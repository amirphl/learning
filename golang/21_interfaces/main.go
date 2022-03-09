package main

import "fmt"

type Animal interface {
	// alive bool // An interface can't hold a variable.
	feed(x int) int
	kill() bool
	killDash9() bool
	// function(){} // An interface can't hold an implemented function.
}

type Dog struct {
	alive  bool
	weight int
}

// Holyshit: This function doesn't work as expected since the `d` is passed by the value, not the reference!
func (d Dog) feed(x int) int {
	fmt.Println("\t\t________________\n")
	fmt.Printf("\t\tinside `feed` `method`: \n\t\t\t d: %v\n\t\t\t d: %p\n\t\t\t type(d): %T \n\t\t\t &d: %p\n", d, d, d, &d)
	d.weight += 10

	return x - 10
}

// Holyshit: This function doesn't work as expected since the `d` is passed by the value, not the reference!
func (d Dog) kill() bool {
	fmt.Println("\t\t________________\n")
	fmt.Printf("\t\tinside `kill` `method`: \n\t\t\t d: %v\n\t\t\t d: %p\n\t\t\t type(d): %T \n\t\t\t &d: %p\n", d, d, d, &d)
	d.weight += 10

	if d.alive {
		d.alive = false
		return true
	}

	return false
}

// This works. `d` is the reference here.
func (d *Dog) killDash9() bool {
	fmt.Printf("\t\t________________\n")
	fmt.Printf("\t\tinside `killDash9` `method`: \n\t\t\t d: %v\n\t\t\t d: %p\n\t\t\t type(d): %T \n\t\t\t &d: %p\n", d, d, d, &d)
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
	fmt.Printf("\tinside \"feed(a Animal, x int) int\":\n\t\ta: %v\n\t\ta: %p\n\t\t&a: ===> %p <===\n\t\t&x: %p\n\t\ttype(a): =======> %T <=======\n", a, a, &a, &x, a)
	/* If `a` is actually a struct:
	 	if `method` `feed` `receiver` input is a pointer:
	 		TODO
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
	fmt.Printf("\tinside \"kill(a Animal) bool\":\n\t\ta: %v\n\t\ta: %p\n\t\t&a:	===> %p <===\n\t\ttype(a): =======> %T <=======\n", a, a, &a, a)
	/* If `a` is actually a struct:
	 	if `method` `kill` `receiver` input is a pointer:
	 		TODO
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
	fmt.Printf("\tinside \"killDash9(a Animal) bool\":\n\t\ta: %v\n\t\ta: %p\n\t\t&a:	===> %p <===\n\t\ttype(a): =======> %T <=======\n", a, a, &a, a)
	// return (*a).killDash9() // Doesn't work.
	// return (&a).killDash9() // Doesn't work.
	/* If `a` is actually a struct:
	 	if `method` `killDash9` `receiver` input is a pointer:
	 		TODO
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

type Cat struct {
	alive  bool
	weight int
}

// Holyshit: This function doesn't work as expected since the `c` is passed by the value, not the reference!
func (c Cat) feed(x int) int {
	fmt.Println("\t\t________________\n")
	fmt.Printf("\t\tinside `feed` `method`: \n\t\t\t c: %v\n\t\t\t c: %p\n\t\t\t type(c): %T \n\t\t\t &c: %p\n", c, c, c, &c)
	c.weight += 5

	return x - 5
}

// Holyshit: This function doesn't work as expected since the `c` is passed by the value, not the reference!
func (c Cat) kill() bool {
	fmt.Println("\t\t________________\n")
	fmt.Printf("\t\tinside `kill` `method`: \n\t\t\t c: %v\n\t\t\t c: %p\n\t\t\t type(c): %T \n\t\t\t &c: %p\n", c, c, c, &c)

	if c.alive {
		c.alive = false
		return true
	}

	return false
}

// Holyshit: This function doesn't work as expected since the `c` is passed by the value, not the reference!
func (c Cat) killDash9() bool {
	fmt.Printf("\t\t________________\n")
	fmt.Printf("\t\tinside `killDash9` `method`: \n\t\t\t c: %v\n\t\t\t c: %p\n\t\t\t type(c): %T \n\t\t\t &c: %p\n", c, c, c, &c)

	if c.alive {
		c.alive = false
		return true
	}

	return false
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

	// # animal inst
}
