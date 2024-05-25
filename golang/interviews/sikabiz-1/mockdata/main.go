package main

import (
	"encoding/json"
	"fmt"
	"math/rand"
	"os"

	"github.com/brianvoe/gofakeit/v6"
)

type Address struct {
	Street  string `json:"street"`
	City    string `json:"city"`
	State   string `json:"state"`
	ZipCode string `json:"zip_code"`
	Country string `json:"country"`
}

type User struct {
	ID          string    `json:"id"`
	Name        string    `json:"name"`
	Email       string    `json:"email"`
	PhoneNumber string    `json:"phone_number"`
	Addresses   []Address `json:"addresses"`
}

func generateUsers(numUsers int) []User {
	gofakeit.Seed(0)
	users := make([]User, numUsers)

	for i := 0; i < numUsers; i++ {
		numAddresses := rand.Intn(5) + 1 // Each user can have between 1 to 5 addresses
		addresses := make([]Address, numAddresses)

		for j := 0; j < numAddresses; j++ {
			addresses[j] = Address{
				Street:  gofakeit.Street(),
				City:    gofakeit.City(),
				State:   gofakeit.State(),
				ZipCode: gofakeit.Zip(),
				Country: gofakeit.Country(),
			}
		}

		users[i] = User{
			ID:          gofakeit.UUID(),
			Name:        gofakeit.Name(),
			Email:       gofakeit.Email(),
			PhoneNumber: gofakeit.Phone(),
			Addresses:   addresses,
		}
	}

	return users
}

func saveToJSON(data []User, filename string) error {
	file, err := os.Create(filename)
	if err != nil {
		return err
	}
	defer file.Close()

	encoder := json.NewEncoder(file)
	encoder.SetIndent("", "  ")
	err = encoder.Encode(data)
	if err != nil {
		return err
	}

	return nil
}

func main() {
	const numUsers = 999999 // 1 million users
	const filename = "users_data.json"

	fmt.Printf("Generating %d users with multiple addresses...\n", numUsers)
	usersData := generateUsers(numUsers)
	fmt.Printf("Saving data to %s...\n", filename)
	err := saveToJSON(usersData, filename)
	if err != nil {
		fmt.Printf("Error saving data: %v\n", err)
	} else {
		fmt.Println("Data generation and saving completed.")
	}
}
