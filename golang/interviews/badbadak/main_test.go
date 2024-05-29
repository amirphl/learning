package main

import (
	"bytes"
	"io/ioutil"
	"net/http"
	"testing"
	"time"

	"github.com/dgrijalva/jwt-go"
)

func TestFetchData(t *testing.T) {
	sampleBody := "Hello, World!"
	sampleResponse := &http.Response{
		StatusCode: 200,
		Body:       ioutil.NopCloser(bytes.NewBufferString(sampleBody)),
	}

	mockClient := &MockClient{
		Response: sampleResponse,
		Err:      nil,
	}

	data, err := fetchData(mockClient, "http://mockurl.com")
	if err != nil {
		t.Fatalf("Expected no error, got %v", err)
	}

	if string(data) != sampleBody {
		t.Fatalf("Expected %s, got %s", sampleBody, string(data))
	}
}

func TestGenerateToken(t *testing.T) {
	secret := "mysecret"
	claims := jwt.MapClaims{
		"username": "amirphl",
		"exp":      time.Now().Add(time.Hour * 1).Unix(), // Token expires in 1 hour
	}

	tokenString, err := generateToken(secret, claims)
	if err != nil {
		t.Fatalf("Expected no error, got %v", err)
	}

	if tokenString == "" {
		t.Fatalf("Expected a token string, got empty string")
	}
}

func TestVerifyToken(t *testing.T) {
	secret := "mysecret"
	claims := jwt.MapClaims{
		"username": "amirphl",
		"exp":      time.Now().Add(time.Hour * 1).Unix(), // Token expires in 1 hour
	}

	tokenString, err := generateToken(secret, claims)
	if err != nil {
		t.Fatalf("Expected no error, got %v", err)
	}

	token, err := verifyToken(tokenString, secret)
	if err != nil {
		t.Fatalf("Expected no error, got %v", err)
	}

	if !token.Valid {
		t.Fatalf("Expected token to be valid")
	}

	if tokenClaims, ok := token.Claims.(jwt.MapClaims); ok && token.Valid {
		if tokenClaims["username"] != "amirphl" {
			t.Fatalf("Expected username to be 'amirphl', got %v", tokenClaims["username"])
		}
	} else {
		t.Fatalf("Expected valid token claims, got invalid")
	}
}
