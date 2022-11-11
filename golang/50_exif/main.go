package main

import (
	"fmt"
	"log"
	"os"

	"github.com/rwcarlsen/goexif/exif"
	"github.com/rwcarlsen/goexif/mknote"
)

func main() {
	fname := "Jobagent.tiff"

	f, err := os.Open(fname)

	if err != nil {
		log.Fatalln(err)
	}

	defer f.Close()
	exif.RegisterParsers(mknote.All...)

	x, err := exif.Decode(f)

	if err != nil {
		panic(err)
	}

	camModel, err := x.Get(exif.Model)

	if err != nil {
		log.Fatalln(err)
	}

	fmt.Println(camModel.StringVal())

	focal, _ := x.Get(exif.FocalLength)
	rumer, denom, _ := focal.Rat2(0)
	fmt.Println(rumer, denom)

	tm, _ := x.DateTime()
	fmt.Println(tm)

	lat, long, _ := x.LatLong()
	fmt.Println(lat, long)
}
