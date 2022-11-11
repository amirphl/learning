package main

import (
	"fmt"
	"html/template"
	"io"
	"log"
	"net/http"
	"os"
	"strings"
	"time"
)

// curl -v -F 'key_4=@./go.mod' -F key5=value5,value5.1 'localhost:9000?key_1=hello,bye&key_2=this,that"'
// curl -v -F 'key_4=@./go.mod' -F key5=value5,value5.1 'localhost:9000?key_1=hello,bye&key_2=this,that' -d '{"main cast": "rick", "sec cast", "dixon"}'

func passedData() {
	http.HandleFunc("/", func(w http.ResponseWriter, r *http.Request) {
		if r.URL.Query().Has("key_1") {
			fmt.Println(r.URL.Query().Get("key_1"))
			fmt.Println(r.URL.Query()["key_1"])
		}

		fmt.Println("method: ", r.Method)
		fmt.Println("FormValue of key_1: ", r.FormValue("key_1"))
		fmt.Println("FormValue of key_2: ", r.FormValue("key_2"))
		fmt.Println("FormValue of key_5: ", r.FormValue("key_5"))

		file, hdr, err := r.FormFile("key_4")

		if err != nil {
			log.Fatalln(err)
		}

		defer file.Close()
		bs, err := io.ReadAll(file)
		// bs, err := ioutil.ReadAll(file)

		if err != nil {
			log.Fatalln(err)
		}

		str := string(bs)
		fmt.Println("file: ", file)
		fmt.Println("-------------")
		fmt.Printf("hdr:\n%v\n", hdr)
		fmt.Println("-------------")
		fmt.Printf("str:\n%s\n", str)
		fmt.Println("-------------")

		http.ServeContent(w, r, hdr.Filename, time.Now(), file)
	})

	http.ListenAndServe(":9000", nil)
}

func serveUpload() {
	http.HandleFunc("/", func(w http.ResponseWriter, r *http.Request) {
		if r.Method == "POST" {
			f, hdr, err := r.FormFile("my-file")

			if err != nil {
				log.Fatalln(err)
				w.WriteHeader(http.StatusInternalServerError)
				return
			}
			defer f.Close()

			fmt.Println(os.TempDir())
			newFile, err := os.Create(strings.Join([]string{os.TempDir(), hdr.Filename}, "/"))

			if err != nil {
				log.Fatalln(err)
				w.WriteHeader(http.StatusInternalServerError)
				return
			}

			defer newFile.Close()
			src := io.LimitReader(f, 75) // write only first 75 bytes
			// io.Copy(newFile, f) // writing whole file
			io.Copy(newFile, src)
			w.WriteHeader(http.StatusCreated)
		} else if r.Method == "GET" {
			w.Header().Set("Content-Type", "text/html; charset=utf-8")
			tpl := template.New("tpl1.html")
			tpl, err := tpl.ParseFiles("tpl1.html")

			if err != nil {
				log.Fatalln(err)
				panic(err)
			}

			err = tpl.Execute(w, nil)

			if err != nil {
				log.Fatalln(err)
				w.WriteHeader(http.StatusInternalServerError)
				return
			}

			w.WriteHeader(http.StatusOK)
		} else {
			w.WriteHeader(http.StatusMethodNotAllowed)
		}
	})

	http.ListenAndServe(":9000", nil)
}

func main() {
	// passedData()
	serveUpload()
}
