package main

import (
	"crypto/md5"
	"encoding/base64"
	"encoding/hex"
	"fmt"
	"hash/fnv"
	"io"
	"strings"
)

func main() {
	sr := strings.NewReader("A sample text")
	h1 := fnv.New64()
	io.Copy(h1, sr)
	fmt.Println(h1.Sum64())

	sr.Seek(0, io.SeekStart)
	m1 := md5.New()
	io.Copy(m1, sr)
	fmt.Println(m1.Sum(nil))

	resArr := md5.Sum([]byte("Another sample text"))
	resSli := resArr[:]
	fmt.Println(base64.StdEncoding.EncodeToString(resSli))
	fmt.Println(hex.EncodeToString(resSli))
}
