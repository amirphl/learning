package main

import (
	"fmt"
	"net/http"
)

type frstHandler struct{}
type thrdHandler struct{}

func (h frstHandler) ServeHTTP(w http.ResponseWriter, r *http.Request) {
	w.Write([]uint8("Frst!"))
}

func scndHandler(w http.ResponseWriter, r *http.Request) {
	w.Write([]uint8("Scnd!"))
}

func (h thrdHandler) ServeHTTP(w http.ResponseWriter, r *http.Request) {
	for k, v := range r.URL.Query() {
		fmt.Printf("%s: %v\n", k, v)
	}

	w.Write([]uint8("Thrd!"))
}

func main() {
	mux := http.NewServeMux() // Read the doc!
	mux.Handle("/", frstHandler{})
	mux.HandleFunc("/2/", scndHandler)
	mux.Handle("/3", thrdHandler{}) // no trailing slash

	http.ListenAndServe(":9000", mux)
}
