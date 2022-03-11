package main

import "fmt"
import "sort"
import (
	"bytes"
	"io"
	"net/http"
	"os"
	"strings"
)

// golint
// method sets concept

// TODO Does the subtype must implement all methods of the supertype?

// Universal is an empty interface.
type Universal interface {
	// You can put some methods here.
}

// Animal is a subtype of Universal.
type Animal interface {
	Universal
	// alive bool // An interface can't hold a variable.
	feed(x int) int
	kill() bool
	killDash9() bool
	// function(){} // An interface can't hold an implemented function.
}

// Dog is a struct implementing Animal interface.
type Dog struct {
	alive  bool
	weight int
}

// Holyshit: This function doesn't work as expected since the `d` is passed by the value, not the reference!
func (d Dog) feed(x int) int {
	fmt.Println("\t\t ________________ \n")
	fmt.Printf("\t\t inside `feed` `method` of Dog: \n\t\t\t d: %v \n\t\t\t d: %p \n\t\t\t &d: %p \n\t\t\t type(d): %T \n", d, d, &d, d)
	d.weight += 10

	return x - 10
}

// Holyshit: This function doesn't work as expected since the `d` is passed by the value, not the reference!
func (d Dog) kill() bool {
	fmt.Println("\t\t ________________ \n")
	fmt.Printf("\t\t inside `kill` `method` of Dog: \n\t\t\t d: %v \n\t\t\t d: %p \n\t\t\t &d: %p \n\t\t\t type(d): %T \n", d, d, &d, d)

	if d.alive {
		d.alive = false
		return true
	}

	return false
}

// This works. `d` is the reference here.
func (d *Dog) killDash9() bool {
	fmt.Printf("\t\t ________________ \n")
	fmt.Printf("\t\t inside `killDash9` `method` of Dog: \n\t\t\t d: %v \n\t\t\t d: %p \n\t\t\t &d: %p \n\t\t\t type(d): %T \n", d, d, &d, d)
	// fmt.Printf("%p	%p\n", &d.alive, &(*d).alive)
	// if *d.alive { // invalid indirect of d.alive (type bool)
	// if (*d).alive { // This works too.
	if d.alive {
		// *d.alive = false // This doesn't work. invalid indirect of d.alive (type bool)
		// (*d).alive = false // This works.
		d.alive = false
		return true
	}

	return false
}

/* If you pass a  `struct`, it will be passed by value.
   If you pass a `&struct`, its reference (reference of the real `struct`) will be passed by value, so you have direct access to the original struct.
   You can pass both `struct` and `&struct` to this function.
*/
func feed(a Animal, x int) int {
	fmt.Printf("\t inside \"feed(a Animal, x int)\": \n\t\t a: %v \n\t\t a: %p \n\t\t &a: ===> %p <===\n\t\t type(a): =======> %T <======= \n", a, a, &a, a)
	/* If `a` is actually a struct:
	 	if `method` `feed` `receiver` input is a pointer:
	 		This is not possible because of parallel type system. Refer to `124-method-sets.mp4` for more info.
	 	else
			A new struct is formed from `a` somewhere in the memory and passed to the receiver.
	   If `a` is a pointer to a struct:
	 	if `method` `feed` `receiver` input is a pointer:
	 		`a` is passed by value (receiver receives a pointer to the real struct).
	 	else
			A new struct is formed from `a` somewhere in the memory and passed to the receiver.
	   Everything is passed by value!
	*/
	return a.feed(x)
}

// error: feed redeclared in this block
/*
func feed(d Dog, x int) int {
	return d.feed(x)
}
*/

func feed2(d Dog, x int) int {
	return d.feed(x)
}

/* If you pass a  `struct`, it will be passed by value.
   If you pass a `&struct`, its reference (reference of the real `struct`) will be passed by value, so you have direct access to the original struct.
   You can pass both `struct` and `&struct` to this function.
*/
func kill(a Animal) bool {
	fmt.Printf("\t inside \"kill(a Animal)\": \n\t\t a: %v \n\t\t a: %p \n\t\t &a: ===> %p <===\n\t\t type(a): =======> %T <======= \n", a, a, &a, a)
	/* If `a` is actually a struct:
	 	if `method` `kill` `receiver` input is a pointer:
	 		This is not possible because of parallel type system. Refer to `124-method-sets.mp4` for more info.
	 	else
			A new struct is formed from `a` somewhere in the memory and passed to the receiver.
	   If `a` is a pointer to a struct:
	 	if `method` `kill` `receiver` input is a pointer:
	 		`a` is passed by value (receiver receives a pointer to the real struct).
	 	else
			A new struct is formed from `a` somewhere in the memory and passed to the receiver.
	   Everything is passed by value!
	*/
	return a.kill()
}

/* If you pass a  `struct`, it will be passed by value.
   If you pass a `&struct`, its reference (reference of the real `struct`) will be passed by value, so you have direct access to the original struct.
   You can pass both `struct` and `&struct` to this function.
*/
func killDash9(a Animal) bool {
	fmt.Printf("\t inside \"killDash9(a Animal)\": \n\t\t a: %v \n\t\t a: %p \n\t\t &a: ===> %p <===\n\t\t type(a): =======> %T <======= \n", a, a, &a, a)
	// return (*a).killDash9() // Doesn't work.
	// return (&a).killDash9() // Doesn't work.
	/* If `a` is actually a struct:
	 	if `method` `killDash9` `receiver` input is a pointer:
	 		This is not possible because of parallel type system. Refer to `124-method-sets.mp4` for more info.
	 	else
			A new struct is formed from `a` somewhere in the memory and passed to the receiver.
	   If `a` is a pointer to a struct:
	 	if `method` `killDash9` `receiver` input is a pointer:
	 		`a` is passed by value (receiver receives a pointer to the real struct).
	 	else
			A new struct is formed from `a` somewhere in the memory and passed to the receiver.
	   Everything is passed by value!
	*/
	return a.killDash9()
}

// Cat is a struct implementing Animal interface.
type Cat struct {
	alive  bool
	weight int
}

// Holyshit: This function doesn't work as expected since the `c` is passed by the value, not the reference!
func (c Cat) feed(x int) int {
	fmt.Println("\t\t ________________ \n")
	fmt.Printf("\t\t inside `feed` `method` of Cat: \n\t\t\t c: %v \n\t\t\t c: %p \n\t\t\t &c: %p \n\t\t\t type(c): %T \n", c, c, &c, c)
	c.weight += 5

	return x - 5
}

// Holyshit: This function doesn't work as expected since the `c` is passed by the value, not the reference!
func (c Cat) kill() bool {
	fmt.Println("\t\t ________________ \n")
	fmt.Printf("\t\t inside `kill` `method` of Cat: \n\t\t\t c: %v \n\t\t\t c: %p \n\t\t\t &c: %p \n\t\t\t type(c): %T \n", c, c, &c, c)

	if c.alive {
		c.alive = false
		return true
	}

	return false
}

// Holyshit: This function doesn't work as expected since the `c` is passed by the value, not the reference!
func (c Cat) killDash9() bool {
	fmt.Printf("\t\t ________________ \n")
	fmt.Printf("\t\t inside `killDash9` `method` of Cat: \n\t\t\t c: %v \n\t\t\t c: %p \n\t\t\t &c: %p \n\t\t\t type(c): %T \n", c, c, &c, c)

	if c.alive {
		c.alive = false
		return true
	}

	return false
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
	// x is a reference.
	x[i], x[j] = x[j], x[i]
}

// Cats is an array of Cat.
type Cats []Cat

func (x Cats) Len() int {
	return len(x)
}

func (x Cats) Less(i, j int) bool {
	return x[i].weight <= x[j].weight
}

func (x Cats) Swap(i, j int) {
	x[i], x[j] = x[j], x[i]
}

func sortExamples() {
	a1 := []string{"hello", "bye", "salam", "hellyeah"}
	fmt.Printf("before sorting: %v\n", a1)
	sort.Strings(a1)
	fmt.Printf("after  sorting: %v\n", a1)

	fmt.Println("---------------------")

	a2 := []float64{1.4, 2.5, -1.3, 0.5, 0, 0.0}
	fmt.Printf("before sorting: %v\n", a2)
	sort.Float64s(a2)
	fmt.Printf("after  sorting: %v\n", a2)

	fmt.Println("---------------------")

	a3 := []float64{1.4, 2.5, -1.3, 0.5, 0, 0.0}
	fmt.Printf("before sorting in decreasing order: %v\n", a3)
	sort.Sort(sort.Reverse(sort.Float64Slice(a3)))
	fmt.Printf("after  sorting in decreasing order: %v\n", a3)

	fmt.Println("---------------------")

	a4 := foo{"abc", "dd", "de", "zz", "ab"}
	fmt.Printf("before sorting: %v\n", a4)
	sort.Sort(a4) // The sort is performed in-place.
	fmt.Printf("after  sorting: %v\n", a4)

	fmt.Println("---------------------")

	// TODO The type is being converted to the `Interface` or the instance? Are the methods (Len, Swap, and Less) are appended to the instance?
	a5 := sort.StringSlice(a1)
	// TODO Why `&a1` is different from `&a5`?
	fmt.Printf("a5, &a5, &a1, type(a5):	%v	%p	%p	%T\n", a5, &a5, &a1, a5)

	fmt.Println("---------------------")

	// TODO Does `Reverse` modifies the `Swap` `method`?
	a6 := sort.Reverse(a5)
	fmt.Printf("a6, &a6, &a5, type(a6):	%v	%p	%p	%T\n", a6, &a6, &a5, a6)

	fmt.Println("---------------------")

	a7 := Cats{{true, 55}, {false, 60}, {false, 54}}
	fmt.Printf("before sorting: %v\n", a7)
	sort.Sort(a7)
	fmt.Printf("after  sorting: %v\n", a7)

	fmt.Println("---------------------")
}

func main() {
	dog := &Dog{true, 70}
	// TODO Dog{} vs &Dog{}
	fmt.Printf("before feeding:\n\tdog: %v\n\ttype(dog): %T\n\taddress of dog: %p\n", dog, dog, dog)
	fmt.Println("---------------------")
	food := 43
	remainedFood := feed(dog, food)
	fmt.Println("---------------------")
	fmt.Printf("remained food: %v\n", remainedFood)
	fmt.Println("---------------------")
	fmt.Printf("after  feeding:\n\tdog: %v\n\ttype(dog): %T\n\taddress of dog: %p\n", dog, dog, dog)
	fmt.Println("As you see, there is no change applied to the dog!")
	fmt.Println("---------------------")

	fmt.Println("\n\n+++++++++++++++++++++")
	fmt.Println("+++++++++++++++++++++")
	fmt.Println("+++++++++++++++++++++\n\n")

	wasAlive := kill(dog)
	fmt.Println("---------------------")
	fmt.Printf("was alive: %v\n", wasAlive)
	fmt.Println("---------------------")
	wasAlive = kill(dog)
	fmt.Println("---------------------")
	fmt.Printf("was alive: %v\n", wasAlive)
	fmt.Println("---------------------")
	wasAlive = kill(dog)
	fmt.Println("---------------------")
	fmt.Printf("was alive: %v\n", wasAlive)
	fmt.Println("As you see, there is no change applied to the dog!")
	fmt.Println("---------------------")

	fmt.Println("\n\n+++++++++++++++++++++")
	fmt.Println("+++++++++++++++++++++")
	fmt.Println("+++++++++++++++++++++\n\n")

	wasAlive = killDash9(dog)
	fmt.Println("---------------------")
	fmt.Printf("was alive: %v\n", wasAlive)
	fmt.Println("---------------------")
	wasAlive = killDash9(dog)
	fmt.Println("---------------------")
	fmt.Printf("was alive: %v\n", wasAlive)
	fmt.Println("---------------------")
	wasAlive = killDash9(dog)
	fmt.Println("---------------------")
	fmt.Printf("was alive: %v\n", wasAlive)
	fmt.Println("---------------------")

	fmt.Println("\n\n+++++++++++++++++++++")
	fmt.Println("+++++++++++++++++++++")
	fmt.Println("+++++++++++++++++++++\n\n")

	// feed2(dog, 100) // TODO Why it doesn't work? // cannot use dog (type *Dog) as type Dog in argument to feed2
	feed2(*dog, 5666)

	fmt.Println("**************************************************************")

	// very important:
	// 	cannot use dog2 (type Dog) as type Animal in argument to feed:
	// 	Dog does not implement Animal (killDash9 method has pointer receiver)
	// dog2 := Dog{true, 876} // There is no `&` sign.
	// feed(dog2, 56)

	fmt.Println("**************************************************************")

	cat := Cat{true, 96} // There is no `&` sign.
	fmt.Printf("before feeding:\n\tcat: %v\n\ttype(cat): %T\n\taddress of cat: %p\n\taddress of cat: %p \n", cat, cat, cat, &cat)
	fmt.Println("---------------------")
	food = 34
	remainedFood = feed(cat, food)
	fmt.Println("---------------------")
	fmt.Printf("remained food: %v\n", remainedFood)
	fmt.Println("---------------------")
	fmt.Printf("after  feeding:\n\tcat: %v\n\ttype(cat): %T\n\taddress of cat: %p\n\taddress of cat: %p \n", cat, cat, cat, &cat)
	fmt.Println("---------------------")

	fmt.Println("\n\n+++++++++++++++++++++")
	fmt.Println("+++++++++++++++++++++")
	fmt.Println("+++++++++++++++++++++\n\n")

	wasAlive = kill(cat)
	fmt.Println("---------------------")
	fmt.Printf("was alive: %v\n", wasAlive)
	fmt.Println("---------------------")
	wasAlive = kill(cat)
	fmt.Println("---------------------")
	fmt.Printf("was alive: %v\n", wasAlive)
	fmt.Println("---------------------")
	wasAlive = kill(cat)
	fmt.Println("---------------------")
	fmt.Printf("was alive: %v\n", wasAlive)
	fmt.Println("---------------------")

	fmt.Println("\n\n+++++++++++++++++++++")
	fmt.Println("+++++++++++++++++++++")
	fmt.Println("+++++++++++++++++++++\n\n")

	wasAlive = killDash9(cat)
	fmt.Println("---------------------")
	fmt.Printf("was alive: %v\n", wasAlive)
	fmt.Println("---------------------")
	wasAlive = killDash9(cat)
	fmt.Println("---------------------")
	fmt.Printf("was alive: %v\n", wasAlive)
	fmt.Println("---------------------")
	wasAlive = killDash9(cat)
	fmt.Println("---------------------")
	fmt.Printf("was alive: %v\n", wasAlive)
	fmt.Println("---------------------")

	fmt.Println("\n\n+++++++++++++++++++++")
	fmt.Println("+++++++++++++++++++++")
	fmt.Println("+++++++++++++++++++++\n\n")

	// anim := Animal{} // invalid composite literal type Animal

	// An struct can't have a function inside the body.
	// type structWithFunction struct {
	//	feed(x int) int
	// }

	type structWithNoBody struct{}
	var structwithnobody structWithNoBody
	fmt.Printf("structwithnobody: %v %T\n", structwithnobody, structwithnobody)
	fmt.Println("---------------------")

	fmt.Println("\n\n+++++++++++++++++++++")
	fmt.Println("+++++++++++++++++++++")
	fmt.Println("+++++++++++++++++++++\n\n")

	sortExamples()

	a := []Universal{Dog{true, 50}, Cat{false, 66}, Cat{true, 54}} // It's possible to store Dogs and Cats inside an array of type Universal because of polymorphism.
	fmt.Printf("storing Cats and Dogs inside a Universal slice: %v\n", a)
	for _, v := range a {
		fmt.Printf("\t%v	%T\n", v, v)
	}

	fmt.Println("---------------------")

	sameInterfaceAsInput()

	fmt.Println("---------------------")

	acceptAnything("hello")
	acceptAnything(1)
	acceptAnything(Dog{true, 123})

	fmt.Println("---------------------")

	type persianCat struct {
		Cat
		something float64
	}

	// cannot use persianCat{...} (type persianCat) as type Cat in slice literal
	// pc := []Cat{persianCat{Cat{true, 34}, 4.3}, persianCat{Cat{true, 56}, -1.2}}

	// for _, c := range pc {
	// 	fmt.Printf("%v	%T\n", c, c)
	// }

	// Same as []Universal defined above.
	pc := []interface{}{persianCat{Cat{true, 34}, 4.3}, persianCat{Cat{true, 56}, -1.2}}

	for _, c := range pc {
		fmt.Printf("%v	%T\n", c, c)
	}

	fmt.Println("---------------------")
}

func sameInterfaceAsInput() {
	rdr := strings.NewReader("I come from somewhere!\n")
	io.Copy(os.Stdout, rdr)
	rdr2 := bytes.NewBuffer([]byte("I come from somewhere 2!\n"))
	io.Copy(os.Stdout, rdr2)
	res, _ := http.Get("https://web.ics.purdue.edu/~gchopra/class/public/pages/webdesign/05_simple.html")
	io.Copy(os.Stdout, res.Body)
	res.Body.Close()
}

// This function accepts anything.
func acceptAnything(x interface{}) {
	fmt.Println(x)
}
