package main

import (
	"crypto/hmac"
	"crypto/sha256"
	"fmt"
	"io"
	"net/http"
	"strconv"
	"strings"
	"time"

	sessions "github.com/gorilla/sessions"
	uuid "github.com/nu7hatch/gouuid"
)

func getCode(data string) string {
	h := hmac.New(sha256.New, []byte("secret key"))
	io.WriteString(h, data)
	return fmt.Sprintf("%x", h.Sum(nil))
}

func setCookie1() {
	http.HandleFunc("/", func(w http.ResponseWriter, r *http.Request) {
		cookie, err := r.Cookie("session-id")

		// if err != nil {
		if err == http.ErrNoCookie {
			id, _ := uuid.NewV4()
			val := id.String() + " email=abc@gmail.com" + " JSON data" + " Whatever"
			hashed := getCode(val)
			fmt.Println("hash of val:", hashed)

			http.SetCookie(w, &http.Cookie{
				Name:  "session-id",
				Value: hashed + "|" + val,
			})
			http.SetCookie(w, &http.Cookie{
				Name:  "my cookie 2", // TODO This doesn't work because of the spaces?
				Value: "This is the value.",
			})
		}

		cookie, err = r.Cookie("num-visits")

		if err == http.ErrNoCookie {
			http.SetCookie(w, &http.Cookie{
				Name:  "num-visits",
				Value: "0",
			})
		} else {
			x, _ := strconv.Atoi(cookie.Value)
			x++
			cookie.Value = strconv.Itoa(x)
			http.SetCookie(w, cookie)
			w.Write([]byte(cookie.Value))
			fmt.Println(cookie)
		}
	})

	http.ListenAndServe(":9000", nil)
}

var store = sessions.NewCookieStore([]byte("secret-password"))

func setCookie2() {
	http.HandleFunc("/", func(w http.ResponseWriter, r *http.Request) {
		session, _ := store.Get(r, "session")
		session.Values["email"] = "abc@gmail.com"
		session.Values["name"] = "amir"

		v, has := session.Values["visits"]
		if has {
			session.Values["visits"] = v.(int) + 1
		} else {
			session.Values["visits"] = 1
		}

		fmt.Println(session)
		session.Save(r, w)
	})
	http.ListenAndServe(":9000", nil)
}

func auth(username, password string) bool {
	return username == "amir" && password == "1234"
}

var m map[string]*uuid.UUID = make(map[string]*uuid.UUID)

func match(username, sessionId string) bool {
	val, exist := m[username]
	return exist && val != nil && val.String() == sessionId
}

func login() {
	// https://github.com/GoesToEleven/GolangTraining/blob/master/27_code-in-process/49_cookies-sessions/08_log-in-out/main.go
	http.HandleFunc("/login", func(w http.ResponseWriter, r *http.Request) {
		username := r.FormValue("username")
		password := r.FormValue("password")
		cook, err := r.Cookie("session-id")

		if err == nil && match(username, cook.Value) {
			http.SetCookie(w, &http.Cookie{
				Name:  "last-visit",
				Value: time.Now().String(),
			})
			w.WriteHeader(http.StatusOK)
			w.Write([]byte("matched cookie"))
		} else if auth(username, password) {
			id, _ := uuid.NewV4()
			http.SetCookie(w, &http.Cookie{
				Name:  "session-id",
				Value: id.String(),
			})
			http.SetCookie(w, &http.Cookie{
				Name:  "last-visit",
				Value: time.Now().String(),
			})
			m[username] = id
			w.WriteHeader(http.StatusOK)
			w.Header().Set("Content-Type", "text/html; charset=utf-8")
			rdr := strings.NewReader("<br>welcome.</br>")
			io.Copy(w, rdr)
		} else {
			w.WriteHeader(http.StatusUnauthorized)
			w.Write([]byte("unauthorized"))
		}
	})

	http.ListenAndServe(":9000", nil)
}

func redir(w http.ResponseWriter, r *http.Request) {
	http.Redirect(w, r, "https://127.0.0.1:13443/"+r.RequestURI, http.StatusPermanentRedirect)
}

// https://www.arubacloud.com/tutorial/how-to-create-a-self-signed-ssl-certificate-on-ubuntu-18-04.aspx
// https://stackoverflow.com/questions/4691699/how-to-convert-crt-to-pem
func tls() {
	go http.ListenAndServe(":9000", http.HandlerFunc(redir))
	err := http.ListenAndServeTLS(":13443", "mycert.pem", "private.pem", nil)

	if err != nil {
		panic(err)
	}
}

func main() {
	// setCookie1()
	// setCookie2()
	// login()
	// tls()
}
