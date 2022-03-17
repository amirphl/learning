package main

import "fmt"

// package scope
var a = 2
var b string
var c, d = 4.3, false

func main() {
	// not works:
	// var a b c
	// var a b c string
	// var a string b string
	// var a, b, c
	// var a string, b string, c string
	// var a string, b int, c bool
	// var a, b, c string = 11, "a a a", ""

	// works
	// var a, b, c string // declare-many-at-once
	// var a, b, c string = "11", "a a a", "" // init-many-at-once
	// var a, b, c = 1, 2, 3 // infer-type
	// var a, b, c = 1, "2", 3.0 // infer-mixed-up-types
	// a, b, c := "1", 2.0, 3 // init-shorthand
	// a, b, c := 'a', `b`, "c" // int32- string (backtick) - string
	fmt.Printf("%v, %v, %v, %T, %T, %T", a, b, c, a, b, c)
}
