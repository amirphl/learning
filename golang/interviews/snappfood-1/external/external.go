package external

import (
	"context"
	"encoding/json"
	"fmt"
	"net/http"
	"time"
)

const deliveryTimeRoute = "https://run.mocky.io/v3/f1bb38ff-6469-42c6-918d-1ab21844d268"

type deliveryTimePayload struct {
	TimeMins int `json:"time"`
}

func FetchNewDeliveryTime(ctx context.Context) (time.Time, error) {
	req, err := http.NewRequestWithContext(ctx, http.MethodGet, deliveryTimeRoute, nil)
	if err != nil {
		return time.Time{}, fmt.Errorf("could not create request: %v", err)
	}

	client := &http.Client{}
	resp, err := client.Do(req)
	if err != nil {
		return time.Time{}, fmt.Errorf("could not fetch new delivery time: %v", err)
	}
	defer resp.Body.Close()

	var payload deliveryTimePayload
	err = json.NewDecoder(resp.Body).Decode(&payload)
	if err != nil {
		return time.Time{}, fmt.Errorf("could not decode response: %v", err)
	}

	return time.Now().UTC().Add(time.Duration(payload.TimeMins) * time.Minute), nil
}
