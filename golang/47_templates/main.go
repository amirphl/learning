package main

import (
	"encoding/csv"
	"fmt"
	"html/template"
	"log"
	"net/http"
	"os"
	"strconv"
	"strings"
)

func serveSimpleTemplate() {
	tpl, err := template.ParseFiles("tpl1.html")

	if err != nil {
		panic(err)
	}

	err = tpl.Execute(os.Stdout, nil)

	if err != nil {
		panic(err)
	}
}

type Page struct {
	Title string
	Body  template.HTML
	Extra string
}

func addFuncs(tpl *template.Template) {
	tpl.Funcs(template.FuncMap{
		"uppercase": func(in string) string {
			return strings.ToUpper(in)
		},
	})
}

func serveTemplateWithFields() {
	tpl := template.New("tpl2.gohtml")
	addFuncs(tpl)
	tpl, err := tpl.ParseFiles("tpl2.gohtml")

	if err != nil {
		log.Fatalln(err)
	}

	http.HandleFunc("/", func(w http.ResponseWriter, r *http.Request) {
		// concurrent access issue
		e := tpl.Execute(w, Page{
			Title: "How to get rid of it?",
			Body:  template.HTML(`No way. <script>alert("Pray the God for forgiveness.")</script>`),
			Extra: "Nothing more.",
		})

		if e != nil {
			log.Fatalln(err)
		}
	})

	http.ListenAndServe(":9000", nil)
}

func serveTwoTpl() {
	var err error
	var tpl *template.Template = template.New("tpl2.gohtml")
	addFuncs(tpl)
	// tpl, err = tpl.ParseFiles("tpl2.gohtml", "tpl3.gohtml")
	tpl, err = tpl.ParseGlob("./*.gohtml") // Like above

	if err != nil {
		log.Fatalln(err)
	}

	err = tpl.Execute(os.Stdout, Page{
		Title: "The title",
		Body:  template.HTML("The body"),
		Extra: "extra",
	})

	if err != nil {
		log.Fatalln(err)
	}

	fmt.Println("-------------------")

	err = tpl.ExecuteTemplate(os.Stdout, "tpl3.gohtml", Page{
		Title: "second title",
		Body:  "second body",
	})

	if err != nil {
		log.Fatalln(err)
	}
}

func tplWithEmptyDot() {
	tpl := template.New("tpl4.gohtml")
	tpl, err := tpl.ParseFiles("tpl4.gohtml")

	if err != nil {
		panic(err)
	}

	// err = tpl.Execute(os.Stdout, 1234)
	// err = tpl.Execute(os.Stdout, []int{100, 345, 444})
	err = tpl.Execute(os.Stdout, Page{Extra: "Just extra!"})

	if err != nil {
		panic(err)
	}
}

func fillTplWithCSV() {
	f, err := os.Open("state_table.csv")

	if err != nil {
		panic(err)
	}

	defer f.Close()

	rows, err := csv.NewReader(f).ReadAll()

	if err != nil {
		panic(err)
	}

	type Record struct {
		Name          string
		Circuit_court int64
	}

	records := make([]Record, 0, len(rows))

	for _, row := range rows {
		name := row[1]
		circuit_court, _ := strconv.ParseInt(row[16], 10, 32)
		records = append(records, Record{name, circuit_court})
	}

	tpl, err := template.ParseFiles("tpl5.gohtml")

	if err != nil {
		panic(err)
	}

	http.HandleFunc("/", func(w http.ResponseWriter, r *http.Request) {
		err = tpl.Execute(w, records)

		if err != nil {
			log.Fatalln(err)
		}
	})

	http.ListenAndServe(":9000", nil)
}

func main() {
	// serveSimpleTemplate()
	// serveTemplateWithFields()
	// serveTwoTpl()
	// tplWithEmptyDot()
	// fillTplWithCSV()
}
