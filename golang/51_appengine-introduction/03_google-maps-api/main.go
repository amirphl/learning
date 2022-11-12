package main

import (
	"html/template"
	"log"
	"net/http"
	"os"

	"github.com/rwcarlsen/goexif/exif"
)

const googleAPIKey = "AIzaSyDpMNCWNz2UENVGQOS6zMFvtLsXn0zMBf4"

var tpls *template.Template

func init() {
	var err error
	tpls, err = template.ParseFiles("assets/tpls/index.gohtml")

	if err != nil {
		log.Fatalln(err)
	}

	http.HandleFunc("/", handleIndex)
}

func handleIndex(w http.ResponseWriter, r *http.Request) {
	src, err := os.Open("assets/imgs/IMG_20150714_191905.jpg")

	if err != nil {
		log.Fatalln(err)
	}

	defer src.Close()
	x, _ := exif.Decode(src)
	lat, long, _ := x.LatLong()

	var model struct {
		Latitude, Longitude float64
		Key                 string
	}

	model.Latitude = lat
	model.Longitude = long
	model.Key = googleAPIKey
	err = tpls.ExecuteTemplate(w, "index.gohtml", model)

	if err != nil {
		http.Error(w, err.Error(), 500)
	}
}

func main() {
	http.ListenAndServe(":9000", nil)
}
