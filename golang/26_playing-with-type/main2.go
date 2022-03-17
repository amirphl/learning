package main

import (
	"fmt"
	"strconv"
)

func intInt() {
	fmt.Printf("\n ----------- \n intInt:\n")
	fmt.Printf("%v    %T\n", 8/4, 8/4)
}

func intInt2() {
	fmt.Printf("\n ----------- \n intInt2:\n")
	fmt.Printf("%v    %T\n", 7/4, 7/4)
}

func intFloat() {
	fmt.Printf("\n ----------- \n intFloat:\n")
	fmt.Printf("%v    %T\n", 8/4.0, 8/4.0)
}

func intFloat2() {
	fmt.Printf("\n ----------- \n intFloat2:\n")
	fmt.Printf("%v    %T\n", 8/4.1, 8/4.1)
}

func intFloat3() {
	fmt.Printf("\n ----------- \n intFloat3:\n")
	var a int
	a = 8 / 4.0
	fmt.Printf("%v    %T   %v   %T\n", a, a, 8/4.0, 8/4.0)
}

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
	fmt.Printf("%v    %T\n", "hello", "hello")
}

func stringByte() {
	fmt.Printf("\n ----------- \n stringByte:\n")
	fmt.Printf("%v    %T\n", []byte("hello"), []byte("hello"))
}

func stringImmutable() {
	fmt.Printf("\n ----------- \n stringImmutable:\n")
	a := "salam"
	fmt.Printf("%v    %p\n", a, &a)
	a = "bye"
	fmt.Printf("%v    %p\n", a, &a)
}

// invalid code
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

func lenPersian() {
	fmt.Printf("\n ----------- \n lenPersian:\n")
	fmt.Printf("%v\n", len("سلام"))
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

	c := 9999999999999999
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
}

func strconvSamples() {
	fmt.Printf("\n ----------- \n strconvSamples:\n")
	a := strconv.Itoa(-1)
	b := strconv.Itoa(1)
	c := strconv.Itoa(255)
	d := strconv.Itoa(256)
	e, e1 := strconv.Atoi("-1")
	f, e2 := strconv.Atoi("1")
	g, e3 := strconv.Atoi("255")
	h, e4 := strconv.Atoi("256")
	fmt.Printf("%v   %v   %v   %v\n", a, b, c, d)
	fmt.Printf("%v   %v   %v   %v\n", e, f, g, h)
	fmt.Printf("%v   %v   %v   %v\n", e1, e2, e3, e4)
}

func sprintSamples() {
	fmt.Printf("\n ----------- \n sprintSamples:\n")
	a := fmt.Sprint(-1)
	b := fmt.Sprint(1)
	c := fmt.Sprint(255)
	d := fmt.Sprint(256)
	fmt.Printf("%v   %v   %v   %v\n", a, b, c, d)
}

func main() {
	// intInt()
	// intInt2()
	// intFloat()
	// intFloat2()
	// intFloat3()
	// stringString()
	// byteStringByteString()
	stringImmutable()
	// changeImmutable()
	lenEnglish()
	lenPersian()
	binary()
	indexAccess()
	concatenation()
	concatenation2()
	strconvSamples()
	sprintSamples()
}
