package main

import "fmt"

func main() {
	if a := "hello"; 1 == 1 {
		fmt.Println(a)
	}

	// a is not defined here
	// fmt.Println(a)
}
