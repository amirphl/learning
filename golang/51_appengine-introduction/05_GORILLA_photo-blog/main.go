package main

import (
	"crypto/sha1"
	"encoding/json"
	"fmt"
	"html/template"
	"io"
	"mime/multipart"
	"net/http"
	"os"
	"path/filepath"

	"github.com/gorilla/context"
	"github.com/gorilla/sessions"
)

var tpl *template.Template
var store = sessions.NewCookieStore([]byte("secret-key"))

func init() {
	tpl, _ = template.ParseGlob("assets/tpls/*.html")
	mux := http.DefaultServeMux
	mux.HandleFunc("/", index)
	mux.HandleFunc("/login", login)
	mux.HandleFunc("/logout", logout)
	mux.Handle("/assets/imgs/", http.StripPrefix("/assets/imgs", http.FileServer(http.Dir("./assets/imgs/"))))
	mux.Handle("/favicon.ico", http.NotFoundHandler())
}

func index(w http.ResponseWriter, r *http.Request) {
	defer context.Clear(r)
	session, _ := store.Get(r, "my-session")

	if session.Values["loggedin"] == "false" || session.Values["loggedin"] == nil {
		http.Redirect(w, r, "/login", 302)
		return
	}

	if r.Method == "POST" {
		src, hdr, err := r.FormFile("data")
		if err == nil {
			uploadPhoto(src, hdr, session)
		}
	}

	session.Save(r, w)
	data := getPhotos(session)
	tpl.ExecuteTemplate(w, "index.html", data)
}

func logout(w http.ResponseWriter, r *http.Request) {
	defer context.Clear(r)
	session, _ := store.Get(r, "my-session")
	session.Values["loggedin"] = "false"
	session.Save(r, w)
	http.Redirect(w, r, "/login", 302)
}

func login(w http.ResponseWriter, r *http.Request) {
	defer context.Clear(r)
	session, _ := store.Get(r, "my-session")
	if r.Method == "POST" && r.FormValue("password") == "secret" {
		session.Values["loggedin"] = "true"
		session.Save(r, w)
		http.Redirect(w, r, "/", 302)
		return
	}

	tpl.ExecuteTemplate(w, "login.html", nil)
}

func uploadPhoto(src multipart.File, hdr *multipart.FileHeader, session *sessions.Session) {
	defer src.Close()
	fName := getSha(src) + ".jpg"
	wd, _ := os.Getwd()
	path := filepath.Join(wd, "assets", "imgs", fName)
	dst, _ := os.Create(path)
	defer dst.Close()
	src.Seek(0, 0)
	io.Copy(dst, src)
	addPhoto(fName, session)
}

func getSha(src multipart.File) string {
	h := sha1.New()
	io.Copy(h, src)
	return fmt.Sprintf("%x", h.Sum(nil))
}

func addPhoto(fName string, session *sessions.Session) {
	data := getPhotos(session)
	data = append(data, fName)
	bs, _ := json.Marshal(data)
	session.Values["data"] = string(bs)
}

func getPhotos(session *sessions.Session) []string {
	var data []string
	jsonData := session.Values["data"]
	if jsonData != nil {
		json.Unmarshal([]byte(jsonData.(string)), &data)
	}
	return data
}

func main() {
	http.ListenAndServe(":9000", nil)
}
