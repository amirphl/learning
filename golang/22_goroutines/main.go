package main

import "fmt"

func foo1() {
	for i := 0; i < 10; i++ {
		fmt.Printf("foo_1	%v\n", i)
	}
}

func bar1() {
	for i := 0; i < 10; i++ {
		fmt.Printf("bar_1	%v\n", i)
	}
}

// Nothing will be printed!
func noGo() {
	foo1()
	bar1()
}

func noWait() {
	go foo1()
	go bar1()
}

func main() {
	// noGo()
	noWait()
}
