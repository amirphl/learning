package main

import (
	"bufio"
	"encoding/json"
	"fmt"
	"io/ioutil"
	"log"
	"net/http"
	"os"
	"strings"
	"sync"

	"github.com/dgrijalva/jwt-go"
)

type HttpClient interface {
	Get(url string) (*http.Response, error)
}

type MockClient struct {
	Response *http.Response
	Err      error
}

func (m *MockClient) Get(url string) (*http.Response, error) {
	return m.Response, m.Err
}

func runProducerConsumer() {
	q := make(chan int)

	go func() {
		for i := 1; i <= 100; i++ {
			q <- i
		}
		close(q)
	}()

	var wg sync.WaitGroup
	wg.Add(1)

	go func() {
		defer wg.Done()
		for d := range q {
			fmt.Printf("%d ", d)
		}
		fmt.Println("")
	}()

	wg.Wait()
}

func countWordsInLine(line string, wordFreq map[string]int) {
	for _, word := range strings.Fields(line) {
		word = strings.ToLower(word)
		wordFreq[word]++
	}
}

func readFileAndCountWords(filePath string) {
	file, err := os.Open(filePath)
	if err != nil {
		log.Fatalln(err)
	}
	defer file.Close()

	wordFreq := make(map[string]int)
	scanner := bufio.NewScanner(file)
	for scanner.Scan() {
		countWordsInLine(scanner.Text(), wordFreq)
	}

	if err := scanner.Err(); err != nil {
		log.Fatalln(err)
	}

	b, _ := json.MarshalIndent(wordFreq, "", "  ")
	log.Println("word frequencies:", string(b))
}

func fetchData(client HttpClient, url string) ([]byte, error) {
	resp, err := client.Get(url)
	if err != nil {
		return nil, err
	}
	defer resp.Body.Close()

	return ioutil.ReadAll(resp.Body)
}

func generateToken(secret string, claims jwt.MapClaims) (string, error) {
	token := jwt.NewWithClaims(jwt.SigningMethodHS256, claims)
	tokenString, err := token.SignedString([]byte(secret))
	if err != nil {
		return "", err
	}
	return tokenString, nil
}

func verifyToken(tokenString string, secret string) (*jwt.Token, error) {
	token, err := jwt.Parse(tokenString, func(token *jwt.Token) (interface{}, error) {
		if _, ok := token.Method.(*jwt.SigningMethodHMAC); !ok {
			return nil, fmt.Errorf("unexpected signing method: %v", token.Header["alg"])
		}
		return []byte(secret), nil
	})

	if err != nil {
		return nil, err
	}

	if !token.Valid {
		return nil, fmt.Errorf("invalid token")
	}

	return token, nil
}

func main() {
	runProducerConsumer()
	readFileAndCountWords("./main.go") // read main.go then compute the freq
}
