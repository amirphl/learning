package main

import "fmt"
import "testing"
import "testing/quick"

func adder(xc ...int) int {
	var s int

	for _, v := range xc {
		s += v
	}

	return s
}

func TestAdder(t *testing.T) {
	res := adder(1, 2, 3)

	if res != 6 {
		t.Fatalf("1 + 2 + 3 != 6 ?\n")
	}
}

/*
func TestAdder2(t *testing.T) {
	res := adder(1, 2, 3)

	if res != 7 {
		t.Fatalf("1 + 2 + 3 != 7 ?\n")
	}
}
*/

func BenchmarkAdder(b *testing.B) {
	fmt.Println("--------")
	for i := 0; i < b.N; i++ {
		adder(4, 5)
	}
}

func TestAdderBlackbox(t *testing.T) {
	err := quick.Check(a, nil)

	if err != nil {
		t.Fatalf("%v\n", err)
	}
}

func a(x, y int) bool {
	return adder(x, y) == x+y
}

func main() {
	fmt.Println(adder(1, 3, 5))
}
