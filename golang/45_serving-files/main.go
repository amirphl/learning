package main

import (
	"fmt"
	"io"
	"net/http"
	"os"
	"strings"
)

func h1(w http.ResponseWriter, r *http.Request) {
	w.Header().Add("Content-Type", "text/html; charset=utf-8")
	fs, err := os.Open("./Norman.webp")

	if err != nil {
		w.WriteHeader(http.StatusBadRequest)
		return
	}

	defer fs.Close()
	io.Copy(w, fs)
}

func h2(w http.ResponseWriter, r *http.Request) {
	w.Header().Add("Content-Type", "image/webp") // This is the diff with h1
	fs, err := os.Open("./Norman.webp")

	fmt.Println(strings.Fields(r.URL.Path))

	if err != nil {
		w.WriteHeader(http.StatusBadRequest)
		// http.Error(w, "File not found", 404)
		return
	}

	defer fs.Close()
	io.Copy(w, fs)
}

func h3(w http.ResponseWriter, r *http.Request) {
	// Content-Type is handled by http.ServeContent
	fs, err := os.Open("./Norman.webp")

	if err != nil {
		http.Error(w, "File not found", 404)
		return
	}

	defer fs.Close()

	f, _ := fs.Stat()

	http.ServeContent(w, r, fs.Name(), f.ModTime(), fs)
}

func h4(w http.ResponseWriter, r *http.Request) {
	http.ServeFile(w, r, "No-Norman.webp") // Not found
}

func h5(w http.ResponseWriter, r *http.Request) {
	http.ServeFile(w, r, "Norman.webp") // ServeFile vs ServeContent
}

func main() {
	http.HandleFunc("/Norman1/", h1)
	http.HandleFunc("/Norman2/", h2)
	http.HandleFunc("/Norman3/", h3)
	http.HandleFunc("/Norman4/", h4)
	http.HandleFunc("/Norman5/", h5)
	// http.Handle("/", http.FileServer(http.Dir("../")))
	http.Handle("/assets/", http.StripPrefix("/assets", http.FileServer(http.Dir("../"))))
	// log.Fatal(http.ListenAndServe(":9000", http.FileServer(http.Dir(".")))) // TODO

	http.ListenAndServe(":9000", nil)
}
