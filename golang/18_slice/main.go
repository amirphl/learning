package main

import "fmt"

// notes:
// Slices are actually references.
// appending int, string, ... to slice: copy by value
// appending slice to slice (ex: []string to [][]string): copy by value (underlying array is passed by reference)
// appending occurres at slice[len(slice)] if len(slice) < cap(slice), otherwise, first, the slice is extended (by doubling the cap) then the insertion occurres the same way as before.
// accessing indexes: [0, len(slice) - 1]
/*
var t = make([]float64, 3, 5)
0.0 as default value
First three elements are 0.0
len is 3
cap is 5
The first appended element is stored in the 4'th position
You can access the index 0:2
resize in case of maximum capacity reached
*/
/*
str := "سلام"
str[i] returns the i'th byte of the encoded string in utf8, not the i'th character.
to access byte: str[i]
to access char: string([]rune(salam)[i])
ref: https://stackoverflow.com/questions/15018545/how-to-index-characters-in-a-golang-string
*/
// Be sure to take a look at `extendSliceFromMiddle` and `playWithSlice`.
// This operation `slice[a:b]` doesn't create a new array, but creates a new slice!
// https://stackoverflow.com/questions/38654729/golang-slice-append-vs-assign-performance
/*
uasge of nil slice:
https://stackoverflow.com/questions/30806931/the-zero-value-of-a-slice-is-not-nil
*/

// [p *string, len int, cap int] is passed by value. Pay attention to *string. The underlying array is passed by reference.
// If you change anything of the slice, the real slice will be changed too.
func change(slice []string, index int, newValue string) {
	slice[index] = newValue
}

func playWithSlice() {
	slc := []uint16{1, 2, 3, 4, 5, 6, 7}
	slc1 := slc[1:3]
	slc2 := slc[1:4]
	slc3 := slc[1:]
	slc4 := slc[2:3]
	// invalid slice index: 2 > 1
	// subNewSlice4_ := newSlice[2:1]
	slc5 := slc[2:]
	slc6 := slc[:]
	fmt.Printf("&slc      : %p\n", &slc)
	fmt.Printf(" slc      len = %d, cap = %d\n", len(slc), cap(slc))
	fmt.Printf("&slc[1:3] : %p\n", &slc1)
	fmt.Printf(" slc[1:3] len = %d, cap = %d\n", len(slc1), cap(slc1))
	fmt.Printf("&slc[1:4] : %p\n", &slc2)
	fmt.Printf(" slc[1:4] len = %d, cap = %d\n", len(slc2), cap(slc2))
	fmt.Printf("&slc[1:]  : %p\n", &slc3)
	fmt.Printf(" slc[1:]  len = %d, cap = %d\n", len(slc3), cap(slc3))
	fmt.Printf("&slc[2:3] : %p\n", &slc4)
	fmt.Printf(" slc[2:3] len = %d, cap = %d\n", len(slc4), cap(slc4))
	fmt.Printf("&slc[2:]  : %p\n", &slc5)
	fmt.Printf(" slc[2:]  len = %d, cap = %d\n", len(slc5), cap(slc5))
	fmt.Printf("&slc[:]   : %p\n", &slc6)
	fmt.Printf(" slc[:]   len = %d, cap = %d\n", len(slc6), cap(slc6))
	fmt.Printf("*****  before changing slc1: %v\n", slc)
	slc1[0] = 1000
	// slc1[7] = 300 // runtime error: index out of range [7] with length 2
	fmt.Printf("*****  after  changing slc1 (slc1[0] = 1000): %v\n", slc)
	fmt.Printf("*****  &slc == &slc[:]: %v\n", &slc == &slc6) // ***** This is reasonable: two pointers stored in different places but refer to the same datastructure.
}

// Take a look at outputs carefully!
func extendSliceFromMiddle() {
	fmt.Println("extending slice from middle:")
	slc := []byte{1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15}
	slc2 := slc[3:10]
	fmt.Println(slc)
	fmt.Printf("%T     %v\n", slc2, slc2)
	slc2[3] = 1
	slc2[4] = 1
	slc2[5] = 1
	fmt.Println(slc)
	fmt.Printf("%T     %v\n", slc2, slc2)
	slc2 = append(slc2, 36, 34)
	fmt.Println(slc)
	fmt.Printf("%T     %v\n", slc2, slc2)
	slc2 = append(slc2, 100, 100, 100, 99, 88, 78, 68) // TODO no effect on slc
	fmt.Println(slc)
	fmt.Printf("%T     %v\n", slc2, slc2)
	slc = append(slc, 222, 222, 222)
	fmt.Println(slc)
	fmt.Printf("%T     %v\n", slc2, slc2)
	// TODO How an array can be extended from the middle?
}

func multiDimSliceExample() {
	var multi = make([][]float64, 10) // []float64{} as default value

	for i := 2; i < 5; i++ {
		temp := []float64{}
		fmt.Printf("before `append` operations: %p \n", &temp) // A
		for j := 3; j < 6; j++ {
			temp = append(temp, float64(i*j))
		}
		fmt.Printf("after  `append` operations: %p \n", &temp) // B
		multi = append(multi, temp)
		fmt.Printf("after appending to 2D slice: %p \n", &multi[len(multi)-1]) // C
		temp[1] = 100000
		// ***** A == B != C
	}

	/*
		// uncomment to see the difference.
		counter := 0
		for i := 2; i < 5; i++ {
			for j := 3; j < 6; j++ {
				multi[counter] = append(multi[counter], float64(i*j))
			}
			counter++
		}
	*/

	var t = make([]float64, 3, 5) // 0.0 as default value // First three elements are 0.0 // len is 3 // cap is 5 // The first appended element is stored in the 4'th position. // You can access the index 0:2 // resize in case of maximum capacity reached
	t = append(t, 1.0, -1.0)
	multi = append(multi, t)

	fmt.Printf("This is a multi-dim array: %v\n", multi)
}

func main() {
	emptySlice := []string{}
	// cannot use 1 (type untyped int) as type string in slice literal
	// cannot use 2 (type untyped int) as type string in slice literal
	// slice := []string{1, "hello", 2, "bye"}
	slice := []string{"hello", "bye", "a", "c", "ccc"}
	fmt.Printf("empty slice: %v\n", emptySlice)
	fmt.Printf("string slice type: %T\n", emptySlice)
	fmt.Printf("non-empty slice: %v\n", slice)

	fmt.Println("--------------------")

	// invalid slice index -1 (index must be non-negative)
	// fmt.Printf("non-empty slice[-1]: %v\n", slice[-1])
	// untime error: index out of range [5] with length 5
	// fmt.Printf("non-empty slice[5]: %v\n", slice[5])
	// runtime error: slice bounds out of range [:10] with capacity 5
	// fmt.Printf("non-empty slice[0:10]: %v\n", slice[0:10])
	fmt.Printf("non-empty slice[0:5]: %v\n", slice[0:5])
	fmt.Printf("non-empty slice[0:1]: %v\n", slice[0:1])
	fmt.Printf("non-empty slice[0:0]: %v\n", slice[0:0])
	// invalid slice index -1 (index must be non-negative)
	// fmt.Printf("non-empty slice[0:-1]: %v\n", slice[0:-1])
	// invalid slice index -4 (index must be non-negative)
	// fmt.Printf("non-empty slice[-4:-2]: %v\n", slice[-4:-2])

	fmt.Println("--------------------")

	fmt.Printf("len(non-empty slice): %v\n", len(slice))
	fmt.Printf("cap(non-empty slice): %v\n", cap(slice))
	slice = append(slice, "!!!")
	fmt.Printf("len(non-empty slice) after appending an element: %v\n", len(slice))
	fmt.Printf("cap(non-empty slice) after appending an element: ***** %v\n", cap(slice))

	fmt.Println("--------------------")

	// first argument to append must be slice; have untyped string
	// str := append("---", slice)
	// first argument to append must be slice; have untyped string
	// str := append("---", []byte{1, 2})
	// cannot use []byte{...} (type []byte) as type byte in append
	// str := append([]byte("---"), []byte{1, 2})
	str := append([]byte("---"), 1)
	fmt.Printf("append byte to str: %v \n", str)
	// first argument to append must be slice; have untyped string
	// str := append("---", 1)

	fmt.Println("--------------------")

	fmt.Printf("slice before passing to function to change: %v \n", slice)
	change(slice, len(slice)-1, "I-have-changed")
	fmt.Printf("slice after passing to function to change: %v \n", slice)

	fmt.Println("--------------------")

	makeSlice := make([]int32, 5, 9)
	newSlice := new([11]int32)[0:4]
	fmt.Printf("slice created with `make` keyword: %T, %d, %d, %v\n", makeSlice, len(makeSlice), cap(makeSlice), makeSlice)
	fmt.Printf("slice created with `new`  keyword: %T, %d, %d, %v\n", newSlice, len(newSlice), cap(newSlice), newSlice) // TODO Why cap == 11?
	makeSlice = append(makeSlice, 100)
	newSlice = append(newSlice, 101)
	fmt.Printf("slice created with `make` keyword after appending an element: %T, %d, %d, %v\n", makeSlice, len(makeSlice), cap(makeSlice), makeSlice)
	fmt.Printf("slice created with `new`  keyword after appending an element: %T, %d, %d, %v\n", newSlice, len(newSlice), cap(newSlice), newSlice)

	fmt.Println("--------------------")

	salam := "سلام"
	// To access bytes:
	fmt.Printf("`سلام`[:1]:\n%v\n", salam[:1])
	fmt.Printf("`سلام`[:2]:\n%v\n", salam[:2])
	fmt.Printf("`سلام`[:3]:\n%v\n", salam[:3])
	fmt.Printf("`سلام`[:4]:\n%v\n", salam[:4])
	// To access characters:
	fmt.Printf("`سلام`[:1]:\n%s\n", string([]rune(salam)[:1]))
	fmt.Printf("`سلام`[:2]:\n%s\n", string([]rune(salam)[:2]))
	fmt.Printf("`سلام`[:3]:\n%s\n", string([]rune(salam)[:3]))
	fmt.Printf("`سلام`[:4]:\n%s\n", string([]rune(salam)[:4]))

	fmt.Println("--------------------")
	// len = cap = 3
	capLen3 := make([]rune, 3)
	fmt.Printf("cap = len = 3: %v \n", capLen3)

	fmt.Println("--------------------")

	playWithSlice()
	fmt.Println("--------------------")
	extendSliceFromMiddle()
	fmt.Println("--------------------")
	multiDimSliceExample()

	fmt.Println("--------------------")

	var appendedSlices = append([]byte{1, 2, 3}, []byte{4, 6, 0}...)
	fmt.Printf("appending two slices: %v\n", appendedSlices)

	fmt.Println("--------------------")

	var test = make([]int, 3, 4)
	// var test = []int{}
	for i := 10; i < 100; i++ {
		test = append(test, i)
		fmt.Printf("len = %v,, cap = %v\n", len(test), cap(test))
	}
	fmt.Printf("test array: %v\n", test)

	fmt.Println("--------------------")
	var s1 []byte            // len = cap = 0, no index yet, underlying array is not allocated yet.
	var s2 = []byte{}        // len = cap = 0, no index yet
	var s3 = []byte{1}       // len = cap = 1, index 0 is accessible
	var s4 = make([]byte, 0) // same as s2
	var s5 = make([]byte, 1) // same as s3
	s6 := []byte{}           // same as s2
	s7 := []byte{1}          // same as s3
	s8 := make([]byte, 0)    // same as s2
	s9 := make([]byte, 1)    // same as s3
	fmt.Printf("s1 = %v      s1 == nil: %v\n", s1, s1 == nil)
	fmt.Printf("s2 = %v      s2 == nil: %v\n", s2, s2 == nil)
	fmt.Printf("s3 = %v      s3 == nil: %v\n", s3, s3 == nil)
	fmt.Printf("s4 = %v      s4 == nil: %v\n", s4, s4 == nil)
	fmt.Printf("s5 = %v      s5 == nil: %v\n", s5, s5 == nil)
	fmt.Printf("s6 = %v      s6 == nil: %v\n", s6, s6 == nil)
	fmt.Printf("s7 = %v      s7 == nil: %v\n", s7, s7 == nil)
	fmt.Printf("s8 = %v      s8 == nil: %v\n", s8, s8 == nil)
	fmt.Printf("s9 = %v      s9 == nil: %v\n", s9, s9 == nil)
	// s1[0] = 100 // runtime error: index out of range [0] with length 0
	// s2[0] = 100 // runtime error: index out of range [0] with length 0
	s3[0] = 100
	// s4[0] = 100 // runtime error: index out of range [0] with length 0
	s5[0] = 100
	// s6[0] = 100 // runtime error: index out of range [0] with length 0
	s7[0] = 100
	// s8[0] = 100 // runtime error: index out of range [0] with length 0
	s9[0] = 100
	fmt.Printf("s1: %v\n", s1)
	fmt.Printf("s2: %v\n", s2)
	fmt.Printf("s3: %v\n", s3)
	fmt.Printf("s4: %v\n", s4)
	fmt.Printf("s5: %v\n", s5)
	fmt.Printf("s6: %v\n", s6)
	fmt.Printf("s7: %v\n", s7)
	fmt.Printf("s8: %v\n", s8)
	fmt.Printf("s9: %v\n", s9)

	fmt.Println("--------------------")

	ss := []byte{0}
	ss[0] = 10
	ss[0]++
	ss[0] += 2
	ss[0] = ss[0] + 3
	fmt.Printf("ss ++ += =      : %v\n", ss)

	fmt.Println("--------------------")

	// ss2 := make([]byte, 100, 20) // len larger than cap in make([]byte)
	// fmt.Println("--------------------")
	// ss2 := make([]byte, 20, 100)
	// ss2[35] = 100 // runtime error: index out of range [35] with length 20

	fmt.Println("--------------------")

	ss2 := make([]byte, 5, 10)
	fmt.Printf("before append: %v\n", ss2)
	ss2 = append(ss2, 101)
	fmt.Printf("after  append: %v\n", ss2)

	fmt.Println("--------------------")
}
