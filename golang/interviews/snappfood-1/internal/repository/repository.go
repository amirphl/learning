package repository

import (
	"context"
	"database/sql"
	"fmt"
	"strconv"
	"time"

	"github.com/jackc/pgx/v5"
	"github.com/redis/go-redis/v9"
)

const delayReportCacheKey = "delay_reports"

type VendorDelay struct {
	Name              string
	TotalDelayMinutes float64
	_                 struct{}
}

type repository struct {
	db  *pgx.Conn
	rdb *redis.Client // TODO try 3 times
	_   struct{}
}

type Repository interface {
	CreateVendor(ctx context.Context, name string) (int, error)
	CreateOrder(ctx context.Context, vendorID int, orderTime, deliveryTime time.Time) (int, int, error)
	CreateOrderEstimatedDelivery(ctx context.Context, orderID int, time_ time.Time) (int, error)
	GetOrderLastEstimatedDelivery(ctx context.Context, orderID int) (int, time.Time, error)
	GetOrderLastEstimatedDeliveryTimeAndTripStatus(ctx context.Context, orderID int) (time.Time, *tripStatus, error)
	HasOrderUnresolvedDelayReport(ctx context.Context, orderID int) (bool, error)
	CreateTrip(ctx context.Context, orderID int, status tripStatus) (int, error)
	UpdateTripStatus(ctx context.Context, tripID int, status tripStatus) error
	CreateDelayReport(ctx context.Context, orderID int, reportTime time.Time, reason DelayReportReason, resolved bool) (int, error)
	UpdateDelayReportAgent(ctx context.Context, delayReportID int, agentID int) error
	ResolveDelayReport(ctx context.Context, delayReportID int) error
	VendorsTotalDelay(ctx context.Context, from time.Time, to time.Time) ([]VendorDelay, error)
	IsAnyDelayReportAssginedToAgent(ctx context.Context, agentID int, resolved bool) (bool, error)
	IsAnyAgentAssignedToDelayReport(ctx context.Context, delayReportID int) (bool, error)
	CreateAgent(ctx context.Context) (int, error)
	PushDelayReport(ctx context.Context, delayReportID int) error
	PopDelayReport(ctx context.Context) (int, bool, error)
}

type tripStatus string

const (
	Assigned  tripStatus = "assigned"
	AtVendor  tripStatus = "at_vendor"
	Picked    tripStatus = "picked"
	Delivered tripStatus = "delivered"
)

type DelayReportReason uint8

const (
	TripNotAssigned DelayReportReason = iota
	NotDeliveredYet
	DeliveredNotReceived
)

var InvalidTripStatus = fmt.Errorf("invalid trip status")

func NewTripStatus(status string) (tripStatus, error) {
	switch status {
	case string(Assigned):
		return Assigned, nil
	case string(AtVendor):
		return AtVendor, nil
	case string(Picked):
		return Picked, nil
	case string(Delivered):
		return Delivered, nil
	}

	return "", InvalidTripStatus
}

func (r *repository) CreateVendor(ctx context.Context, name string) (int, error) {
	var vendorID int
	query := `INSERT INTO Vendors (name) VALUES ($1) RETURNING id`
	err := r.db.QueryRow(ctx, query, name).Scan(&vendorID)
	if err != nil {
		return 0, fmt.Errorf("could not create vendor %s: %v", name, err)
	}

	return vendorID, nil
}

// TODO tx, return 404
func (r *repository) CreateOrder(ctx context.Context, vendorID int, orderTime, deliveryTime time.Time) (int, int, error) {
	var orderID int
	query := `INSERT INTO Orders (vendor_id, time) VALUES ($1, $2) RETURNING id`
	err := r.db.QueryRow(ctx, query, vendorID, orderTime).Scan(&orderID)
	if err != nil {
		return 0, 0, fmt.Errorf("could not create order for vendor %d: %v", vendorID, err)
	}

	var estimatedDeliveryID int
	query = `INSERT INTO EstimatedDeliveries (order_id, time) VALUES ($1, $2) RETURNING id`
	err = r.db.QueryRow(ctx, query, orderID, deliveryTime).Scan(&estimatedDeliveryID)
	if err != nil {
		return orderID, 0, fmt.Errorf("could not create estimated delivery for order %d: %v", orderID, err)
	}

	return orderID, estimatedDeliveryID, nil
}

// TODO return 404
func (r *repository) CreateOrderEstimatedDelivery(ctx context.Context, orderID int, time_ time.Time) (int, error) {
	var estimatedDeliveryID int
	query := `INSERT INTO EstimatedDeliveries (order_id, time) VALUES ($1, $2) RETURNING id`
	err := r.db.QueryRow(ctx, query, orderID, time_).Scan(&estimatedDeliveryID)
	if err != nil {
		return 0, fmt.Errorf("could not create estimated delivery for order %d: %v", orderID, err)
	}

	return estimatedDeliveryID, nil
}

// TODO return 404
func (r *repository) GetOrderLastEstimatedDelivery(ctx context.Context, orderID int) (int, time.Time, error) {
	var (
		id           sql.NullInt32
		deliveryTime sql.NullTime
	)
	query := `SELECT id, time FROM EstimatedDeliveries WHERE order_id = $1 ORDER BY id DESC LIMIT 1`
	err := r.db.QueryRow(ctx, query, orderID).Scan(&id, &deliveryTime)
	if err != nil {
		return 0, time.Time{}, fmt.Errorf("could not find order %d last estimated delivery: %v", orderID, err)
	}
	if !id.Valid || !deliveryTime.Valid {
		return 0, time.Time{}, fmt.Errorf("order %d last estimated delivery not found", orderID)
	}

	return int(id.Int32), deliveryTime.Time, nil
}

// TODO return 404
func (r *repository) GetOrderLastEstimatedDeliveryTimeAndTripStatus(ctx context.Context, orderID int) (time.Time, *tripStatus, error) {
	var deliveryTime sql.NullTime
	var statusStr sql.NullString

	// TODO only join E and T
	query := `SELECT E.time, T.status FROM Orders O
                LEFT JOIN Trips T ON T.order_id = O.id
                LEFT JOIN EstimatedDeliveries E ON E.order_id = O.id
                WHERE O.id = $1 ORDER BY E.id DESC LIMIT 1`
	err := r.db.QueryRow(ctx, query, orderID).Scan(&deliveryTime, &statusStr)
	if err != nil {
		return time.Time{}, nil, fmt.Errorf("could not fetch order %d trip status and estimated delivery time: %v", orderID, err)
	}
	if !deliveryTime.Valid {
		return time.Time{}, nil, fmt.Errorf("estimated delivery time is null for order %d: %v", orderID, err)
	}
	if !statusStr.Valid {
		return deliveryTime.Time, nil, nil
	}

	status, err := NewTripStatus(statusStr.String)
	if err != nil {
		return time.Time{}, nil, err
	}

	return deliveryTime.Time, &status, nil
}

// TODO return 404
func (r *repository) HasOrderUnresolvedDelayReport(ctx context.Context, orderID int) (bool, error) {
	var reportCount int
	query := `SELECT COUNT(*) FROM DelayReports WHERE order_id = $1 AND resolved = FALSE`
	err := r.db.QueryRow(ctx, query, orderID).Scan(&reportCount)
	if err != nil {
		return false, fmt.Errorf("could not find unresolved delay reports associated with order %d: %v", orderID, err)
	}

	return reportCount > 0, nil
}

// TODO return conflict, 404
func (r *repository) CreateTrip(ctx context.Context, orderID int, status tripStatus) (int, error) {
	var tripID int
	query := `INSERT INTO Trips (order_id, status, deliverd_time) VALUES ($1, $2, NULL) RETURNING id`
	err := r.db.QueryRow(ctx, query, orderID, status).Scan(&tripID)
	if err != nil {
		return 0, fmt.Errorf("could not create trip for order %d: %v", orderID, err)
	}

	return tripID, nil
}

// TODO return 404
func (r *repository) UpdateTripStatus(ctx context.Context, tripID int, status tripStatus) error {
	var query string
	var err error
	if status == Delivered {
		query = `UPDATE Trips SET deliverd_time = $1,   status = $2 WHERE id = $3`
		_, err = r.db.Exec(ctx, query, time.Now().UTC(), status, tripID)
	} else {
		query = `UPDATE Trips SET deliverd_time = NULL, status = $1 WHERE id = $2`
		_, err = r.db.Exec(ctx, query, status, tripID)
	}
	if err != nil {
		return fmt.Errorf("could not update trip %d status: %v", tripID, err)
	}

	return nil
}

// TODO tx, return 404
func (r *repository) CreateDelayReport(ctx context.Context, orderID int, reportTime time.Time, reason DelayReportReason, resolved bool) (int, error) {
	var reportID int

	estimatedDeliveryID, _, err := r.GetOrderLastEstimatedDelivery(ctx, orderID)
	if err != nil {
		return 0, err
	}

	query := `INSERT INTO DelayReports (order_id, report_time, estimated_delivery, reason, resolved, agent_id) VALUES ($1, $2, $3, $4, $5, NULL) RETURNING id`
	err = r.db.QueryRow(ctx, query, orderID, reportTime, estimatedDeliveryID, reason, resolved).Scan(&reportID)
	if err != nil {
		return 0, fmt.Errorf("could not create delay report for order %d: %v", orderID, err)
	}

	return reportID, nil
}

// TODO return 404
func (r *repository) UpdateDelayReportAgent(ctx context.Context, delayReportID int, agentID int) error {
	_, err := r.db.Exec(ctx, `UPDATE DelayReports SET agent_id = $1 WHERE id = $2`, agentID, delayReportID)
	if err != nil {
		return fmt.Errorf("could not update delay report %d agent set to %d: %v", delayReportID, agentID, err)
	}

	return nil
}

// TODO use in API
func (r *repository) ResolveDelayReport(ctx context.Context, delayReportID int) error {
	_, err := r.db.Exec(ctx, `UPDATE DelayReports SET resolved = TRUE WHERE id = $2`, delayReportID)
	if err != nil {
		return fmt.Errorf("could not resolve delay report %d: %v", delayReportID, err)
	}

	return nil
}

func (r *repository) VendorsTotalDelay(ctx context.Context, from time.Time, to time.Time) ([]VendorDelay, error) {
	var totalDelays []VendorDelay
	fmt.Println(from, to)
	query := `SELECT V.name AS name, SUM(EXTRACT(EPOCH FROM (T.deliverd_time - E.time)) / 60) AS TotalDelayMinutes
                  FROM Vendors V
                  LEFT JOIN Orders O ON O.vendor_id = V.id
                  LEFT JOIN Trips T ON T.order_id = O.id
                  LEFT JOIN (
                    SELECT ED.order_id, MIN(ED.time) AS time
                    FROM EstimatedDeliveries ED
                    GROUP BY ED.order_id
                  ) AS E ON E.order_id = O.id
                  WHERE T.id IS NOT NULL AND T.status = 'delivered' AND O.time >= $1 AND O.time <= $2
                  GROUP BY V.id, V.name
                  ORDER BY TotalDelayMinutes`
	rows, err := r.db.Query(ctx, query, from, to)
	if err != nil {
		return nil, fmt.Errorf("could not calculate vendors total delay: %v", err)
	}
	defer rows.Close()

	for rows.Next() {
		var vendorDelay VendorDelay
		err := rows.Scan(&vendorDelay.Name, &vendorDelay.TotalDelayMinutes)
		if err != nil {
			return nil, fmt.Errorf("could not calculate vendors total delay: %v", err)
		}
		totalDelays = append(totalDelays, vendorDelay)
	}

	return totalDelays, nil
}

// TODO return 404
func (r *repository) IsAnyDelayReportAssginedToAgent(ctx context.Context, agentID int, resolved bool) (bool, error) {
	var reportCount int
	err := r.db.QueryRow(ctx, `SELECT COUNT(*) FROM DelayReports WHERE agent_id = $1 AND resolved = $2`, agentID, resolved).Scan(&reportCount)
	if err != nil {
		return false, fmt.Errorf("could not find delay reports assigned to agent %d: %v", agentID, err)
	}

	return reportCount > 0, nil
}

// TODO return 404
func (r *repository) IsAnyAgentAssignedToDelayReport(ctx context.Context, delayReportID int) (bool, error) {
	var agentCount int
	// TODO limit resolved = false?
	err := r.db.QueryRow(context.Background(), `SELECT COUNT(*) FROM DelayReports WHERE id = $1 AND agent_id IS NOT NULL`, delayReportID).Scan(&agentCount)
	if err != nil {
		return false, fmt.Errorf("could not find any agent assigned to delay report %d: %v", delayReportID, err)
	}

	return agentCount > 0, nil
}

func (r *repository) CreateAgent(ctx context.Context) (int, error) {
	var agentID int
	query := `INSERT INTO Agents DEFAULT VALUES RETURNING id`
	err := r.db.QueryRow(ctx, query).Scan(&agentID)
	if err != nil {
		return 0, fmt.Errorf("could not create agent: %v", err)
	}

	return agentID, nil
}

func (r *repository) PushDelayReport(ctx context.Context, delayReportID int) error {
	err := r.rdb.LPush(ctx, delayReportCacheKey, delayReportID).Err()
	if err != nil {
		return fmt.Errorf("could not push delay report %d to queue: %v", delayReportID, err)
	}

	return nil
}

func (r *repository) PopDelayReport(ctx context.Context) (int, bool, error) {
	delayReportIDStr, err := r.rdb.RPop(ctx, delayReportCacheKey).Result()
	if err == redis.Nil {
		return 0, false, nil
	} else if err != nil {
		return 0, false, fmt.Errorf("could not pop delay report from queue: %v", err)
	}

	id, err := strconv.Atoi(delayReportIDStr)
	if err != nil {
		return 0, false, fmt.Errorf("could not parse delay report id %s", delayReportIDStr)
	}

	return int(id), true, nil
}

func New(db *pgx.Conn, rdb *redis.Client) Repository {
	return &repository{
		db:  db,
		rdb: rdb,
	}
}
