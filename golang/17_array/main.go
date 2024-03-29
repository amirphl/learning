package main

import "fmt"

// Note: This array is completly a new array and is not a reference to
// the original array in the caller function!
// unlike slice, map, and channel, it's not a reference!
func change(arr [5]byte, index int, newValue byte) {
	fmt.Printf("inside change function: %p \n", &arr)
	arr[index] = newValue
}

// To solve the problem: pass the reference to the array.
func changeByRef(arr *[5]byte, index int, newValue byte) {
	fmt.Printf("inside changeByRef function: %p \n", arr)
	arr[index] = newValue
}

func main() {
	var strs [10]string
	// strs[-1] = "abc" // invalid array index -1 (index must be non-negative)
	// strs[10] = "abc" // invalid array index 10 (out of bounds for 10-element array)
	// strs[0] = 10 // cannot use 10 (type untyped int) as type string in assignment

	fmt.Printf("%T \n", strs)
	fmt.Println(strs)
	fmt.Println(len(strs))
	strs[1] = "amirphl"
	strs[4] = "bbb"
	strs[8] = "dccccd"
	fmt.Println(strs)
	fmt.Println(len(strs))
	fmt.Println("---------")

	b := [5]byte{1, 2, 3, 4, 5}
	b[0] = 255 // No need to cast. It's an untyped constant (255)
	// b[0] = 256 // constant 256 overflows byte
	// b[0] = -1 // constant -1 overflows byte
	// b[0] = byte(-1) // constant -1 overflows byte
	// b[0] = byte(300) // constant 300 overflows byte
	var u int = 254
	// b[1] = u // cannot use u (type int) as type byte in assignment even 254 <= 255
	b[1] = byte(u)
	fmt.Printf("inside main function: %p      %v\n", &b, b)
	change(b, 4, 11)
	fmt.Printf("inside main function: %p      %v\n", &b, b)
	changeByRef(&b, 4, 11)
	fmt.Printf("inside main function: %p      %v\n", &b, b)
}
