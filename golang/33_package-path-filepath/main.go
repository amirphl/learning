package main

import (
	"fmt"
	"os"
	"path/filepath"
)

func main() {
	filepath.Walk("../", func(path string, info os.FileInfo, err error) error {
		fmt.Println(path, info.Name(), info.Mode(), info.Size(), info.Sys(), info.IsDir())
		return nil
	})
}
