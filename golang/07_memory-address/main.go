package main

import "fmt"

func main() {
	a := 60
	fmt.Printf("%d , %p\n", a, &a)

	var input string
	fmt.Printf("%s, %p\n", input, &input)
	fmt.Scan(&input)
	fmt.Printf("%s, %p\n", input, &input)
}
