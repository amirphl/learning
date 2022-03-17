package main

import "fmt"

func main() {
	a := 10
	b := "hello"
	c := false
	d := 7.2
	fmt.Printf("%d, %d, %d, %d, %s, %s, %s, %s, %T, %T, %T, %T, %f, %f, %f, %f, %v, %v, %v, %v\n", a, b, c, d, a, b, c, d, a, b, c, d, a, b, c, d, a, b, c, d)

	var e string             // declaration
	var f string             // declaration
	f = "hello"              // assignment
	var g string = "initial" // initialization
	fmt.Println(e, f, g)
}
