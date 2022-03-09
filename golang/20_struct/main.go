package main

import (
	"encoding/json"
	"fmt"
	"os"
	"strings"
)

type foo int
type foo2 int

type info struct {
	firstName string
	age       foo
	hw        weightHeight // It's defined after `info` and there's no problem.
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
	c int16
}

func (p Parent) do() {
	// You could access p fields(state) and methods here.
	// p.do() // **** Uncomment this line and you receive stack overflow!!!
	fmt.Println("I am the function do() and I belong to `Parent`.", "p:", p)
}

func (c child) do(x int) {
	// You could access c fields(state) and methods here.
	fmt.Println("I am the function do(x int) and I belong to `child`.", "c:", c, "x:", x)
}

type AAA struct {
	a int // This field is not exported since it's lowercase so it's not available in marshaling output.
	A string
	b bool // This field is not exported since it's lowercase so it's not available in marshaling output.
	B float64
	C string `json:"-"`   // Although this field is uppercase but it's not available in marshaling output because of the `-` tag.
	D string `json:"DDD"` // This field is renamed to DDD while marshaling.
}

func marshaling() {
	c1 := child{Parent{1, 1.2, "salam"}, 3, "bye", 4}
	c1Marshaled, err := json.Marshal(c1)
	c1Str := string(c1Marshaled)
	// very important: None of the fields of the c1 are exported (uppercase), so, the result is {}
	fmt.Printf("c1(marshaled), type of c1(marshaled), c1(string), marshaling error: %v, %T, %v, %v\n", c1Marshaled, c1Marshaled, c1Str, err)

	aaa := AAA{1, "salam", true, -3.4, "bye", "hello"}
	aaaMarshaled, aaaMarshErr := json.Marshal(aaa)
	aaaStr := string(aaaMarshaled)
	fmt.Printf("aaa(marshaled), type of aaa(marshaled), aaa(string), marshaling error: %v, %T, %v, %v\n", aaaMarshaled, aaaMarshaled, aaaStr, aaaMarshErr)

	fmt.Println("Filling values of `aaa` with persian words ...")

	aaa = AAA{1, "سلام", true, -3.4, "bye", "خداحافظ"}
	aaaMarshaled, aaaMarshErr = json.Marshal(aaa)
	aaaStr = string(aaaMarshaled)
	fmt.Printf("aaa(marshaled), type of aaa(marshaled), aaa(string), marshaling error: %v, %T, %v, %v\n", aaaMarshaled, aaaMarshaled, aaaStr, aaaMarshErr) //TODO It's still unit8. Why? Why not int32?
}

func unmarshaling() {
	a1 := AAA{}
	b1 := []uint8(`{"A":   "111"}`) // It can also be []byte // pay attention to extra spaces! It doesn't have any effects! // 111 is passed as a string, not an integer!
	e1 := json.Unmarshal(b1, &a1)
	fmt.Printf("a1, a1.A, b1, string(b1), e1:	%v	%v	%v	%v	%v\n", a1, a1.A, b1, string(b1), e1)

	a1 = AAA{}
	b1 = []uint8(`{"B":   "ture"}`)
	e1 = json.Unmarshal(b1, &a1) // json: cannot unmarshal string into Go struct field AAA.B of type float64
	fmt.Printf("a1, a1.B, b1, string(b1), e1:	%v	%v	%v	%v	%v\n", a1, a1.B, b1, string(b1), e1)

	a1 = AAA{}
	b1 = []uint8(`{"a":   "222"}`)
	e1 = json.Unmarshal(b1, &a1) // TODO Why a is stored inside A ?!
	fmt.Printf("(a is stored inside A!!!!) a1, a1.a, b1, string(b1), e1:	%v	%v	%v	%v	%v\n", a1, a1.a, b1, string(b1), e1)

	a1 = AAA{}
	b1 = []byte(`{"b":   "333"}`)
	e1 = json.Unmarshal(b1, &a1) // json: cannot unmarshal string into Go struct field TODO AAA.B TODO of type float64
	fmt.Printf("a1, a1.b, b1, string(b1), e1:	%v	%v	%v	%v	%v\n", a1, a1.b, b1, string(b1), e1)

	a1 = AAA{}
	b1 = []uint8("{\"A\":   \"111\"}") // Using " instead of ` then escaping ": \"
	e1 = json.Unmarshal(b1, &a1)
	fmt.Printf("a1, a1.A, b1, string(b1), e1:	%v	%v	%v	%v	%v\n", a1, a1.A, b1, string(b1), e1)

	a1 = AAA{
		a: 1111,
		A: "The-String",
		b: false,
		B: 6.64,
		C: "CCCC",
		D: "DDDD",
	}
	a2 := AAA{}
	a3 := AAA{}
	a1Marsh, _ := json.Marshal(a1)
	b1 = []byte(`{"A":"The-String","B":6.64,"DDD":"DDDD"}`)
	json.Unmarshal(a1Marsh, &a2)
	json.Unmarshal(b1, &a3)
	// fmt.Printf("a1Marsh == b1: %v\n", a1Marsh == b1) // invalid operation: a1Marsh == b1 (slice can only be compared to nil)
	fmt.Printf("a2 == a3, a2, a3:	%v	%v	%v\n", a2 == a3, a2, a3)

	a1 = AAA{}
	b1 = []uint8("{\"D\":   \"STRING\"}")
	e1 = json.Unmarshal(b1, &a1) // D is not unmarshaled, it must be DDD!
	fmt.Printf("a1, a1.D, b1, string(b1), e1:	%v	%v	%v	%v	%v\n", a1, a1.D, b1, string(b1), e1)

	a1 = AAA{}
	b1 = []uint8("{\"DDD\":   \"STRING\"}")
	e1 = json.Unmarshal(b1, &a1) // DDD is not unmarshaled!
	fmt.Printf("a1, a1.D, b1, string(b1), e1:	%v	%v	%v	%v	%v\n", a1, a1.D, b1, string(b1), e1)
	// fmt.Printf("a1, a1.D, b1, string(b1), e1:	%v	%v	%v	%v	%v\n", a1, a1.DDD, b1, string(b1), e1) // a1.DDD undefined (type AAA has no field or method DDD)

	a1 = AAA{}
	b1 = []uint8("{\"ZZZ\":   \"ZzZ\"}")
	e1 = json.Unmarshal(b1, &a1) // ZZZ is not an attribute(field, value) of AAA while there is no err.
	fmt.Printf("a1, b1, string(b1), e1:	%v	%v	%v	%v\n", a1, b1, string(b1), e1)

	a1 = AAA{}
	b1 = []uint8("{\"DDD\":   \"درود خدا بر تو!\"}")
	e1 = json.Unmarshal(b1, &a1) // DDD contains persian characters.
	fmt.Printf("a1, b1, string(b1), e1:	%v	%v	%v	%v\n", a1, b1, string(b1), e1)
}

func encode() {
	a1 := AAA{
		a: 1111,
		A: "The-String",
		b: false,
		B: 6.64,
		C: "CCCC",
		D: "DDDD",
	}

	json.NewEncoder(os.Stdout).Encode(a1)
}

func decode() {
	a1 := AAA{}
	reader := strings.NewReader("{\"DDD\":	\"ﺩﺭﻭﺩ ﺥﺩﺍ ﺏﺭ ﺕﻭ!\"}")
	json.NewDecoder(reader).Decode(&a1)
	fmt.Printf("a1: %v\n", a1)
}

func main() {
	var a1 foo = 60
	var a2 foo2 = 70
	fmt.Printf("type(a1), a1: %T, %v\n", a1, a1)
	// a2 = a1 // cannot use a1 (type foo) as type foo2 in assignment
	// a2 = int(a1) // This isn't possbile.
	a2 = foo2(a1) // This is possbile.
	fmt.Printf("type(a2), a2: %T, %v\n", a2, a2)

	fmt.Println("------------")

	b := info{"amirphl", 23, weightHeight{75, 177}}
	fmt.Printf("b, &b, &b.firstName: %v	%p	%p\n", b, &b, &b.firstName)

	fmt.Println("------------")

	p1 := Parent{
		a: 1, // different way of initialization. Compare with b.
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
	fmt.Printf("c1 variable `c` overwrites p1 variable `c`:		%v	%v	%v	%v	%v	%v\n", c1.c, &c1.c, p1.c, &p1.c, c1.Parent.c, &c1.Parent.c)
	fmt.Printf("holyshit: p1 == c1.Parent: %v\n", c1.Parent == p1)     // TODO It is compared by value?
	fmt.Printf("holyshit: &p1 == &c1.Parent: %v\n", &c1.Parent == &p1) // TODO It is passed by value?
	fmt.Printf("&p1, &c1.Parent: %p		%p\n", &p1, &c1.Parent)
	p1.do()
	// p1.do(1) // too many arguments in call to p1.do
	// c1.do() // not enough arguments in call to c1.do
	c1.do(1001)
	c1.Parent.do()
	fmt.Printf("p1.do: %v\n", p1.do) // TODO Is the output (ex: 0x480760) the address of the function inside the memory?
	// fmt.Printf("&p1.do: %v\n" , &p1.do) // cannot take the address of p1.do // TODO
	fmt.Printf("c1.do: %v\n", c1.do)
	fmt.Printf("c1.Parent.do: %v\n", c1.Parent.do)
	fmt.Printf("c1.Parent.do, p1.do: %v	%v\n", c1.Parent.do, p1.do)
	// fmt.Printf("c1.Parent.do == p1.do: %v\n", c1.Parent.do == p1.do) // invalid operation: c1.Parent.do == p1.do (func can only be compared to nil)

	fmt.Println("------------")

	p2 := Parent{}
	fmt.Printf("p2 (empty struct): %v\n", p2)

	fmt.Println("------------")

	c2 := &child{}
	fmt.Printf("&child{}: %v	%p	%T\n", c2, c2, c2)
	fmt.Printf("holyshit: &child{}.Parent: %v	%T\n", c2.Parent, c2.Parent) // TODO What does it mean?

	fmt.Println("------------")

	marshaling()

	fmt.Println("------------")

	unmarshaling()

	fmt.Println("------------")

	encode()

	fmt.Println("------------")

	decode()

	fmt.Println("------------")
}
