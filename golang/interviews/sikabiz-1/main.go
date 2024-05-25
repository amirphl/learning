package main

import (
	"context"
	"encoding/json"
	"fmt"
	"io/ioutil"
	"log"
	"net/http"
	"strings"
	"sync"
	"time"

	"gorm.io/driver/postgres"
	"gorm.io/gorm"
)

const filePath = "./users_data.json"
const concurrency = 10

// TODO read from env var
const dbuser = "postgres"
const dbpass = "postgres"
const dbname = "interview"
const dbport = 5555

type Server struct {
	db *gorm.DB
}

type User struct {
	gorm.Model  `json:"-"`
	UUID        string `json:"id"`
	Name        string
	Email       string
	PhoneNumber string `json:"phone_number"`
	Addresses   []Address
}

type Address struct {
	gorm.Model
	Street  string
	City    string
	State   string
	ZipCode string
	Country string
	UserID  int64
}

func readUsers() []User {
	f, err := ioutil.ReadFile(filePath)
	if err != nil {
		log.Fatal(err)
	}

	users := make([]User, 0, 0) // TODO What is the proper value
	err = json.Unmarshal(f, &users)
	if err != nil {
		log.Fatal("Can't read the users json file: " + err.Error())
	}

	return users
}

func populateDB(s Server, users []User) {
	log.Println("populating the db")
	var wg sync.WaitGroup
	numRows := len(users)
	chunk := numRows / concurrency

	for i := 0; i < concurrency; i++ {
		wg.Add(1)
		view := users[i*chunk : (i+1)*chunk]

		go func(v []User) {
			for _, user := range v {
				s.db.Create(&user)
			}

			wg.Done()
		}(view)
	}

	wg.Wait()
}

func newServer() Server {
	dbURL := fmt.Sprintf("postgres://%s:%s@127.0.0.1:%d/%s", dbuser, dbpass, dbport, dbname)

	db, err := gorm.Open(postgres.Open(dbURL), &gorm.Config{})
	// defer db.Close() // TODO

	if err != nil {
		log.Fatalln(err)
	}

	db.AutoMigrate(&Address{})
	db.AutoMigrate(&User{})

	return Server{db: db}
}

func (s *Server) handleUser(w http.ResponseWriter, r *http.Request) {
	ctx := context.Background()
	ctx, _ = context.WithTimeout(ctx, 1*time.Second)

	// TODO ensure user_id is int
	userId := strings.TrimPrefix(r.URL.Path, "/users/")
	var user User

	query := s.db.WithContext(ctx).Model(&User{}).Preload("Addresses").Where("id = ?", userId)

	err := query.Find(&user).Error
	if err != nil {
		log.Println("[ERROR]", err)
		w.WriteHeader(http.StatusInternalServerError)
	}

	b, _ := json.Marshal(user)
	w.Write(b)
}

func serve(s *Server) {
	log.Println("serving http ...")
	http.HandleFunc("/users/", s.handleUser)
	log.Fatal(http.ListenAndServe(":3000", nil))
}

func main() {
	s := newServer()
	users := readUsers()
	populateDB(s, users)
	serve(&s)
}
