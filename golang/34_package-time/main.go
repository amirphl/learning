package main

import (
	"fmt"
	"time"
)

func main() {
	fmt.Println(time.Now())
	fmt.Println(time.Parse("YY-MM-DD", "2022 10 14"))
}
