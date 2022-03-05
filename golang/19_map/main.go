package main

import (
	"bufio"
	"fmt"
	"log"
	"net/http"
    "io/ioutil"
)

func makeHttpReq() {
	res, err := http.Get("http://www-01.sil.org/linguistics/wordlists/english/wordlist/wordsEn.txt")

	if err != nil {
		log.Fatal(err)
	}

	bs, _ := ioutil.ReadAll(res.Body)
	str := string(bs)
	fmt.Printf("wordsBn: %v\n", str)
}

func makeHashTable() {
	fmt.Printf("type of salam[1]: %T\n", "salam"[1]) // TODO
	fmt.Printf("type of rune(salam[1]): %T\n", rune("salam"[1]))
	fmt.Printf("type of سلام[1]: %T\n", "سلام"[1]) // TODO
	fmt.Printf("type of rune(سلام[1]): %T\n", rune("سلام"[1]))

	res, err := http.Get("http://www.gutenberg.org/files/2701/old/moby10b.txt")

	if err != nil {
		log.Fatal(err)
	}

	defer res.Body.Close()

	scanner := bufio.NewScanner(res.Body)
	scanner.Split(bufio.ScanWords)
	buckets1 := make([]int, 200)
	buckets2 := make([]int, 12)
	buckets3 := make([]int, 15)
	buckets4 := make([][]string, 100) // buckets4[i] is empty and is not nil, so we are able to do `buckets4[i] = append(buckets4[i], someStuff)`
	// buckets4[i][0] produces runtime error: index out of range [0] with length 0
	buckets5 := make(map[int]map[string]int) // inner maps are nil!!

	for i := 0; i < 100; i++ {
		buckets5[i] = make(map[string]int)
	}

	hashFunc1 := func(str string) int {
		return int(str[0])
	}

	hashFunc2 := func(str string, buckets []int) int {
		return int(str[0]) % len(buckets)
	}

	hashFunc3 := func(str string, buckets []int) int {
		sum := 0

		for _, v := range str {
			sum += int(v)
		}

		return sum % len(buckets)
	}

	hashFunc4 := func(str string, buckets [][]string) int {
		sum := 0

		for _, v := range str {
			sum += int(v)
		}

		return sum % len(buckets)
	}

	for scanner.Scan() {
		str := scanner.Text()
		buckets1[hashFunc1(str)]++
		buckets2[hashFunc2(str, buckets2)]++
		buckets3[hashFunc3(str, buckets3)]++
		n := hashFunc4(str, buckets4)
		buckets4[n] = append(buckets4[n], str)
		buckets5[n][str]++
	}

	fmt.Printf("buckets1: %v\n", buckets1)
	fmt.Printf("buckets2: %v\n", buckets2)
	fmt.Printf("buckets3: %v\n", buckets3)
	fmt.Printf("len(buckets4): %v\n", len(buckets4))
	fmt.Printf("cap(buckets4): %v\n", cap(buckets4))

	for i, innerBuck := range buckets4 {
		fmt.Printf("len(buckets4[%d]), cap(buckets4[%d]): %v    %v\n", i, i, len(innerBuck), cap(innerBuck))
	}

	fmt.Printf("buckets5[49]: %v\n", buckets5[49])
}

func main() {
	// There is no function like `append` for map.

	// nil map

	var a map[int]string
	fmt.Printf("a: %v\n", a)
	fmt.Printf("a == nil: %v\n", a == nil)
	// a[5] = "salam" // assignment to entry in nil map
	delete(a, 5) // a is nil but it still works
	fmt.Println("----------------------")

	// empty map

	// var b map[int]int = map[int]int{}
	var b = map[int]int{}
	fmt.Printf("b: %v\n", b)
	fmt.Printf("b == nil: %v\n", b == nil)
	fmt.Printf("***** (default value test) b[5]: %v\n", b[5])
	b[5] = 5
	fmt.Printf("(after adding 5:5) b[5]: %v\n", b[5])
	fmt.Printf("(after adding 5:5) b: %v\n", b)
	b[5] = 6
	fmt.Printf("(after adding 5:6) b: %v\n", b)
	delete(b, 5)
	fmt.Printf("(after deleting key 5) b: %v\n", b)
	delete(b, 5)
	fmt.Printf("(after deleting key 5 again) b: %v\n", b)
	fmt.Println("----------------------")

	// composite-literal map

	var c = map[float64]float64{
		4.6:   -1,
		100.5: 0.6,
		0:     2,
	}
	fmt.Printf("address of c: %p\n", &c)
	fmt.Println("----------------------")

	// d := map[rune]int16 // expected expression
	d := map[rune]int16{}
	fmt.Printf("d: %v\n", d)
	fmt.Printf("***** d[3]: %v\n", d[3])
	fmt.Println("----------------------")

	// create map using `make`

	e := make(map[int32]bool, 5)
	fmt.Printf("e: %v\n", e)
	val, exists := e[100]
	fmt.Printf("e{100]: val, exists: %v, %v\n", val, exists) // very important: Although the map doesn't contain key 100, it returns false as the default value (the value type is bool).
	// another note: we didn't use var while it returns default value.
	fmt.Println("----------------------")

	// map capacity
	// Most of the time, setting initial capacity is not necessary. Golang can handle it.

	f := make(map[int8]int8, 3) // initial capacity // It should be tuned well!
	for i := 0; i < 10; i++ {
		f[int8(i+11)] = int8(i)
		// fmt.Printf("cap(f): %v\n", cap(f)) // invalid argument f (type map[int8]int8) for cap
		fmt.Printf("f, len(f): %v   %v\n", f, len(f))
	}
	fmt.Println("----------------------")

	// fetching value from the map

	value, ex := f[0]
	value2 := f[0]
	fmt.Printf("value, ex, value2: %v  %v  %v\n", value, ex, value2)
	fmt.Println("----------------------")

	// iterate over map

	fmt.Println("iterating over f:")
	for k, value := range f { // variable shadowing :))
		fmt.Printf("key, value: %v    %v\n", k, value)
	}
	fmt.Println("----------------------")

	// f18 := delete(f, 18) // delete(f, 18) used as value

	makeHashTable()
	fmt.Println("----------------------")
	makeHttpReq()
	fmt.Println("----------------------")
}
