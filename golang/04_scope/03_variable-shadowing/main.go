package main

import "fmt"

func main() {
	var foo = foo(2)
	fmt.Println(foo)
	// not works: because `foo` is no longer a function in this scope, it's an int variable so it's not callable.
	// var foo2 = foo(3)
}

func foo(x int) int {
	return x + 2
}
