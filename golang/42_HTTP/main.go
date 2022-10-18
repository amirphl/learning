package main

import (
	"bufio"
	"fmt"
	"io"
	"net"
	"strconv"
	"strings"
)

func findMethod() {
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
		defer conn.Close()

		/*
			bf := make([]byte, 1024)
			_, err = conn.Read(bf)
			if err != nil {
				panic(err)
			}
			fmt.Println(string(bf))
		*/
		scanner := bufio.NewScanner(conn)
		scanner.Scan()
		firstLine := scanner.Text()
		tokens := strings.Fields(firstLine)
		fmt.Printf("method: %s\n", tokens[0])

		resp := "Hello world"
		io.WriteString(conn, "HTTP/1.1 200 OK")
		conn.Write([]byte{13, 10}) // \r\n
		io.WriteString(conn, fmt.Sprintf("Content-Length: %d\r\n", len(resp)))
		conn.Write([]byte{13, 10}) // \r\n
		io.WriteString(conn, resp)
	}
}

func showLineFeeds() {
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
		defer conn.Close()

		bf := make([]byte, 1024)
		n, err := conn.Read(bf)
		if err != nil {
			panic(err)
		}
		// Take a look at 13 10 (\r\n) in output.
		fmt.Println(bf[:n])
	}
}

func getHtmlResp() {
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
		defer conn.Close()

		var body_len int
		scanner := bufio.NewScanner(conn)

		for scanner.Scan() {
			line := scanner.Text()
			fmt.Println(line)
			if strings.Contains(line, "Content-Length") {
				b_len := strings.SplitN(line, " ", 2)[1]
				body_len, _ = strconv.Atoi(b_len)
			}
			if line == "" { // \r\n\r\n
				break
			}
		}

		bf := make([]byte, body_len)
		// Reads from the last seek pointer of scanner. This is interesting
		// since both ReadFull and NewScanner share the same Reader, I mean, conn
		// _, err = io.ReadFull(conn, bf)
		// TODO doesn't work!
		_, err = conn.Read(bf)
		if err != nil {
			fmt.Println(err)
		}
		fmt.Println(string(bf))

		resp_body := `<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <title></title>
</head>
<body>
	<form method="POST">
		<input type="text" name="key" value="">
		<input type="submit">
	</form>
</body>
</html>`
		io.WriteString(conn, "HTTP/1.1 200 OK")
		conn.Write([]byte{13, 10}) // \r\n
		io.WriteString(conn, fmt.Sprintf("Content-Length: %d\r\n", len(resp_body)))
		conn.Write([]byte{13, 10})      // \r\n
		io.WriteString(conn, resp_body) // put \r\n\r\n before body
	}
}

func main() {
	// findMethod()
	// showLineFeeds()
	getHtmlResp()
}
