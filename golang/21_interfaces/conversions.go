package main

import (
	"fmt"
	"strconv"
)

func main() {
	// var a int
	// a = int(3.14) // constant 3.14 truncated to integer
	// fmt.Printf("a:	%v	%T\n", a, a)

	a1 := 3.14
	a2 := int(a1)
	fmt.Printf("a2:	%v	%T\n", a2, a2)

	var b float64
	b = float64(3)
	fmt.Printf("b:	%v	%T\n", b, b)

	var c float64
	c = float64(3.15)
	fmt.Printf("c:	%v	%T\n", c, c)

	var d []byte
	d = []byte(string('u'))
	fmt.Printf("d:	%v	%T\n", d, d)

	// TODO
	// var e rune
	// e = rune("u") // cannot convert "u" (type untyped string) to type rune
	// fmt.Printf("e:	%v	%T\n", e, e)

	// TODO
	// var f int32
	// f = int32("a") // cannot convert "a" (type untyped string) to type int32
	// fmt.Printf("f:	%v	%T\n", f, f)

	// TODO
	// var g string
	// g = string([]byte(rune(32))) // cannot convert rune(32) (type rune) to type []byte
	// fmt.Printf("g:	%v	%T\n", g, g)

	var g2 rune
	g2 = rune(68)
	fmt.Printf("g2:	%v	%T\n", g2, g2)

	var g3 string
	g3 = string(g2)
	fmt.Printf("g3:	%v	%T\n", g3, g3)

	var h string
	h = string([]byte("salam"))
	fmt.Printf("h:	%v	%T\n", h, h)

	// TODO How `int32` is converted to `unit8`?
	var h2 string
	h2 = string([]byte{'s', 'a', 'l', 'a', 'm'})
	fmt.Printf("h2:	%v	%T\n", h2, h2)

	// Not works.
	// var h3 string
	// h3 = string([]byte{'س', 'ل', 'ا', 'م'})
	// fmt.Printf("h3:	%v	%T\n", h3, h3)

	var h4 string
	h4 = string([]rune{'س', 'ل', 'ا', 'م'})
	fmt.Printf("h4:	%v	%T\n", h4, h4)

	var i interface{}
	i = "I-am-string"
	fmt.Printf("i:	%v	%T\n", i, i)

	var j interface{}
	j = 3.15
	fmt.Printf("j:	%v	%T\n", j, j)

	// var k int
	// k = int(j) // cannot convert j (type interface {}) to type int: need type assertion
	// fmt.Printf("k:	%v	%T\n", k, k)

	// var l int
	// l = j.(int) // panic: interface conversion: interface {} is float64, not int
	// fmt.Printf("l:	%v	%T\n", l, l)

	var l2 float64
	l2 = j.(float64)
	fmt.Printf("l2:	%v	%T\n", l2, l2)

	var m, _ = strconv.Atoi("85")
	fmt.Printf("m:  %v	%T\n", m, m)

	var m2, err = strconv.Atoi("b")
	fmt.Printf("m2, err:	%v	%T	%v\n", m2, m2, err)

	var m3 = strconv.Itoa(85)
	fmt.Printf("m3:	%v	%T\n", m3, m3)

	// TODO precision
	var n float64
	n, err = strconv.ParseFloat("3.14", 32)
	fmt.Printf("n, err:	%v	%T	%v\n", n, n, err)

	var n2 float64
	n2, err = strconv.ParseFloat("3.14", 64)
	fmt.Printf("n2, err:	%v	%T	%v\n", n2, n2, err)

	var n3 string
	n3 = strconv.FormatFloat(3.14, 'E', -1, 32)
	fmt.Printf("n3:	%v	%T\n", n3, n3)

	// invalid type assertion: n3.(string) (non-interface type string on left)
	// if n3.(string) {
	// 	fmt.Println("Ok, n3 is a string!")
	// } else {
	// 	fmt.Println("Oh, n3 isn't a string!")
	// }

	var n4 interface{} = n3
	var _, ok = n4.(string) // interface will be converted to the string.
	if ok {
		fmt.Println("Ok, n4 is a string!")
	} else {
		fmt.Println("Oh, n4 isn't a string!")
	}

	var n5 interface{} = 45
	_, ok = n5.(string)
	if ok {
		fmt.Println("Ok, n5 is a string!")
	} else {
		fmt.Println("Oh, n5 isn't a string!")
	}

	// var n6 interface{} = 66
	// 63 + n6 // invalid operation: 63 + n6 (mismatched types int and interface {})

	var n7 interface{} = 66
	fmt.Printf("n7 + 45:	%v\n", n7.(int)+45)

	// var n8 interface{} = 66
	// fmt.Printf("n8 + 45:	%v\n", int(n8)+45) // cannot convert n8 (type interface {}) to type int: need type assertion
}
