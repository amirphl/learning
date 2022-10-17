package main

import (
	"encoding/csv"
	"fmt"
	"io"
	"os"
	"strconv"
)

type state struct {
	id            int
	name          string
	circuit_court int
	abbreviation  string
}

func ParseState(columns map[string]int, record []string) (*state, error) {
	id, err := strconv.Atoi(record[columns["id"]])
	if err != nil {
		return nil, err
	}
	circuit_court, err := strconv.Atoi(record[columns["circuit_court"]])
	if err != nil {
		return nil, err
	}
	name := record[columns["name"]]
	abbreviation := record[columns["abbreviation"]]

	// state gets allocated in the heap, not the stack. ?
	return &state{id, name, circuit_court, abbreviation}, nil
}

func main() {
	fmt.Println(">>> phase1: read csv")
	src, err := os.Open("./state_table.csv")
	if err != nil {
		panic(err)

	}
	defer src.Close()

	rdr := csv.NewReader(src)
	headers := make(map[string]int)
	row := 0
	for {
		record, err := rdr.Read()
		if err == io.EOF {
			fmt.Println("EOF reached")
			break
		} else if err != nil {
			panic(err)
		}
		if row == 0 {
			for idx, col := range record {
				headers[col] = idx
			}
		}
		row++
		// fmt.Println(record)
		parsed, _ := ParseState(headers, record)
		fmt.Println(parsed)
	}

	fmt.Println(headers)

	fmt.Println("\n\n>>> phase 2: ReadAll")

	src.Seek(0, io.SeekStart)
	rdr = csv.NewReader(src)
	rows, err := rdr.ReadAll()
	if err != nil {
		panic(err)
	}
	for idx, row := range rows {
		fmt.Println(idx, row)
	}
}
