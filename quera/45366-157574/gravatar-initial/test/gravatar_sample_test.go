package main

import (
	"github.com/stretchr/testify/assert"
	"github.com/stretchr/testify/require"
	"gravatar/handlers"
	"net/http"
	"net/http/httptest"
	"testing"
)

func TestSampleGravatarWithoutEmail(t *testing.T) {
	req, _ := http.NewRequest("GET", "/avatar", nil)
	rr := httptest.NewRecorder()
	handler := http.HandlerFunc(handlers.HandleGravatarRequest)
	handler.ServeHTTP(rr, req)
	assert.Equal(t, http.StatusBadRequest, rr.Code)
	assert.Equal(t, "application/json", rr.Header().Get("content-type"))
	require.JSONEq(t, `{"ok": false, "message": "No email address provided"}`, rr.Body.String())
}

func TestSampleGravatarWithEmptyEmail(t *testing.T) {
	req, _ := http.NewRequest("GET", "/avatar?email=", nil)
	rr := httptest.NewRecorder()
	handler := http.HandlerFunc(handlers.HandleGravatarRequest)
	handler.ServeHTTP(rr, req)
	assert.Equal(t, http.StatusBadRequest, rr.Code)
	assert.Equal(t, "application/json", rr.Header().Get("content-type"))
	require.JSONEq(t, `{"ok": false, "message": "No email address provided"}`, rr.Body.String())
}

func TestSampleGravatarWithInvalidEmail(t *testing.T) {
	req, _ := http.NewRequest("GET", "/avatar?email=abcd", nil)
	rr := httptest.NewRecorder()
	handler := http.HandlerFunc(handlers.HandleGravatarRequest)
	handler.ServeHTTP(rr, req)
	assert.Equal(t, http.StatusBadRequest, rr.Code)
	assert.Equal(t, "application/json", rr.Header().Get("content-type"))
	require.JSONEq(t, `{"ok": false, "message": "Invalid email address"}`, rr.Body.String())
}

func TestSampleGravatarWithValidEmail1(t *testing.T) {
	req, _ := http.NewRequest("GET", "/avatar?email=abcd1234@gmail.com", nil)
	rr := httptest.NewRecorder()
	handler := http.HandlerFunc(handlers.HandleGravatarRequest)
	handler.ServeHTTP(rr, req)
	assert.Equal(t, http.StatusOK, rr.Code)
	assert.Equal(t, "application/json", rr.Header().Get("content-type"))
	require.JSONEq(t, `{"ok": true, "gravatar_url": "https://www.gravatar.com/avatar/92e7a64348303b0e5f8b06c563252620"}`, rr.Body.String())

	req, _ = http.NewRequest("GET", "/avatar?email=nima.heydari79@gmail.com", nil)
	rr = httptest.NewRecorder()
	handler.ServeHTTP(rr, req)
	assert.Equal(t, http.StatusOK, rr.Code)
	assert.Equal(t, "application/json", rr.Header().Get("content-type"))
	require.JSONEq(t, `{"ok": true, "gravatar_url": "https://www.gravatar.com/avatar/2a56dbcf5465065566e1b55fb6cfd619"}`, rr.Body.String())

	req, _ = http.NewRequest("GET", "/avatar?email=ali9ali@yahoo.com", nil)
	rr = httptest.NewRecorder()
	handler.ServeHTTP(rr, req)
	assert.Equal(t, http.StatusOK, rr.Code)
	assert.Equal(t, "application/json", rr.Header().Get("content-type"))
	require.JSONEq(t, `{"ok": true, "gravatar_url": "https://www.gravatar.com/avatar/72e6fd5b1ef9241e7b30e59742d7e242"}`, rr.Body.String())
}
