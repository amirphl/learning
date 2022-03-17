package main

import "fmt"

import "rsc.io/quote"

func main() {
	fmt.Println(quote.Go())
	fmt.Printf("%d, %b, %x, %#x, %#X\n", 50, 50, 50, 50, 50)

	for i := 1000; i < 1100; i++ {
		fmt.Printf("%d, %b, %x, %#x, %#X, %q\n", i, i, i, i, i, i)
	}
}
