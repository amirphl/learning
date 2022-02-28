package main

import "fmt"

func main() {
	// default value is zero for int, "" for string, false for bool, and 0.0 for float64
	var a int
	var b string
	var c bool
	var d float64
	fmt.Printf("%d, %d, %d, %d, %s, %s, %s, %s, %T, %T, %T, %T, %f, %f, %f, %f, %v, %v, %v, %v\n", a, b, c, d, a, b, c, d, a, b, c, d, a, b, c, d, a, b, c, d)
}
