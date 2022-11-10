package main

import (
	"fmt"
	"net/http"
)

func main() {
	http.HandleFunc("/", func(w http.ResponseWriter, r *http.Request) {
		w.Header().Set("abc_key", "abc_value")
		w.Header()["ffff_key"] = []string{"111", "222"}

		fmt.Println(r.URL.Host)
		fmt.Println(r.URL.Opaque)
		fmt.Println(r.URL.String())
		fmt.Println(r.URL.Path)
		fmt.Println(r.URL.RawPath)
		fmt.Println(r.URL.EscapedPath())
		fmt.Println(r.URL.RequestURI())
		fmt.Println(r.URL.RawQuery)
		fmt.Println(r.URL.User)
		fmt.Println(r.URL.IsAbs())
		fmt.Println(r.URL.Scheme)
	})

	http.ListenAndServe(":9000", nil)
}
