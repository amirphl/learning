package main

import "fmt"

type foo int
type foo2 int

type info struct {
	firstName string
	age       foo
	hw        weightHeight
}

type weightHeight struct {
	weight int
	height foo
}

type Parent struct {
	a int
	b float64
	c string
}

type child struct {
	Parent
	d int
	e string
	c int16 // `c` overwrites the `c` of Parent
}

func main() {
	var a1 foo = 60
	var a2 foo2 = 70
	fmt.Printf("type(a1), a1: %T, %v\n", a1, a1)
	// a2 = a1 // cannot use a1 (type foo) as type foo2 in assignment
	// a2 = int(a1) // This isn't possbile.
	a2 = foo2(a1) // This is possbile.
	fmt.Printf("type(a2), a2: %T, %v\n", a2, a2)

	b := info{"amirphl", 23, weightHeight{75, 177}}
	fmt.Printf("b, &b, &b.firstName: %v	%p	%p\n", b, &b, &b.firstName)

	p1 := Parent{
		a: 1, // difference way of initialization. Compare with b.
		b: 4.3,
		c: "this-is-a-string",
	}

	c1 := child{
		Parent: p1,
		d:      8,
		e:      "hell-yeah",
		c:      int16(20000),
	}

	fmt.Printf("p1: %v\n", p1)
	fmt.Printf("c1: %v\n", c1)
}
