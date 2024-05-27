package main

import (
	"context"
	"fmt"
	"log"
	"os"
	"strconv"

	"example.com/internal/handler"
	"example.com/internal/repository"
	"example.com/internal/service"
	"github.com/gofiber/fiber/v3"
	"github.com/jackc/pgx/v5"
	"github.com/redis/go-redis/v9"
)

type Server struct {
	rdb *redis.Client
	db  *pgx.Conn
	_   struct{}
}

func NewServer() *Server {
	redisDB, err := strconv.Atoi(os.Getenv("REDIS_DB"))
	if err != nil {
		fmt.Fprintf(os.Stderr, "Invalid redis db: %v\n", err)
		os.Exit(1)
	}

	rdb := redis.NewClient(&redis.Options{
		Addr:     os.Getenv("REDIS_HOST"),
		Password: os.Getenv("REDIS_PASS"),
		DB:       redisDB,
	})

	// TODO ctx deadline
	_, err = rdb.Ping(context.Background()).Result()
	if err != nil {
		fmt.Fprintf(os.Stderr, "Unable to connect to cache: %v\n", err)
		os.Exit(1)
	}
	log.Println("Cache connected.")

	// TODO ctx deadline
	conn, err := pgx.Connect(context.Background(), os.Getenv("DATABASE_URL"))
	if err != nil {
		fmt.Fprintf(os.Stderr, "Unable to connect to database: %v\n", err)
		os.Exit(1)
	}
	log.Println("Database connected.")

	return &Server{
		rdb: rdb,
		db:  conn,
	}
}

func main() {
	server := NewServer()
	defer server.db.Close(context.Background())
	defer server.rdb.Close()

	repo := repository.New(server.db, server.rdb)
	serv := service.New(repo)
	h := handler.New(serv)
	app := fiber.New()

	app.Get("/vendor/delay-reports/", h.GetVendorsTotalDelay)
	app.Post("/vendor/", h.CreateVendor)
	app.Post("/vendor/:id/order/", h.CreateOrder)
	app.Post("/order/:id/trip/", h.CreateTrip)
	app.Post("/order/:id/report-delay", h.ReportDelay)
	app.Put("/trip/:id", h.UpdateTripStatus)
	app.Post("/agent/", h.CreateAgent)
	app.Put("/agent/:id/assign-delay-report", h.AssignDelayReport)

	log.Println("Serving ...")
	app.Listen(":8080")
}
