package main

import (
	"fmt"
	"io"
	"net/http"
)

type MyHandler1 struct{}

func (h MyHandler1) ServeHTTP(w http.ResponseWriter, r *http.Request) {
	fmt.Println(r.URL.RequestURI())
	fmt.Println(r.URL.Path)
	fmt.Println(r.RequestURI)
	w.Header().Add("Content-Type", "application/json; charset=ascii")
	w.Header().Add("Content-Type", "text/html; charset=utf-8")
	// w.Write([]byte(`{"name": "amir"}`))
	switch r.URL.Path {
	case "/cat":
		io.WriteString(w, `{"name": "میرمحمد"}`)
	case "/dog":
		io.WriteString(w, `{"name": "amir"}`)
	default:
		io.WriteString(w, `{"name": "phl"}`)
	}
}

func main() {
	var mh MyHandler1
	http.ListenAndServe(":9000", mh)
}
