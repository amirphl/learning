package handlers

import (
	"crypto/md5"
	"encoding/json"
	"fmt"
	"net/http"
	"net/mail"
	"strings"
)

type GravatarResponse struct {
	Ok          bool   `json:"ok"`
	GravatarUrl string `json:"gravatar_url"`
}

type ErrorResponse struct {
	Ok      bool   `json:"ok"`
	Message string `json:"message"`
}

func validMailAddress(address string) (string, bool) {
	addr, err := mail.ParseAddress(address)
	if err != nil {
		return "", false
	}
	return addr.Address, true
}

func HandleGravatarRequest(w http.ResponseWriter, r *http.Request) {
	hasEmail := r.URL.Query().Has("email")
	email := r.URL.Query().Get("email")

	if !hasEmail || email == "" {
		err := ErrorResponse{
			false,
			"No email address provided",
		}
		body, _ := json.Marshal(err)
		w.Header().Set("Content-Type", "application/json")
		w.WriteHeader(http.StatusBadRequest)
		w.Write(body)
		return
	}

	email, valid := validMailAddress(email)

	if !valid {
		err := ErrorResponse{
			false,
			"Invalid email address",
		}
		body, _ := json.Marshal(err)
		w.Header().Set("Content-Type", "application/json")
		w.WriteHeader(http.StatusBadRequest)
		w.Write(body)
		return
	}

	email = strings.ToLower(strings.Trim(email, " "))
	hash := fmt.Sprintf("%x", md5.Sum([]byte(email)))
	gURL := "https://www.gravatar.com/avatar/"
	w.Header().Set("Content-Type", "application/json")
	w.WriteHeader(http.StatusOK)
	payload := GravatarResponse{
		true,
		gURL + hash,
	}
	body, _ := json.Marshal(payload)
	w.Write(body)
}
