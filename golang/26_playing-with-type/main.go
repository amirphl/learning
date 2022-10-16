package main

import (
	"fmt"
	"math"
	"reflect"
	"strconv"
)

// TODO Why does this code prints two sequential `In goroutine`s?
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
	fmt.Printf("-----------\n")
}

func intInt() {
	var a int = 8
	var b int = 4
	fmt.Printf("8/4=%v    %T\n", a/b, a/b)
}

func intInt2() {
	var a int = 7
	var b int = 4
	fmt.Printf("7/4=%v    %T\n", a/b, a/b)
}

/*
func intFloat() {
	var a int = 8
	var b float32 = 4.0
	// invalid operation: a / b (mismatched types int and float32)
	fmt.Printf("8/4.0=%v    %T\n", a/b, a/b)
}
*/

/*
func intFloat2() {
	var a int = 8
	var b float32 = 4.1
	// invalid operation: a / b (mismatched types int and float32)
	fmt.Printf("8/4.1=%v    %T\n", a/b, a/b)
}
*/

/*
func intFloat3() {
	fmt.Printf("\n ----------- \n intFloat3:\n")
	var a int = 8
	var b float32 = 4.0
	// invalid operation: a / b (mismatched types int and float32)
	var c int = a/b
	fmt.Printf("%v   %T\n", c, c)
}
*/

// invalid code
/*
func intFloat4() {
	fmt.Printf("\n ----------- \n intFloat4:\n")
	var a int
	a = 8 / 4.1
	fmt.Println(a)
}
*/

func stringString() {
	fmt.Printf("\n ----------- \n stringString:\n")
	var a string = "hello"
	fmt.Printf("%v    %T\n", a, a)
}

func stringByte() {
	fmt.Printf("\n ----------- \n stringByte:\n")
	var a []byte = []byte("hello")
	fmt.Printf("%v    %T\n", a, a)
}

func stringImmutable() {
	fmt.Printf("\n ----------- \n stringImmutable:\n")
	a := "salam"
	fmt.Printf("%v    %p\n", a, &a)
	a = "bye"
	fmt.Printf("%v    %p\n", a, &a)
}

/*
func changeImmutable() {
	fmt.Printf("\n ----------- \n changeImmutable:\n")
	a := "salam"
	a[0] = "f"
	fmt.Println(a)
}
*/

func lenEnglish() {
	fmt.Printf("\n ----------- \n lenEnglish:\n")
	fmt.Printf("%v\n", len("hello"))
}

// Very important!
func lenPersian() {
	fmt.Printf("\n ----------- \n lenPersian:\n")
	fmt.Printf("%v\n", len("سلام"))
}

func lenCombined() {
	fmt.Printf("\n ----------- \n lenCombined:\n")
	fmt.Printf("%v\n", len("helloسلام"))
}

func binary() {
	fmt.Printf("\n ----------- \n binary:\n")
	a := "hello---سلام"
	fmt.Printf("%v   %v   %T\n", a, len(a), a)
	b := []byte(a)
	fmt.Printf("%v   %v   %T\n", b, len(b), b)

	for _, v := range b {
		fmt.Printf("%d     %#x     %b\n", v, v, v)
	}

	c := 999999999999999999
	fmt.Printf("%d     %#x     %b     %p     %T\n", c, c, c, &c, c)
	fmt.Sprint(c)

	d := 'y'
	fmt.Printf("%v\n", d)
}

func indexAccess() {
	fmt.Printf("\n ----------- \n indexAccess:\n")
	a := "salam"
	fmt.Printf("%v   %v   %v   %v   %v\n", a[1], a[3], a[2:3], a[:3], a[3:])
	// panic: runtime error: slice bounds out of range [:10] with length 5
	/*
		fmt.Printf("%v\n", a[:10])
		fmt.Printf("%v\n", a[10])
	*/
	// invalid code
	/*
		fmt.Printf("%v\n", a[-1])
		fmt.Printf("%v\n", a[:-1])
		fmt.Printf("%v\n", a[-1:])
	*/
}

func concatenation() {
	fmt.Printf("\n ----------- \n concatenation:\n")
	a := "salam"
	b := "bye"
	fmt.Printf("%v\n", a+b)
	// invalid code
	/*
		fmt.Printf("%T\n", append(a, b))
		fmt.Printf("%v\n", append(a, b))
	*/
}

func concatenation2() {
	fmt.Printf("\n ----------- \n concatenation2:\n")
	a := []byte("salam")
	b := []byte("bye")
	// invalid code
	/*
		fmt.Printf("%v\n", a+b)
		append(a, b)
	*/
	a = append(a, 1)
	b = append(b, 1)
	fmt.Printf("%v\n", a)
	fmt.Printf("%v\n", b)
	fmt.Printf("%p\n", &a)
	a = append(a, b...)
	fmt.Printf("%v\n", a)
	fmt.Printf("%p\n", &a)
}

func strconvSamples() {
	fmt.Printf("\n ----------- \n strconvSamples:\n")
	a := strconv.Itoa(-1)
	b := strconv.Itoa(1)
	c := strconv.Itoa(255)
	d := strconv.Itoa(256)
	dd := strconv.Itoa(100)
	e, e1 := strconv.Atoi("-1")
	f, e2 := strconv.Atoi("1")
	g, e3 := strconv.Atoi("255")
	h, e4 := strconv.Atoi("256")
	i, e5 := strconv.Atoi("100")
	fmt.Printf("%v   %v   %v   %v   %T\n", a, b, c, d, dd)
	fmt.Printf("%v   %v   %v   %v   %T\n", e, f, g, h, i)
	fmt.Printf("%v   %v   %v   %v   %T\n", e1, e2, e3, e4, e5)
}

func sprintSamples() {
	fmt.Printf("\n ----------- \n sprintSamples:\n")
	a := fmt.Sprint(-1)
	b := fmt.Sprint(1)
	c := fmt.Sprint(255)
	d := fmt.Sprint(256)
	e := fmt.Sprint(100)
	fmt.Printf("%v   %v   %v   %v   %T\n", a, b, c, d, e)
}

func mathFloor() {
	fmt.Printf("\n ----------- \n mathFloor:\n")
	fmt.Printf("%v\n", math.Floor(0.6))
	fmt.Printf("%v\n", math.Floor(0.1))
	fmt.Printf("%v\n", math.Floor(-0.1))
}

func reflectSamples() {
	fmt.Printf("\n ----------- \n reflectSamples:\n")
	fmt.Printf("%v\n", reflect.TypeOf(nil))
	fmt.Printf("%v\n", reflect.TypeOf(2))
	fmt.Printf("%v\n", reflect.TypeOf(2.1))
	fmt.Printf("%v\n", reflect.TypeOf("2.1"))
	fmt.Printf("%v\n", reflect.TypeOf(`2.1`))
}

type newString string

func stringConversion() {
	fmt.Printf("\n ----------- \n anotherTypeLikeString:\n")
	var a newString = "hello"
	b := string(a)
	fmt.Printf("%T   %T\n", a, b)
	// invalid conversion
	/*
		c := a.(string)
		d := b.(newString)
		fmt.Printf("%T\n", c)
		fmt.Printf("%T\n", d)
	*/
}

func zeroValInit() {
	fmt.Printf("\n ----------- \n zeroValInit:\n")
	type a struct {
		a, b int
		c    bool
		d    string
		f    float32
		g    rune
	}

	var b a
	fmt.Println(b)
}

type sliceStr []string

func sliceString() {
	fmt.Printf("\n ----------- \n sliceString:\n")
	a := sliceStr{"11", "salam", "ha_"}
	fmt.Printf("%T\n", a)
	// invalid conversion
	/*
		b := a.([]string)
		fmt.Printf("%T\n", b)
	*/
	c := []string(a)
	fmt.Printf("%v   %T\n", c, c)
	var d sliceStr = []string{"s", "a"}
	fmt.Printf("%T\n", d)
}

func main() {
	q1()
	intInt()
	intInt2()
	// intFloat()
	// intFloat2()
	// intFloat3()
	stringString()
	stringByte()
	stringImmutable()
	// changeImmutable()
	lenEnglish()
	lenPersian()
	lenCombined()
	binary()
	indexAccess()
	concatenation()
	concatenation2()
	strconvSamples()
	sprintSamples()
	mathFloor()
	reflectSamples()
	stringConversion()
	zeroValInit()
	sliceString()
}
