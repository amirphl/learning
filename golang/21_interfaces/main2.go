package main2

import (
	"bytes"
	"fmt"
	"io"
	"net/http"
	"os"
	"sort"
	"strings"
)

// Universal is an empty interface.
type Universal interface {
	// You can put some methods here.
}

// MyInterface is a subtype of Universal.
type MyInterface interface {
	Universal
	// field bool // An interface can't hold a variable.
	Mthd_1()
	Mthd_2()
	// function(){} // An interface can't hold an implemented function.
}

// TODO lowercase vs Uppercase methods of an interface. mthd_1 vs Mthd_1

// `MyStruct` is a struct implementing `MyInterface` interface.
type MyStruct struct {
	x int
}

// `d` is passed by the value, not the reference!
func (d MyStruct) Mthd_1() {
	fmt.Printf("%p\n", &d)
	d.x += 10
}

// Uncomment to see the diff!
/*
func (d MyStruct) Mthd_2() {
	d.x -= 7
}
*/

// `d` is passed by the value, not the reference!
// Note: `d` is a reference.
func (d *MyStruct) Mthd_2() {
	fmt.Printf("%p	 %p\n", d, &(*d))
	// *d.x -= 7 // This doesn't work. invalid indirect of d.x (type int)
	// (*d).x -= 7 // This works too.
	d.x -= 7
}

func acceptInterfaceAsVal(d MyInterface) {
	fmt.Printf("%v          %p\n", d, &d)
	// fmt.Println(d.x)
	s := d.(*MyStruct)
	fmt.Println(s.x)
	d.Mthd_1()
	fmt.Println(s.x)
	d.Mthd_2()
	fmt.Println(s.x)
}

func acceptInterfaceAsRef(d *MyInterface) {
	fmt.Printf("%v          %p          %p\n", *d, d, &d)
	// s := d.(MyStruct)
	// d.Mthd_1()
	// d.Mthd_2()
}

func accepStructAsVal(d MyStruct) {
	fmt.Printf("%p\n", &d)
	fmt.Println(d.x)
	d.Mthd_1()
	fmt.Println(d.x)
	d.Mthd_2()
	fmt.Println(d.x)
}

func accepStructAsRef(d *MyStruct) {
	fmt.Printf("%p          %p\n", d, &d)
	fmt.Println(d.x)
	d.Mthd_1()
	fmt.Println(d.x)
	d.Mthd_2()
	fmt.Println(d.x)
}

func valToVal() {
	fmt.Println("val to val")
	d := MyStruct{100}
	fmt.Printf("%p\n", &d)
	// acceptInterfaceAsVal(d)
	accepStructAsVal(d)
}

func valToRef() {
	fmt.Println("val to ref")
	d := MyStruct{100}
	fmt.Printf("%p\n", &d)
	// acceptInterfaceAsRef(d)
	// accepStructAsRef(d)
}

func refToVal() {
	fmt.Println("ref to val")
	d := &MyStruct{100}
	fmt.Printf("%p\n", d)
	acceptInterfaceAsVal(d)
	// accepStructAsVal(d)
}

func refToRef() {
	fmt.Println("ref to ref")
	d := &MyStruct{100}
	fmt.Printf("%p\n", d)
	// acceptInterfaceAsRef(d)
	accepStructAsRef(d)
}

type foo []string

// assigning function to type
func (x foo) Len() int {
	return len(x)
}

// assigning function to type
func (x foo) Less(i, j int) bool {
	return x[i] <= x[j]
}

// assigning function to type
func (x foo) Swap(i, j int) {
	x[i], x[j] = x[j], x[i]
}

func sortExamples() {
	fmt.Println("sorting examples")

	a1 := []string{"hello", "bye", "salam", "hellyeah"}
	fmt.Printf("before sorting: %v\n", a1)
	sort.Strings(a1)
	fmt.Printf("after  sorting: %v\n", a1)

	fmt.Println("+++++++++++")

	a2 := []float64{1.4, 2.5, -1.3, 0.5, 0, 0.0}
	fmt.Printf("before sorting: %v\n", a2)
	sort.Float64s(a2)
	fmt.Printf("after  sorting: %v\n", a2)

	fmt.Println("+++++++++++")

	a3 := []float64{1.4, 2.5, -1.3, 0.5, 0, 0.0}
	fmt.Printf("before sorting in decreasing order: %v\n", a3)
	sort.Sort(sort.Reverse(sort.Float64Slice(a3)))
	fmt.Printf("after  sorting in decreasing order: %v\n", a3)

	fmt.Println("+++++++++++")

	a4 := foo{"abc", "dd", "de", "zz", "ab"}
	fmt.Printf("before sorting: %v\n", a4)
	sort.Sort(a4) // The sort is performed in-place.
	fmt.Printf("after  sorting: %v\n", a4)

	fmt.Println("+++++++++++")

	a5 := sort.StringSlice(a1) // casting
	fmt.Println("Note: &a1 != &a5")
	fmt.Printf("a5, &a5, &a1, type(a5):	%v	%p	%p	%T\n", a5, &a5, &a1, a5)
	a1[0] = "zzzz"
	fmt.Println(a5) // See the effect of the previous line on the output.

	fmt.Println("+++++++++++")

	a6 := sort.Reverse(a5)
	fmt.Printf("a6, &a6, &a5, type(a6):	%v	%p	%p	%T\n", a6, &a6, &a5, a6)

	fmt.Println("+++++++++++")
}

func noBody() {
	fmt.Println("struct with no body")
	type structWithNoBody struct{}
	var structwithnobody structWithNoBody
	fmt.Printf("structwithnobody:   %v   %T\n", structwithnobody, structwithnobody)
}

func polyMor() {
	fmt.Println("polymorphism")
	var a []Universal = []Universal{MyStruct{99}, MyStruct{100}, MyStruct{101}} // It's possible to store MyStruct(s) inside an array of type Universal because of polymorphism.
	for _, v := range a {
		fmt.Printf("%v	%T\n", v, v)
	}
}

func sameInterfaceAsInput() {
	fmt.Println("passing interfaces which have different underlying structs")
	rdr := strings.NewReader("text 1\n")
	io.Copy(os.Stdout, rdr)
	rdr2 := bytes.NewBuffer([]byte("text 2\n"))
	io.Copy(os.Stdout, rdr2)
	res, _ := http.Get("https://web.ics.purdue.edu/~gchopra/class/public/pages/webdesign/05_simple.html")
	io.Copy(os.Stdout, res.Body)
	res.Body.Close()
}

// This function accepts anything.
func acceptAnything(x interface{}) {
	fmt.Println(x)
}

func main() {
	valToVal()
	fmt.Println("-----------------")
	valToRef()
	fmt.Println("-----------------")
	refToVal()
	fmt.Println("-----------------")
	refToRef()
	fmt.Println("-----------------")
	sortExamples()
	fmt.Println("-----------------")
	noBody()
	fmt.Println("-----------------")
	polyMor()
	fmt.Println("-----------------")
	sameInterfaceAsInput()
	fmt.Println("-----------------")
	acceptAnything(MyStruct{123})
	acceptAnything("hello")
	fmt.Println("-----------------")
}
