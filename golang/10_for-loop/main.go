package main

import "fmt"

func main() {
	// for (i := 0; i < 20; i++) { // invalid
	// 0 - 127: ascii
	// 128 - : utf8
	for i := 110; i < 140; i++ { // TODO What is happening for 132?
		fmt.Println(i, 'i', string(i), "---", []byte(string(i)), "---", []int32(string(i)))
	}

	fmt.Printf("\n---------\n")

	i := 10
	for i < 14 {
		if i == 12 {
			break
		}
		for j := 10; j < 14; j++ {
			if j == 11 {
				continue
			}
			fmt.Printf("%d * %d = %d ", i, j, i*j)
		}

		fmt.Println("")
		i++
	}

	fmt.Printf("\n---------\n")

	for {
		if i == 20 {
			break
		}

		fmt.Printf("%d ", i)
		i++
	}

	fmt.Printf("\n---------\n")
	fmt.Printf("\n%T %T\n", []byte(string(i)), []int32(string(i)))

	// cannot convert "i" (type untyped string) to type rune
	// fmt.Println(rune("i"))
	fmt.Printf("\n---------\n")
	fmt.Println([]byte("سلام"), []int32("سلام"))
}
