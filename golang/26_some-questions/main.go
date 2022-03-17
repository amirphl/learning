package main

import "fmt"

// Why does this code prints two sequential `In goroutine`s?
// I found it interesting.
func q1() {
	c := make(chan int)

	go func() {
		for i := 0; i < 10; i++ {
			fmt.Println("In goroutine:", i)
			c <- i
		}
		close(c)
	}()

	for n := range c {
		fmt.Println("In main: ", n)
	}
}

func main() {
	q1()
}
