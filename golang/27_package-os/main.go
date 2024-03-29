package main

import (
	"fmt"
	"io"
	"os"
)

// Always remember to close the file

// os Args
func getArg() {
	fmt.Println("get arg")
	arg := os.Args[1]
	fmt.Println(arg)
	fmt.Println("----------")
}

// os Open Create Read Write
func readFromWriteTo() {
	fmt.Println("read src.txt then write into dst.txt")

	src, err := os.Open("src.txt")
	if err != nil {
		panic(err)
	}
	defer src.Close()

	dst, err := os.Create("dst.txt")
	if err != nil {
		panic(err)
	}
	defer dst.Close()

	bs := make([]byte, 10)
	src.Read(bs)
	dst.Write(bs)
	ret, err := dst.Write([]byte("This is another message"))
	if err != nil {
		panic(err)
	}
	fmt.Println(ret)
	fmt.Println("----------")
}

// os ModeDir, ModeAppend, ModeSetgid

const (
	ModeDir = 1 << (32 - 1 - iota)
	ModeAppend
	ModeExclusive
	ModeTemporary
	ModeSymlink
	ModeDevice
	ModeNamedPipe
	ModeSocket
	ModeSetuid
	ModeSetgid
	ModeCharDevice
	ModeSticky
)

func printModes() {
	fmt.Println("ModeDir         - ", ModeDir)
	fmt.Println("ModeAppend      - ", ModeAppend)
	fmt.Println("ModeExclusive   - ", ModeExclusive)
	fmt.Println("ModeTemporary   - ", ModeTemporary)
	fmt.Println("ModeSymlink     - ", ModeSymlink)
	fmt.Println("ModeDevice      - ", ModeDevice)
	fmt.Println("ModeNamedPipe   - ", ModeNamedPipe)
	fmt.Println("ModeSocket      - ", ModeSocket)
	fmt.Println("ModeSetuid      - ", ModeSetuid)
	fmt.Println("ModeSetgid      - ", ModeSetgid)
	fmt.Println("ModeCharDevice  - ", ModeCharDevice)
	fmt.Println("ModeSticky      - ", ModeSticky)

	//decimal (base 10)
	fmt.Printf("ModeDir         - %d\n", ModeDir)
	fmt.Printf("ModeAppend      - %d\n", ModeAppend)
	fmt.Printf("ModeExclusive   - %d\n", ModeExclusive)
	fmt.Printf("ModeTemporary   - %d\n", ModeTemporary)
	fmt.Printf("ModeSymlink     - %d\n", ModeSymlink)
	fmt.Printf("ModeDevice      - %d\n", ModeDevice)
	fmt.Printf("ModeNamedPipe   - %d\n", ModeNamedPipe)
	fmt.Printf("ModeSocket      - %d\n", ModeSocket)
	fmt.Printf("ModeSetuid      - %d\n", ModeSetuid)
	fmt.Printf("ModeSetgid      - %d\n", ModeSetgid)
	fmt.Printf("ModeCharDevice  - %d\n", ModeCharDevice)
	fmt.Printf("ModeSticky      - %d\n", ModeSticky)

	//binary (base 2)
	fmt.Printf("ModeDir         - %b\n", ModeDir)
	fmt.Printf("ModeAppend      - %b\n", ModeAppend)
	fmt.Printf("ModeExclusive   - %b\n", ModeExclusive)
	fmt.Printf("ModeTemporary   - %b\n", ModeTemporary)
	fmt.Printf("ModeSymlink     - %b\n", ModeSymlink)
	fmt.Printf("ModeDevice      - %b\n", ModeDevice)
	fmt.Printf("ModeNamedPipe   - %b\n", ModeNamedPipe)
	fmt.Printf("ModeSocket      - %b\n", ModeSocket)
	fmt.Printf("ModeSetuid      - %b\n", ModeSetuid)
	fmt.Printf("ModeSetgid      - %b\n", ModeSetgid)
	fmt.Printf("ModeCharDevice  - %b\n", ModeCharDevice)
	fmt.Printf("ModeSticky      - %b\n", ModeSticky)

	//hexadecimal (base 16)
	fmt.Printf("ModeDir         - %x\n", ModeDir)
	fmt.Printf("ModeAppend      - %x\n", ModeAppend)
	fmt.Printf("ModeExclusive   - %x\n", ModeExclusive)
	fmt.Printf("ModeTemporary   - %x\n", ModeTemporary)
	fmt.Printf("ModeSymlink     - %x\n", ModeSymlink)
	fmt.Printf("ModeDevice      - %x\n", ModeDevice)
	fmt.Printf("ModeNamedPipe   - %x\n", ModeNamedPipe)
	fmt.Printf("ModeSocket      - %x\n", ModeSocket)
	fmt.Printf("ModeSetuid      - %x\n", ModeSetuid)
	fmt.Printf("ModeSetgid      - %x\n", ModeSetgid)
	fmt.Printf("ModeCharDevice  - %x\n", ModeCharDevice)
	fmt.Printf("ModeSticky      - %x\n", ModeSticky)
	fmt.Println("----------")
}

// io/ioutil ReadAll

func readFileWriteStdout() {
	fmt.Println("read src.txt write into stdout")
	src, _ := os.Open("src.txt")
	defer src.Close()
	io.Copy(os.Stdout, src)
	// io.Copy(dst, src)
	fmt.Println("----------")
}

func main() {
	// getArg()
	// readFromWriteTo()
	// printModes()
	readFileWriteStdout()
}
