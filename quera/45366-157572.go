// https://quera.org/contest/assignments/45366/problems/157572

package main

import (
	"fmt"
	"math"
)

func main() {
	var a int
	var b int
	var c int
	fmt.Scan(&a)
	fmt.Scan(&b)
	fmt.Scan(&c)
	fmt.Println(a + (a-b)*int(math.Pow(2, float64(c))-1))
}
