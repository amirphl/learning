// https://quera.org/contest/assignments/45366/problems/157573

package cache

import (
	"fmt"
)

type CacheVal string

type CacheClientConnection struct {
	snd chan CacheRequest
	rcv chan CacheResponse
}

type CacheRequest struct {
	Request string
	Key     string
	Val     CacheVal
	RTL     int
}

type CacheResponse struct {
	Val CacheVal
	Msg string
}

func (conn *CacheClientConnection) Set(key string, val CacheVal) {
	conn.snd <- CacheRequest{
		Request: "Set",
		Key:     key,
		Val:     val,
	}
	<-conn.rcv
}

func (conn *CacheClientConnection) SetWithRTL(key string, val CacheVal, RTL int) {
	conn.snd <- CacheRequest{
		Request: "Set",
		Key:     key,
		Val:     val,
		RTL:     RTL,
	}
	<-conn.rcv
}

func (conn *CacheClientConnection) Get(key string) CacheVal {
	conn.snd <- CacheRequest{
		Request: "Get",
		Key:     key,
	}
	res := <-conn.rcv

	return res.Val
}

func main() {
	cache := InitCache()
	conn := cache.Connect("amir")
	conn.SetWithRTL("kk", "vv", 3)
	fmt.Println(conn.Get("kk"))
	fmt.Println(conn.Get("kk"))
	fmt.Println(conn.Get("kk"))
	fmt.Println(conn.Get("kk"))
}
