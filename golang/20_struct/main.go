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
	hw        weightHeight // It's defined after `info` and there's no problem. // refer to golang `scoping`
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
	Parent // TODO Is this equal to `p Parent` or `Parent Parent` or `parent Parent`? // Is this inheritance?
	d      int
	e      string
	c      int16 // This `c` is unrelated to the `Parent.c`
}

func (p Parent) do() {
	// You could access p fields(state) and methods here.
	// p.do() // **** Uncomment this line and you receive stack overflow!!! You should set the recursion break point to make it work.
	// The `p` is passed by value!
	fmt.Printf("do()  -  parent  -  %v  -  %p\n", p, &p)
}

func (c child) do(x int) {
	fmt.Printf("do(x int)  -  child  -  %v  -  %p  - %v\n", c, &c, x)
}

type AAA struct {
	a int // This field is not exported since it's lowercase so it's not available in marshaling output.
	A string
	b bool
	B float64
	C string `json:"-"`   // Although this field is uppercase but it's not available in marshaling output because of the `-` tag.
	D string `json:"DDD"` // This field is renamed to DDD while marshaling.
}

func marshaling() {
	c1 := child{Parent{1, 1.2, "salam"}, 3, "bye", 4}
	c1Marshaled, err := json.Marshal(c1)
	c1Str := string(c1Marshaled)
	// very important: None of the fields of the c1 are exported (uppercase), so, the result is {}
	fmt.Printf(" c1(marshaled): %v\n type of c1(marshaled): %T\n c1(string) %s\n marshaling error %v\n", c1Marshaled, c1Marshaled, c1Str, err)

	fmt.Println("------------")

	aaa := AAA{1, "salam", true, -3.4, "bye", "hello"}
	aaaMarshaled, aaaMarshErr := json.Marshal(aaa)
	aaaStr := string(aaaMarshaled)
	fmt.Printf(" aaa(marshaled): %v\n type of aaa(marshaled): %T\n aaa(string) %s\n marshaling error %v\n", aaaMarshaled, aaaMarshaled, aaaStr, aaaMarshErr)

	fmt.Println("------------")

	fmt.Println("Filling values of `aaa` with persian words ...")

	aaa = AAA{1, "سلام", true, -3.4, "bye", "خداحافظ"}
	aaaMarshaled, aaaMarshErr = json.Marshal(aaa)
	aaaStr = string(aaaMarshaled)
	fmt.Printf(" aaa(marshaled): %v\n type of aaa(marshaled): %T\n aaa(string) %s\n marshaling error %v\n", aaaMarshaled, aaaMarshaled, aaaStr, aaaMarshErr)
}

func unmarshaling() {
	a1 := AAA{}
	b1 := []uint8(`{"A":   "111"}`) // It can also be []byte // pay attention to extra spaces! It doesn't have any effect! // 111 is passed as a string, not an integer!
	e1 := json.Unmarshal(b1, &a1)
	fmt.Printf(" a1: %v\n a1.A: %v\n b1: %v\n string(b1): %s\n e1: %v\n", a1, a1.A, b1, b1, e1)

	fmt.Println("------------")

	a1 = AAA{}
	b1 = []uint8(`{"B":   "ture"}`)
	e1 = json.Unmarshal(b1, &a1) // json: cannot unmarshal string into Go struct field AAA.B of type float64
	fmt.Printf(" a1: %v\n a1.B: %v\n b1: %v\n string(b1): %s\n e1: %v\n", a1, a1.B, b1, b1, e1)

	fmt.Println("------------")

	a1 = AAA{}
	b1 = []uint8(`{"a":   "222"}`)
	e1 = json.Unmarshal(b1, &a1) // TODO Why a is stored inside A ?!
	fmt.Printf(" a1: %v     (variable A is filled!)\n a1.a: %v\n a1.A: %v\n b1: %v\n string(b1): %s\n e1: %v\n", a1, a1.a, a1.A, b1, b1, e1)

	fmt.Println("------------")

	a1 = AAA{}
	b1 = []byte(`{"b":   "333"}`)
	e1 = json.Unmarshal(b1, &a1) // json: cannot unmarshal string into Go struct field TODO AAA.B TODO of type float64
	fmt.Printf(" a1: %v\n a1.b: %v\n b1: %v\n string(b1): %s\n e1: %v\n", a1, a1.b, b1, b1, e1)

	fmt.Println("------------")

	a1 = AAA{}
	b1 = []uint8("{\"A\":   \"111\"}") // Using " instead of ` then escaping ": \"
	e1 = json.Unmarshal(b1, &a1)
	fmt.Printf(" a1: %v\n a1.A: %v\n b1: %v\n string(b1): %s\n e1: %v\n", a1, a1.A, b1, b1, e1)

	fmt.Println("------------")

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
	fmt.Printf(" a2 == a3 ? %v\n a2: %v\n a3: %v\n", a2 == a3, a2, a3)

	fmt.Println("------------")

	a1 = AAA{}
	b1 = []uint8("{\"D\":   \"STRING\"}")
	e1 = json.Unmarshal(b1, &a1) // D is not unmarshaled, it must be DDD!
	fmt.Printf(" a1: %v\n a1.D: %v\n b1: %v\n string(b1): %s\n e1: %v\n", a1, a1.D, b1, b1, e1)

	fmt.Println("------------")

	a1 = AAA{}
	b1 = []uint8("{\"DDD\":   \"STRING\"}")
	e1 = json.Unmarshal(b1, &a1) // DDD is unmarshaled!
	fmt.Printf(" a1: %v\n a1.D: %v\n b1: %v\n string(b1): %s\n e1: %v\n", a1, a1.D, b1, b1, e1)
	// fmt.Printf("a1, a1.D, b1, string(b1), e1:	%v	%v	%v	%v	%v\n", a1, a1.DDD, b1, string(b1), e1) // a1.DDD undefined (type AAA has no field or method DDD)

	fmt.Println("------------")

	a1 = AAA{}
	b1 = []uint8("{\"ZZZ\":   \"ZzZ\"}")
	e1 = json.Unmarshal(b1, &a1) // ZZZ is not an attribute(field, value) of AAA while there is no err.
	fmt.Printf(" a1: %v\n b1: %v\n string(b1): %s\n e1: %v\n", a1, b1, b1, e1)

	fmt.Println("------------")

	a1 = AAA{}
	b1 = []uint8("{\"DDD\":   \"درود خدا بر تو!\"}")
	e1 = json.Unmarshal(b1, &a1) // DDD contains persian characters.
	fmt.Printf(" a1: %v\n a1.D: %v\n b1: %v\n string(b1): %s\n e1: %v\n", a1, a1.D, b1, b1, e1)
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
	fmt.Printf("b, &b, &b.firstName, &b.age: %v	 %p	 %p  %p\n", b, &b, &(b.firstName), &(b.age))

	fmt.Println("------------")

	p1 := Parent{
		a: 1, // different way of initialization. Compare with b.
		b: 4.3,
		c: "this-is-a-string",
	}

	c1 := child{
		Parent: p1, // Very important: `p1` is copied here.
		d:      8,
		e:      "hell-yeah",
		c:      int16(20000),
	}

	fmt.Printf("p1: %v\n", p1)
	fmt.Printf("c1: %v\n", c1)
	fmt.Printf("%v	%v	%v	%v	%v	%v\n", c1.c, &c1.c, p1.c, &p1.c, c1.Parent.c, &c1.Parent.c)
	fmt.Printf("compare by value:   p1 == c1.Parent: %v\n", c1.Parent == p1)
	fmt.Printf("p1 is copied into c1.Parent in initialization:   &p1 == &c1.Parent: %v\n", &c1.Parent == &p1)

	fmt.Println("------------")

	fmt.Printf("&p1: %p\n", &p1)
	p1.do()
	// p1.do(1) // too many arguments in call to p1.do
	// c1.do() // not enough arguments in call to c1.do
	fmt.Printf("&c1: %p\n", &c1)
	c1.do(1001)
	fmt.Printf("&c1.Parent: %p\n", &c1.Parent)
	c1.Parent.do()

	fmt.Println("------------")

	fmt.Printf("p1.do: %v\n", p1.do) // TODO Is the output (ex: 0x480760) the address of the function inside the memory?
	// fmt.Printf("&p1.do: %v\n" , &p1.do) // cannot take the address of p1.do // TODO
	fmt.Printf("c1.do: %v\n", c1.do)
	fmt.Printf("c1.Parent.do: %v\n", c1.Parent.do)
	fmt.Printf("c1.Parent.do, p1.do: %v	%v\n", c1.Parent.do, p1.do) // Very important: p1 and c1.Parent share the same set of functions although those are different. They don't share the same set of variables.
	// fmt.Printf("c1.Parent.do == p1.do: %v\n", c1.Parent.do == p1.do) // invalid operation: c1.Parent.do == p1.do (func can only be compared to nil)

	fmt.Println("------------")

	p2 := Parent{}
	fmt.Printf("p2 (empty struct): %v\n", p2)

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
