package main

import (
	"bufio"
	"fmt"
	"io"
	"io/ioutil"
	"os"
	"strings"
)

func main() {
	fmt.Println(">>> phase 1: buffered reader from file, copy to file")
	src, err := os.Open("src.txt")
	if err != nil {
		panic(err)
	}
	defer src.Close()

	br := bufio.NewReader(src)

	dst, err := os.Create("dst.txt")
	if err != nil {
		panic(err)
	}
	defer dst.Close()

	_, err = io.Copy(dst, br)
	if err != nil {
		panic(err)
	}

	fmt.Println(">>> phase 2: scan lines from file")

	src.Seek(0, io.SeekStart)
	scanner := bufio.NewScanner(src)
	for scanner.Scan() {
		fmt.Println(scanner.Text())
	}

	if err := scanner.Err(); err != nil {
		fmt.Fprintln(os.Stderr, "error in scanning: ", err)
	}

	fmt.Println(">>> phase 3: scan words from file")

	src.Seek(0, io.SeekStart)
	secScanner := bufio.NewScanner(src)
	secScanner.Split(bufio.ScanWords)
	for secScanner.Scan() {
		word := secScanner.Text()
		fmt.Printf("%s ", word)
	}
	fmt.Println()

	fmt.Println(">>> phase 4: scan letters from string")

	str := "Now is the winter of our discontent,\nMade glorious summer by this sun of York.\n"
	thrdScanner := bufio.NewScanner(strings.NewReader(str))
	thrdScanner.Split(bufio.ScanRunes)
	countChars := 0
	for thrdScanner.Scan() {
		countChars++
	}
	fmt.Printf("number of characters in the string: %d    %d\n", countChars, len(str))

	fmt.Println(">>> phase 5: buffered reader from string, copy to file")
	rdr := strings.NewReader("\n\nphase 5\n\n")
	io.Copy(dst, rdr)
	rdr = strings.NewReader(str)
	io.Copy(dst, rdr)
	// io.Copy(dst, src)
	// io.Copy(os.Stdout, rdr)
	// io.Copy(os.Stderr, rdr)

	fmt.Println(">>> phase 6: TeeReader")

	src1, err := os.Open("src1.txt")
	if err != nil {
		panic(err)
	}
	// br = bufio.NewReader(src1)

	dst1, err := os.Create("dst1.txt")
	if err != nil {
		panic(err)
	}
	defer dst1.Close()

	dst2, err := os.Create("dst2.txt")
	if err != nil {
		panic(err)
	}
	defer dst2.Close()

	// TODO
	// bufio.Reader vs io.Reader
	// br = io.TeeReader(br, dst1)
	ior := io.TeeReader(src1, dst1)
	ior = io.TeeReader(ior, os.Stdout)
	io.Copy(dst2, ior)

	fmt.Println(">>> phase 7: ReadFull")

	src1.Seek(0, io.SeekStart)
	bf := make([]byte, 100, 200)
	io.ReadFull(src1, bf)
	fmt.Printf("%v\n", bf)
	fmt.Printf("%s\n", string(bf))
	dst2.Write([]byte("\n\nphase7\n\n"))
	dst2.Write(bf)
	// Look at last char (f) as byte and char in the output to see encoding of utf8 and ascii

	fmt.Println(">>> phase 8: LimitRead, WriteString")

	src1.Seek(0, io.SeekStart)
	ior = io.LimitReader(src1, 100)
	ior.Read(bf)
	fmt.Printf("%v\n", bf)
	fmt.Printf("%s\n", string(bf))
	dst2.Write([]byte("\n\nphase8\n\n"))
	dst2.Write(bf)
	io.WriteString(dst2, "\nThis line is written with io.WriteString\n")
	// https://stackoverflow.com/questions/7151261/append-to-a-file-in-go

	fmt.Println(">>> phase 9: ioutil.ReadAll")

	str = "This is a sample"
	rdr = strings.NewReader(str)
	bf, err = ioutil.ReadAll(rdr)
	if err != nil {
		panic(err)
	}
	fmt.Println(bf)
	fmt.Println(string(bf))

	fmt.Println(">>> phase 10: ioutil.WriteFile")

	// second time causes permission denied
	err = ioutil.WriteFile("dst3.txt", []byte("Just a simple content"), 0x777)
	if err != nil {
		panic(err)
	}
}
