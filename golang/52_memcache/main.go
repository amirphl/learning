package main

import (
	"encoding/json"
	"fmt"
	"io"
	"log"
	"net/http"
	"time"

	"google.golang.org/appengine"
	"google.golang.org/appengine/memcache"
	"google.golang.org/appengine/user"
)

func init() {
	http.HandleFunc("/h1", handler1)
	http.HandleFunc("/h2", handler2)
	http.HandleFunc("/h3", handler3)
	http.HandleFunc("/h4", handler4)
	http.HandleFunc("/h5", handler5)
}

// get
func handler1(w http.ResponseWriter, r *http.Request) {
	ctx := appengine.NewContext(r)
	item, err := memcache.Get(ctx, "the-key")
	if err != nil {
		http.Error(w, "Not found", http.StatusNotFound)
		return
	}
	fmt.Fprintln(w, item)
}

// set and get
func handler2(w http.ResponseWriter, r *http.Request) {
	ctx := appengine.NewContext(r)
	key := "the-key"
	val := []byte("the-val")
	item1 := memcache.Item{
		Key:   key,
		Value: val,
	}

	memcache.Set(ctx, &item1)
	item, err := memcache.Get(ctx, key)

	if err != nil {
		log.Println("Not found at h2")
		http.Error(w, "", http.StatusInternalServerError)
		return
	}

	log.Println("Found at h2")
	w.WriteHeader(http.StatusOK)
	bs, _ := json.Marshal(item)
	w.Write(bs)
}

// expire
func handler3(w http.ResponseWriter, r *http.Request) {
	ctx := appengine.NewContext(r)
	key := "the-key"
	val := "the-val"
	item1 := memcache.Item{
		Key:        key,
		Value:      []uint8(val),
		Expiration: 10 * time.Second,
	}

	memcache.Set(ctx, &item1)
	item, err := memcache.Get(ctx, key)

	if err != nil {
		log.Println("Not found at h3")
		http.Error(w, "", http.StatusInternalServerError)
		return
	}

	log.Println("Found at h3")
	w.Header().Add("status", "ok")
	io.WriteString(w, item.Key)
}

// increment
func handler4(w http.ResponseWriter, r *http.Request) {
	if r.URL.Path != "/h4" {
		http.NotFound(w, r)
		return
	}

	ctx := appengine.NewContext(r)
	u := user.Current(ctx)

	globalCounter, _ := memcache.Increment(ctx, "global", 4, 3)
	localKey := fmt.Sprintf("%s-%s", "local", u)
	localCounter, _ := memcache.Increment(ctx, localKey, 7, 0)

	fmt.Fprintf(w, "%x\n", globalCounter)
	fmt.Fprintf(w, "%x\n", localCounter)
}

// cookie
func handler5(w http.ResponseWriter, r *http.Request) {
	cookie, err := r.Cookie("the-key")

	if err != nil {
		http.Error(w, "", http.StatusUnauthorized)
		return
	}

	log.Printf("This is the cookie: %s", cookie)
	w.WriteHeader(http.StatusOK)
	fmt.Fprintf(w, "%s\n", cookie.Raw)
}

func main() {
	http.ListenAndServe(":9000", nil)
}
