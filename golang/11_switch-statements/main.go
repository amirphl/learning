package main

import "fmt"

type food struct {
	name string
	rate int
}

func switchOnType(x interface{}) {
	switch x.(type) {
	case int:
		fmt.Println("int")
	case string:
		fmt.Println("string")
	case food:
		fmt.Println("food")
	default:
		fmt.Println("unknown type")
	}
}

func main() {
	i := 10
	switch {
	case i == 11, i == 10:
		fmt.Println("it is 11 or 10")
		fallthrough
	case i%2 == 0:
		fmt.Println("it is even")
		fallthrough
	case i%2 == 1:
		fmt.Println("it is odd")
		fallthrough
	case i%5 == 0:
		fmt.Println("it is multiply of 5")
	case i%10 == 0:
		fmt.Println("it is multiply of 10")
		fallthrough
	case i%1 == 0:
		fmt.Println("it is multiply of 1 :))")
	case i%3 == 0:
		fmt.Println("it is multiply of 3")
	case i%10 == 0:
		fmt.Println("it is multiply of 10 again")
	default:
		fmt.Println("it is the default case")
	}

	fmt.Printf("\n---\n")

	y := food{"pizaa", 8}
	switchOnType(y)
	switchOnType(y.name)
	switchOnType(y.rate)
	switchOnType(nil)
}
