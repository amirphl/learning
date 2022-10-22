package main

import "fmt"

// ex: multiple params, multiple return
func multipleArgsMultipleReturn(a, b string) (string, string) { // parames are received
	return fmt.Sprint(a, b), fmt.Sprint(b, a)
}

// named return
func multipleArgsMultipleReturn2(a, b string) (c, d string) {
	c = fmt.Sprint(a, b)
	d = fmt.Sprint(b, a)
	return
}

// ex: variadic param
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

// ex: closure
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

// ex: passing a function as a param (like callbacks of js)
func applyCallback(nums []float64, callback func(float64) float64) {
	for _, v := range nums {
		fmt.Printf("%f ", callback(v))
	}
	fmt.Println()
}

// ex: another example of passing a function as a parameter
func filter(nums []float64, callback func(float64) bool) (out []float64) {
	out = []float64{}

	for _, v := range nums {
		if callback(v) {
			out = append(out, v)
		}
	}

	return
}

// ex: recursion
func fibo(n int) int {
	if n < 0 {
		return -1
	}
	if n == 0 || n == 1 {
		return 1
	}
	return fibo(n-1) + fibo(n-2)
}

// ex: "defer" keyword
// usage example: defer file.Close()
func deferExample() {
	defer fmt.Println("before")
	fmt.Println("after")
}

// everything is pass by value!
// slices, maps, and channels are already references!
// references themselves are passed by value!
func changeString(name string) {
	var addr *string = &name
	fmt.Printf("inside changeString: %p %s\n", addr, name)
	name = "I-have-changed"
}

func sudoChangeString(name *string) {
	fmt.Printf("inside sudoChangeString: %p %p\n", name, &name)
	*name = "I-have-changed"
}

// `names` is passed by reference!
func changeContent(names []string, index int, newValue string) {
	names[index] = newValue
}

// reference is passed!
func changeKeyValue(keyValues map[string]int, key string, newValue int) {
	keyValues[key] = newValue
}

type info struct {
	name string
	age  int
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
	var out []float64 = filter([]float64{1, 2, 4.5, -0.2, 3.4, -4.3, -6, 4}, func(x float64) bool {
		if int64(x)%2 == 0 {
			return true
		}
		return false
	})
	fmt.Println(out)
	fmt.Println("-----")
	fmt.Println(fibo(0))
	fmt.Println(fibo(2))
	fmt.Println(fibo(4))
	fmt.Println(fibo(5))
	fmt.Println(fibo(6))
	fmt.Println("-----")
	deferExample()
	fmt.Println("-----")
	var name = "hello"
	fmt.Printf("name address: %p\n", &name)
	changeString(name)
	fmt.Println(name)
	sudoChangeString(&name)
	fmt.Println(name)
	fmt.Printf("name address: %p\n", &name)
	fmt.Println("-----")
	var names = []string{"amirphl", "A", "B"}
	fmt.Println(names)
	changeContent(names, 1, "I-am-new-value")
	fmt.Println(names)
	fmt.Println("-----")
	var ages = map[string]int{"Ronaldo": 37, "Messi": 34}
	fmt.Println(ages)
	changeKeyValue(ages, "Ronaldo", -1)
	changeKeyValue(ages, "amirphl", 23)
	fmt.Println(ages)
	fmt.Println("-----")
	func() {
		fmt.Println("I am a self-executing function!")
	}() // you can also pass params!
	fmt.Println("-----")
	// expression vs statement
	// An expression produces a result which can be stored inside a variable while a statement is an action.
	fmt.Println(1 == 2 || (2 == 2 && 3 == 3.0))
	fmt.Println("-----")
	information := info{"old-value", 100}
	fmt.Println(information)
	sudoChangeString(&information.name)
	fmt.Println(information)
	fmt.Println("-----")
}
