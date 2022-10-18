package main

import (
	"fmt"
	"io"
	"net/http"
)

type MyHandler1 struct{}

func (mh MyHandler1) ServeHTTP(w http.ResponseWriter, req *http.Request) {
	fmt.Println(req.URL.RequestURI())
	fmt.Println(req.URL.Path)
	fmt.Println(req.RequestURI)
	w.Header().Add("Content-Type", "application/json; charset=ascii")
	// res.Write([]byte(`{"name": "amir"}`))
	io.WriteString(w, `{"name": "میرمحمد"}`)
}

func main() {
	var mh MyHandler1
	http.ListenAndServe(":9000", mh)
}
