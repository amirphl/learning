package main

import "fmt"

func makeZero(x int) {
	fmt.Printf("inside makeZero: %d, %p\n", x, &x) // &&x
	x = 0
}

func sudoMakeZero(x *int) {
	fmt.Printf("inside sudoMakeZero: %d, %p\n", *x, x)
	*x = 0
}

func main() {
	x := 60
	fmt.Printf("%d %p\n", x, &x)
	makeZero(x)
	fmt.Printf("%d %p\n", x, &x)
	fmt.Println("----")

	sudoMakeZero(&x)
	fmt.Printf("%d %p\n", x, &x)
	fmt.Println("----")

	// var y int* = &x
	var y *int = &x
	*y = 111
	fmt.Printf("%d %p %p %p --- %d, %p\n", *y, y, &*y, &y, x, &x)
	// fmt.Println(*x) // x is not a pointer
	// fmt.Println(&y == &x) // TODO
	fmt.Printf("%v %v %v %p %p\n", *y == x, y == &x, &*y == &x, &y, &x) // can't compare &y and &x (**int vs *int)
	fmt.Println("----")
}
