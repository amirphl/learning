package main

import (
	"fmt"
	"github.com/amirphl/learning/golang/02_package/stringutil"
)

func main() {
	fmt.Println(stringutil.Reverse("I am accessible from outside of the package"))
	// *reverse* is not accessible outside of the stringutil package
	// fmt.Println(stringutil.reverse("I am ** not ** accessible from outside of the package"))
	fmt.Println(stringutil.VisibleMyName)
	// *unvisibleMyName* is not accessible outside of the stringutil package
	// fmt.Println(stringutil.unvisibleMyName)
}
