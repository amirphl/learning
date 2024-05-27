package service

import (
	"context"
	"errors"
	"time"

	"example.com/external"
	"example.com/internal/repository"
)

type service struct {
	repo repository.Repository
	_    struct{}
}

var DelayReportBeforeDeliveryTimeErr = errors.New("cannot report delay before delivery time")
var AgentAlreadyAssignedDelayReportErr = errors.New("agent has already assigned to an unresolved delay report")
var DelayReportAlreadyAssignedAgentErr = errors.New("delay report has already assigned to an agent")
var DelayReportQueueEmptyErr = errors.New("cannot pop from empty delay report queue")
var OrderHasUnresolvedDelayReport = errors.New("order has unresolved delay report")

type Service interface {
	ReportDelay(ctx context.Context, orderID int) (time.Time, bool, error)
	AssignDelayReport(ctx context.Context, agentID int) (int, error)
	GetVendorsTotalDelay(ctx context.Context) ([]repository.VendorDelay, error)
	CreateVendor(ctx context.Context, name string) (int, error)
	CreateOrder(ctx context.Context, vendorID int) (int, error)
	CreateTrip(ctx context.Context, orderID int) (int, error)
	UpdateTripStatus(ctx context.Context, tripID int, statusStr string) error
	CreateAgent(ctx context.Context) (int, error)
}

func (s *service) createDelayReport(ctx context.Context, orderID int, reason repository.DelayReportReason, resolved bool) (int, error) {
	reportTime := time.Now().UTC()
	reportID, err := s.repo.CreateDelayReport(ctx, orderID, reportTime, reason, resolved)
	if err != nil {
		return 0, err
	}

	return reportID, nil
}

// TODO tx
func (s *service) ReportDelay(ctx context.Context, orderID int) (time.Time, bool, error) {
	hasUnresolvedDelayReport, err := s.repo.HasOrderUnresolvedDelayReport(ctx, orderID)
	if err != nil {
		return time.Time{}, false, err
	}

	if hasUnresolvedDelayReport {
		return time.Time{}, false, OrderHasUnresolvedDelayReport
	}

	deliveryTime, tripStatus, err := s.repo.GetOrderLastEstimatedDeliveryTimeAndTripStatus(ctx, orderID)
	if err != nil {
		return time.Time{}, false, err
	}

	if time.Now().UTC().Before(deliveryTime) {
		return time.Time{}, false, DelayReportBeforeDeliveryTimeErr
	}

	var resolved bool
	var reason repository.DelayReportReason
	if tripStatus == nil {
		reason = repository.TripNotAssigned
		resolved = false
	} else {
		if *tripStatus == repository.Delivered {
			reason = repository.DeliveredNotReceived
			resolved = false
		} else {
			reason = repository.NotDeliveredYet
			resolved = true
		}
	}

	reportID, err := s.createDelayReport(ctx, orderID, reason, resolved)
	if err != nil {
		return time.Time{}, false, err
	}

	if tripStatus != nil && *tripStatus != repository.Delivered {
		newDeliveryTime, err := external.FetchNewDeliveryTime(ctx)
		if err != nil {
			return time.Time{}, false, err
		}

		_, err = s.repo.CreateOrderEstimatedDelivery(ctx, orderID, newDeliveryTime)
		if err != nil {
			return time.Time{}, false, err
		}

		updated := true
		return newDeliveryTime, updated, nil
	}

	err = s.repo.PushDelayReport(ctx, reportID)
	if err != nil {
		return time.Time{}, false, err
	}

	updated := false
	return deliveryTime, updated, nil
}

// TODO what if pop then fail to assign
// TODO tx
func (s *service) AssignDelayReport(ctx context.Context, agentID int) (int, error) {
	resolved := false
	isAgentAssigned, err := s.repo.IsAnyDelayReportAssginedToAgent(ctx, agentID, resolved)
	if err != nil {
		return 0, err
	}
	if isAgentAssigned {
		return 0, AgentAlreadyAssignedDelayReportErr
	}

	delayReportID, ok, err := s.repo.PopDelayReport(ctx)
	if err != nil {
		return 0, err
	}
	if !ok {
		return 0, DelayReportQueueEmptyErr
	}

	isReportAssigned, err := s.repo.IsAnyAgentAssignedToDelayReport(ctx, delayReportID)
	if err != nil {
		return 0, err
	}
	if isReportAssigned {
		return 0, DelayReportAlreadyAssignedAgentErr
	}

	err = s.repo.UpdateDelayReportAgent(ctx, delayReportID, agentID)
	if err != nil {
		return 0, err
	}

	return delayReportID, nil
}

func (s *service) GetVendorsTotalDelay(ctx context.Context) ([]repository.VendorDelay, error) {
	to := time.Now().UTC()
	from := to.Add(-time.Hour * (7 * 24)) // last week // TODO last week from the begining of the last week?
	vendorDelays, err := s.repo.VendorsTotalDelay(ctx, from, to)
	if err != nil {
		return nil, err
	}

	return vendorDelays, nil
}

func (s *service) CreateVendor(ctx context.Context, name string) (int, error) {
	return s.repo.CreateVendor(ctx, name)
}

func (s *service) CreateOrder(ctx context.Context, vendorID int) (int, error) {
	orderTime := time.Now().UTC()
	deliveryTime, err := external.FetchNewDeliveryTime(ctx)
	if err != nil {
		return 0, err
	}

	orderID, _, err := s.repo.CreateOrder(ctx, vendorID, orderTime, deliveryTime)
	if err != nil {
		return 0, err
	}

	return orderID, err
}

func (s *service) CreateTrip(ctx context.Context, orderID int) (int, error) {
	return s.repo.CreateTrip(ctx, orderID, repository.Assigned)
}

func (s *service) UpdateTripStatus(ctx context.Context, tripID int, statusStr string) error {
	status, err := repository.NewTripStatus(statusStr)
	if err != nil {
		return err
	}

	return s.repo.UpdateTripStatus(ctx, tripID, status)
}

func (s *service) CreateAgent(ctx context.Context) (int, error) {
	return s.repo.CreateAgent(ctx)
}

func New(r repository.Repository) Service {
	return &service{
		repo: r,
	}
}
