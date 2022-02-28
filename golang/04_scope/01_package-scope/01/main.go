package main

import "fmt"

// package scope
var x = "amirphl"

func main() {
	fmt.Println(x)
    // block scope
	var y = "otherphl"
	fmt.Println(y)
	// not works: z is not defined yet, order matters!
	// fmt.Println(z)
	// var z = "3"
	fun()
}

func fun() {
	fmt.Println(x)
	// not works: y is not accessible here
	// fmt.Println(y)
	fmt.Println(u)
}

// package scope
var u = "I am declared in the end of the scope while I'm still accessible."
