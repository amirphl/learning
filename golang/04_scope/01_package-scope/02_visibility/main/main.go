package main

import (
	"fmt"
	"github.com/amirphl/learning/golang/04_scope/01_package-scope/02_visibility/vis"
)

func main() {
	fmt.Println(vis.MyName)
	// not works: yourName is only accessible inside of the vis package
	// fmt.Println(vis.yourName)
	vis.PrintVar()
}
