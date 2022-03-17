package main

import "fmt"

func main() {
	const (
		a = 1
		b = "str"
		A = 2
		B = "otherstuff"
	)

	const (
		c = iota
		d = iota
		e = iota
	)

	const (
		f = iota
		g
		h
	)

	const (
		i = iota
		j
		_
		k
		l = 5
	)

	const (
		KB     = 1 << (iota * 10)
		MB     = 1 << (iota * 10)
		GB     = 1 << (iota * 10)
		TB     = 1 << (iota * 10)
		Notice = 1 << iota * 10
	)

    // TODO
	const (
		A1 = 2 << (iota * 10)
		A2 = 2 << (iota * 10)
		A3 = 2 << (iota * 10)
		A4 = 2 << (iota * 10)
		A5 = 2 << (iota * 10)
	)

	fmt.Println(a, A, b, B, c, d, e, f, g, h, i, j, k, l)
	fmt.Printf("%d %b, %d %b, %d %b, %d %b, %d %b\n", KB, KB, MB, MB, GB, GB, TB, TB, Notice, Notice)
	fmt.Printf("%d %b, %d %b, %d %b, %d %b, %d %b\n", A1, A1, A2, A2, A3, A3, A4, A4, A5, A5)
}
