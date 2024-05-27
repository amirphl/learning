package handler

import (
	"encoding/json"
	"log"
	"strconv"

	"example.com/internal/repository"
	"example.com/internal/service"
	"github.com/gofiber/fiber/v3"
)

type handler struct {
	service service.Service
	_       struct{}
}

type Handler interface {
	ReportDelay(c fiber.Ctx) error
	AssignDelayReport(c fiber.Ctx) error
	GetVendorsTotalDelay(c fiber.Ctx) error
	CreateVendor(c fiber.Ctx) error
	CreateOrder(c fiber.Ctx) error
	CreateTrip(c fiber.Ctx) error
	UpdateTripStatus(c fiber.Ctx) error
	CreateAgent(c fiber.Ctx) error
}

func (h *handler) ReportDelay(c fiber.Ctx) error {
	orderID, err := strconv.Atoi(c.Params("id"))
	if err != nil {
		return c.Status(fiber.StatusBadRequest).JSON(fiber.Map{"error": "invalid order ID"})
	}

	deliveryTime, updated, err := h.service.ReportDelay(c.Context(), orderID)
	if err != nil {
		if err == service.OrderHasUnresolvedDelayReport || err == service.DelayReportBeforeDeliveryTimeErr {
			return c.Status(fiber.StatusConflict).JSON(fiber.Map{"error": err.Error()})
		}
		log.Println("report delay:", err)

		return c.Status(fiber.StatusInternalServerError).JSON(fiber.Map{"error": "something went wrong"})
	}

	return c.Status(fiber.StatusCreated).JSON(fiber.Map{"delivery_time": deliveryTime, "updated": updated})
}

func (h *handler) AssignDelayReport(c fiber.Ctx) error {
	agentID, err := strconv.Atoi(c.Params("id"))
	if err != nil {
		return c.Status(fiber.StatusBadRequest).JSON(fiber.Map{"error": "invalid agent ID"})
	}

	delayReportID, err := h.service.AssignDelayReport(c.Context(), agentID)
	if err != nil {
		if err == service.AgentAlreadyAssignedDelayReportErr {
			return c.Status(fiber.StatusConflict).JSON(fiber.Map{"error": "agent already has an assigned delay report"})
		}
		if err == service.DelayReportAlreadyAssignedAgentErr {
			return c.Status(fiber.StatusConflict).JSON(fiber.Map{"error": "order already assigned to an agent"})
		}
		if err == service.DelayReportQueueEmptyErr {
			return c.Status(fiber.StatusNotFound).JSON(fiber.Map{"error": "no delay report in queue"})
		}

		log.Println("assign delay report:", err)

		return c.Status(fiber.StatusInternalServerError).JSON(fiber.Map{"error": "something went wrong"})
	}

	return c.Status(fiber.StatusNoContent).JSON(fiber.Map{"delay_report_id": delayReportID})
}

func (h *handler) GetVendorsTotalDelay(c fiber.Ctx) error {
	delays, err := h.service.GetVendorsTotalDelay(c.Context())
	if err != nil {
		log.Println("vendor delays:", err)

		return c.Status(fiber.StatusInternalServerError).JSON(fiber.Map{"error": "something went wrong"})
	}

	return c.Status(fiber.StatusOK).JSON(delays)
}

func (h *handler) CreateVendor(c fiber.Ctx) error {
	var vendor struct {
		Name string `json:"name" validate:"required"`
	}

	if err := json.Unmarshal(c.Body(), &vendor); err != nil {
		return c.Status(fiber.StatusBadRequest).JSON(fiber.Map{"error": "could not parse request body"})
	}

	if vendor.Name == "" {
		return c.Status(fiber.StatusBadRequest).JSON(fiber.Map{"error": "vendor name is required"})
	}

	vendorID, err := h.service.CreateVendor(c.Context(), vendor.Name)
	if err != nil {
		log.Println("create vendor:", err)

		return c.Status(fiber.StatusInternalServerError).JSON(fiber.Map{"error": "something went wrong"})
	}

	return c.Status(fiber.StatusCreated).JSON(fiber.Map{"vendor_id": vendorID})
}

func (h *handler) CreateOrder(c fiber.Ctx) error {
	vendorID, err := strconv.Atoi(c.Params("id"))
	if err != nil {
		return c.Status(fiber.StatusBadRequest).JSON(fiber.Map{"error": "invalid vendor ID"})
	}

	orderID, err := h.service.CreateOrder(c.Context(), vendorID)
	if err != nil {
		log.Println("create order:", err)

		return c.Status(fiber.StatusInternalServerError).JSON(fiber.Map{"error": "something went wrong"})
	}

	return c.Status(fiber.StatusCreated).JSON(fiber.Map{"order_id": orderID})
}

func (h *handler) CreateTrip(c fiber.Ctx) error {
	orderID, err := strconv.Atoi(c.Params("id"))
	if err != nil {
		return c.Status(fiber.StatusBadRequest).JSON(fiber.Map{"error": "invalid order ID"})
	}

	tripID, err := h.service.CreateTrip(c.Context(), orderID)
	if err != nil {
		log.Println("create trip:", err)

		return c.Status(fiber.StatusInternalServerError).JSON(fiber.Map{"error": "something went wrong"})
	}

	return c.Status(fiber.StatusCreated).JSON(fiber.Map{"trip_id": tripID})
}

func (h *handler) UpdateTripStatus(c fiber.Ctx) error {
	tripID, err := strconv.Atoi(c.Params("id"))
	if err != nil {
		return c.Status(fiber.StatusBadRequest).JSON(fiber.Map{"error": "invalid trip ID"})
	}

	var tripStatus struct {
		Status string `json:"status" validate:"required"`
	}

	if err := json.Unmarshal(c.Body(), &tripStatus); err != nil {
		return c.Status(fiber.StatusBadRequest).JSON(fiber.Map{"error": "could not parse request body"})
	}

	if tripStatus.Status == "" {
		return c.Status(fiber.StatusBadRequest).JSON(fiber.Map{"error": "trip status is required"})
	}

	err = h.service.UpdateTripStatus(c.Context(), tripID, tripStatus.Status)
	if err == repository.InvalidTripStatus {
		return c.Status(fiber.StatusBadRequest).JSON(fiber.Map{"error": "invalid trip status"})
	} else if err != nil {
		log.Println("update trip status:", err)

		return c.Status(fiber.StatusInternalServerError).JSON(fiber.Map{"error": "something went wrong"})
	}

	return c.Status(fiber.StatusNoContent).JSON(fiber.Map{})
}

func (h *handler) CreateAgent(c fiber.Ctx) error {
	agentID, err := h.service.CreateAgent(c.Context())
	if err != nil {
		log.Println("create agent:", err)

		return c.Status(fiber.StatusInternalServerError).JSON(fiber.Map{"error": "something went wrong"})
	}

	return c.Status(fiber.StatusCreated).JSON(fiber.Map{"agent_id": agentID})
}

func New(service service.Service) Handler {
	return &handler{
		service: service,
	}
}
