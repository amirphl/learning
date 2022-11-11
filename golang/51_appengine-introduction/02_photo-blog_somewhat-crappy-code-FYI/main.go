package main

import (
	"fmt"
	"html/template"
	"io"
	"log"
	"net/http"
	"os"
	"path/filepath"

	"github.com/gorilla/sessions"
	uuid "github.com/nu7hatch/gouuid"
)

var tpl *template.Template
var cache map[string][]*uuid.UUID = make(map[string][]*uuid.UUID)
var store = sessions.NewCookieStore([]byte("secret-key"))

func init() {
	var err error
	tpl, err = template.ParseFiles("assets/tpl/index.gohtml", "assets/tpl/admin_login.gohtml", "assets/tpl/admin_upload.gohtml")

	if err != nil {
		log.Fatalln(err)
	}

	http.HandleFunc("/", home)
	http.HandleFunc("/admin", admin)
	http.HandleFunc("/admin/upload", upload)
	http.HandleFunc("/admin/logout", logout)
	http.Handle("/assets/imgs/", http.StripPrefix("/assets/imgs/", http.FileServer(http.Dir("./assets/imgs/"))))
}

type Photo struct {
	PhotoPath string
	Lat       float64
	Long      float64
}

type Model struct {
	Photos   []Photo
	LoggedIn bool
}

func home(w http.ResponseWriter, r *http.Request) {
	session, _ := store.Get(r, "session-name")
	model := Model{}
	_, model.LoggedIn = session.Values["loggedin"]

	filepath.Walk("assets/imgs", func(path string, info os.FileInfo, err error) error {
		if !info.IsDir() {
			fmt.Println("Walking", path)
			currentPhoto := Photo{PhotoPath: path}
			_, err := os.Open(path)

			if err != nil {
				log.Fatalln(err)
			}

			model.Photos = append(model.Photos, currentPhoto)
		}
		return nil
	})

	err := tpl.ExecuteTemplate(w, "index.gohtml", model)

	if err != nil {
		http.Error(w, err.Error(), 500)
	}
}

func admin(w http.ResponseWriter, r *http.Request) {
	username := r.FormValue("username")
	password := r.FormValue("password")
	session, _ := store.Get(r, "session-name")
	providedUUID, ok := session.Values["loggedin"]

	if ok {
		uuidList, ok := cache[username]

		if ok {
			for _, i := range uuidList {
				if i != nil && i.String() == providedUUID {
					w.WriteHeader(http.StatusOK)
					break
				}
			}
		}
	}

	if username == "amirphl" && password == "secret-pass" {
		id, _ := uuid.NewV4()
		cache[username] = append(cache[username], id) // security issue: DDOS
		session.Values["loggedin"] = id.String()
		session.Values["username"] = username
		session.Save(r, w)
		http.Redirect(w, r, "/admin/upload", 302)
		return
	}

	tpl.ExecuteTemplate(w, "admin_login.gohtml", nil)
}

func upload(w http.ResponseWriter, r *http.Request) {
	session, _ := store.Get(r, "session-name")
	providedUUID, ok := session.Values["loggedin"]
	username, ok2 := session.Values["username"]

	if !ok || !ok2 {
		http.Redirect(w, r, "/admin", 302)
		return
	}

	uuidList, ok := cache[username.(string)]

	if !ok {
		http.Redirect(w, r, "/admin", 302)
		return
	}

	ok = false
	for _, i := range uuidList {
		if i != nil && i.String() == providedUUID {
			ok = true
			break
		}
	}

	if !ok {
		http.Redirect(w, r, "/admin", 302)
		return
	}

	if r.Method == "POST" {
		src, hdr, err := r.FormFile("file")

		if err != nil {
			log.Fatalln(err)
		}

		defer src.Close()
		fileName := hdr.Filename
		dst, err := os.Create("assets/imgs/" + fileName)

		if err != nil {
			log.Println(err)
			http.Error(w, err.Error(), 500)
			return
		}

		defer dst.Close()
		io.Copy(dst, src)
	}

	tpl.ExecuteTemplate(w, "admin_upload.gohtml", ok)
}

func logout(w http.ResponseWriter, r *http.Request) {
	session, _ := store.Get(r, "session-name")
	delete(session.Values, "loggedin")
	delete(session.Values, "username")
	username, ok := session.Values["username"]
	if ok {
		delete(cache, username.(string))
	}
	session.Save(r, w)
	http.Redirect(w, r, "/admin", 302)
	return
}

func main() {
	http.ListenAndServe(":9000", nil)
}
