package main

import (
	"encoding/json"
	"fmt"
	"io"
	"log"
	"net"
	"os"
	"strconv"
	"strings"
	"sync"
	"time"
)

// Remember to Close a connection
// Also take a look at this: https://github.com/GoesToEleven/GolangTraining/blob/master/27_code-in-process/41_TCP/05_redis-clone/i06/main.go

func Listen() {
	ln, err := net.Listen("tcp", ":9000")
	if err != nil {
		panic(err)
	}
	defer ln.Close()

	for {
		conn, err := ln.Accept()
		if err != nil {
			log.Fatalln(err)
		} else {
			conn.Write([]byte(fmt.Sprintf("Hello   %v\n", time.Now())))
		}
		conn.Close() // *** Do not defer
	}
}

func Dial() {
	conn, err := net.Dial("tcp", ":9000")
	if err != nil {
		log.Panic(err)
	}
	defer conn.Close()
	conn.Write([]byte("I am client. dial"))
	time.Sleep(time.Second * 2)
	/*
		bf, err := io.ReadAll(conn)
		if err != nil {
			log.Fatalln(err)
		}
	*/
	io.Copy(os.Stdout, conn)
}

func Echo() {
	ln, err := net.Listen("tcp", ":9000")
	if err != nil {
		panic(err)
	}
	defer ln.Close()

	for {
		conn, err := ln.Accept()
		if err != nil {
			log.Println(err)
		}
		defer conn.Close()
		for {
			bf := make([]byte, 1024)
			_, err := conn.Read(bf)
			if err != nil {
				fmt.Println(err)
				break
			}
			fmt.Println(string(bf))
			_, err = conn.Write(bf)
			if err != nil {
				fmt.Println(err)
				break
			}
		}
	}
}

func EchoMultiCLient() {
	ln, err := net.Listen("tcp", ":9000")
	if err != nil {
		panic(err)
	}
	defer ln.Close()
	idx := 0

	for {
		conn, err := ln.Accept()
		if err != nil {
			log.Println(err)
		}

		go func(c net.Conn, index int) {
			for {
				bf := make([]byte, 1024)
				_, err := c.Read(bf)
				if err != nil {
					fmt.Println(index, err)
					break
				}
				fmt.Printf("id: %d, data: %s\n", index, string(bf))
				_, err = c.Write(bf)
				if err != nil {
					fmt.Println(index, err)
					break
				}
				if string(bf[:len("terminate")]) == "terminate" {
					break
				}
			}

			fmt.Printf("Closing connection of id: %d\n", index)
			c.Close()
		}(conn, idx)
		idx++
	}
}

func EchoMultiCLientV2() {
	ln, err := net.Listen("tcp", ":9000")
	if err != nil {
		panic(err)
	}
	defer ln.Close()
	idx := 0

	for {
		conn, err := ln.Accept()
		if err != nil {
			log.Println(err)
		}

		go func(c net.Conn) {
			defer c.Close()
			for {
				io.Copy(c, c)
			}
			// Can't reach here even if the client closes the connection
			fmt.Println("Can I reach here?")
		}(conn)
		idx++
	}
}

func SetupRedisServer() {
	ln, err := net.Listen("tcp", ":9000")
	if err != nil {
		panic(err)
	}
	defer ln.Close()
	cache := make(map[string]string)

	for {
		c, err := ln.Accept()
		if err != nil {
			panic(err)
		}
		go func(conn net.Conn) {
			defer conn.Close()

			for {
				buff := make([]byte, 1024)
				n, err := conn.Read(buff)

				if err != nil {
					fmt.Println(err)            // EOF
					conn.Write([]byte{101, 10}) // 'e'
					break                       // Uncomment and see the results! *****
				} else {
					in := string(buff[:n])
					tokens := strings.Split(in, " ")

					if len(tokens) != 2 && len(tokens) != 3 {
						conn.Write([]byte{102, 10}) // 'f'
					} else {
						command := tokens[0]
						key := tokens[1]

						switch command {
						case "GET":
							key = key[:len(key)-1] // trim \n
							val := cache[key]
							fmt.Fprintf(conn, "%s", val) // ***
							conn.Write([]byte{103, 10})  // '\n', 'g'
						case "POST":
							val := tokens[2]
							cache[key] = val
							conn.Write([]byte{104, 10}) // 'h'
						case "DELETE":
							key = key[:len(key)-1] // trim \n
							delete(cache, key)
							conn.Write([]byte{105, 10}) // 'i'
						case "ALL":
							ser, _ := json.Marshal(cache)
							conn.Write(ser)
							conn.Write([]byte{10, 106, 10}) // 'j'
						default:
							io.WriteString(conn, "Invalid command\n") // ***
							conn.Write([]byte{102, 10})               // 'f'
						}
					}
				}
			}
		}(c)
	}
}

var unique_id = 0
var mutex sync.Mutex

type Event struct {
	Key    string
	Params interface{}
}

type User struct {
	Id string
}

type Joined struct {
	User
	Ch chan *Event
}

type Left struct {
	User
}

type Content struct {
	Text string
}

type Message struct {
	User
	Content
}

func runServer(in <-chan *Event) {
	users := make(map[User]chan *Event)
	for {
		var user User
		e := <-in
		switch e.Key {
		case "JOINED":
			jnd := e.Params.(Joined)
			user = jnd.User
			users[jnd.User] = jnd.Ch
		case "LEFT":
			lft := e.Params.(Left)
			user = lft.User
			delete(users, lft.User)
		case "MSG":
			msg := e.Params.(Message)
			user = msg.User
		}
		for u, c := range users {
			if u != user {
				c <- e // TODO You may get blocked at this point. // solution: use `select`
			}
		}
	}
}

func handleRec(conn net.Conn, user User, serverChan chan *Event, ter chan byte) {
	for {
		buff := make([]byte, 1024)
		n, err := conn.Read(buff)

		if err != nil {
			fmt.Printf("Error reading from user %s: %v\n", user.Id, err)
			break
		}

		serverChan <- &Event{
			"MSG",
			Message{
				user,
				Content{
					string(buff[:n]),
				},
			},
		}
	}

	serverChan <- &Event{
		"LEFT",
		Left{
			user,
		},
	}

	ter <- 1
}

func handleSnd(conn net.Conn, clientChan <-chan *Event) {
	for e := range clientChan {
		switch e.Key {
		case "JOINED":
			who := e.Params.(Joined).User
			fmt.Fprintf(conn, "SYSTEM: new user joind: %s\n", who.Id)
		case "LEFT":
			who := e.Params.(Left).User
			fmt.Fprintf(conn, "SYSTEM: user left: %s\n", who.Id)
		case "MSG":
			who := e.Params.(Message).User
			text := e.Params.(Message).Content.Text
			io.WriteString(conn, fmt.Sprintf("%s: %s\n", who.Id, text))
		}
	}
	// This thread will be automatically terminated because the channel gets closed after the user leaves. The loop will be terminated.
}

func handleClient(conn net.Conn, serverChan chan *Event) {
	defer conn.Close()
	clientChan := make(chan *Event)
	defer close(clientChan)

	mutex.Lock()
	user := User{
		strconv.Itoa(unique_id),
	}
	unique_id++
	mutex.Unlock()

	serverChan <- &Event{
		"JOINED",
		Joined{
			user,
			clientChan,
		},
	}

	ter := make(chan byte, 1)
	defer close(ter)

	go handleRec(conn, user, serverChan, ter)
	go handleSnd(conn, clientChan)
	<-ter
	fmt.Println("For debug.")
}

func SetupChatServer() {
	serverChan := make(chan *Event, 10)
	defer close(serverChan)
	go runServer(serverChan)

	ln, err := net.Listen("tcp", ":9000")
	if err != nil {
		panic(err)
	}
	defer ln.Close()

	for {
		conn, err := ln.Accept()
		if err != nil {
			panic(err)
		}
		go handleClient(conn, serverChan)
	}
}

func main() {
	// Listen()
	// Dial()
	// Echo()
	// EchoMultiCLient()
	// EchoMultiCLientV2()
	// SetupRedisServer()
	SetupChatServer()
}
