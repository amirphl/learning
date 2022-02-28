package main

import "fmt"

var z = 0

func foo() int {
	z++
	return z
}

func wrapper() func() int {
	var x = 0
	return func() int {
		x++
		return x
	}
}

func main() {
	var x = 10
	{
		fmt.Println(x)
		x++
		fmt.Println(x)
		var y = 10
		fmt.Println(y)
	}
	// not works since y is not accessiable here
	// fmt.Println(y)
	fmt.Println("----------------")

	fmt.Println(foo())
	fmt.Println(foo())
	fmt.Println(foo())
	fmt.Println("----------------")

	var anonymousFunc = func() int {
		x++
		return x
	}

	fmt.Println(anonymousFunc())
	fmt.Println(anonymousFunc())
	fmt.Println("----------------")

	var w = wrapper()
	fmt.Println(w())
	fmt.Println(w())
	fmt.Println(w())
	fmt.Println(w())
	fmt.Println("----------------")

	fmt.Println(wrapper()())
	fmt.Println(wrapper()())
	fmt.Println(wrapper()())
	fmt.Println(wrapper()())
}
