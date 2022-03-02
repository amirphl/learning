package main

import "fmt"

func multipleArgsMultipleReturn(a, b string) (string, string) { // parames are received
	return fmt.Sprint(a, b), fmt.Sprint(b, a)
}

func multipleArgsMultipleReturn2(a, b string) (c, d string) {
	c = fmt.Sprint(a, b)
	d = fmt.Sprint(b, a)
	return
}

func variadicAverage(nums ...float64) (float64, float64) {
	fmt.Printf("%T \n", nums)

	total := 0.0
	index := 0.0
	for i, v := range nums {
		total += v
		index += float64(i)
	}
	div := float64(len(nums))

	return total / div, index / div
}

// z := 1 // can't use this format here
var z int

func closureExample(x int) func() int {
	y := 0
	var u int
	return func() int {
		y++
		u++
		z += 2
		return x + y + z + u
	}
}

func applyCallback(nums []float64, callback func(float64) float64) {
	for _, v := range nums {
		fmt.Printf("%f ", callback(v))
	}
	fmt.Println()
}
func main() {
	fmt.Println(multipleArgsMultipleReturn("123", "456")) // args are passed
	fmt.Println("-----")
	fmt.Println(multipleArgsMultipleReturn2("abc", "efg"))
	fmt.Println("-----")
	fmt.Println(variadicAverage(4, 5, 3.4, 2, 3, 5, 6, 10, 0, -1.6))
	fmt.Println("-----")
	data := []float64{4, 5, 3.4, 2, 3, 5, 6, 10, 0, -1.6}
	fmt.Println(variadicAverage(data...))
	fmt.Println("-----")
	// cannot use data (type []float64) as type float64 in argument to variadicAverage
	// fmt.Println(variadicAverage(data))
	fmt.Println("-----")
	funcExpression := func() string {
		return "I am from an anonymous function"
	}
	fmt.Printf("%T \n", funcExpression)
	fmt.Println(funcExpression())
	fmt.Println("-----")
	closureEx := closureExample(10)
	fmt.Println(closureEx())
	fmt.Println(closureEx())
	fmt.Println(closureEx())
	fmt.Println(closureExample(10))
	fmt.Println(closureExample(10)())
	fmt.Println(closureExample(10)())
	fmt.Println(closureExample(10)())
	fmt.Println(closureExample(11))
	fmt.Println(closureExample(11)())
	fmt.Println(closureExample(11)())
	fmt.Println(closureExample(12)())
	fmt.Println(closureExample(13)())
	fmt.Println("-----")
	applyCallback([]float64{1, 4, 5.4, 3, 54.3, -34.2}, func(x float64) float64 {
		return x*5 + 2.5
	})
	fmt.Println("-----")
}
