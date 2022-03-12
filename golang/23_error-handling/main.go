package main

import (
	"errors"
	"fmt"
	"log"
	"os"
)

func fileDoesNotExist() {
	_, err := os.Open("./nofile.txt")

	if err != nil {
		fmt.Println(err)
		fmt.Println("-----------------------------------------")
		log.Println(err)
		fmt.Println("-----------------------------------------")
		log.Fatalln(err)
		fmt.Println("-----------------------------------------")
		// log.Panic(err)
		// fmt.Println("-----------------------------------------")
		// panic(err)
	}
}

func writeErrFile() {
	nf, err := os.Open("./log.txt")

	if err != nil {
		panic(err)
	}

	log.SetOutput(nf)
	log.Println("abc.")
}

func sqrt(x float64) (float64, error) {
	if x < 0 {
		return -1, errors.New("ERR: sqrt input < 0")
	}

	return 13, nil
}

func sqrt2(x float64) (float64, error) {
	if x < 0 {
		return -1, errors.New(fmt.Sprintf("ERR: sqrt input %v < 0", x))
	}

	return 13, nil
}

func sqrt3(x float64) (float64, error) {
	if x < 0 {
		return -1, fmt.Errorf("ERR: sqrt input %v < 0", x)
	}

	return 13, nil
}

type CustomErr struct {
	a int
	b string
	c float64
}

func (ce *CustomErr) Error() string {
	return fmt.Sprintf("%p", ce)
}

func createCustomErr() (error, string) {
	err := &CustomErr{1, "salam", 2}
	fmt.Printf("%p\n", err)
	return err, err.Error()
}

func main() {
	// fileDoesNotExist()
	// writeErrFile()
	// fmt.Println(sqrt(3))
	// fmt.Println(sqrt(-1))
	// fmt.Println(sqrt2(-1.4))
	// fmt.Println(sqrt3(-1.44))
	// fmt.Println(createCustomErr())
}
