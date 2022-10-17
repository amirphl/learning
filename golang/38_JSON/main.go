package main

// conversion for concrete types: string(j)
// casting for interfaces: j.(string)

import (
	"bytes"
	"encoding/json"
	"fmt"
	"log"
	"os"
	"strings"
)

type Meta struct {
	Job    string `json:"JoB"`
	salary uint16
	Unit   string `json:"unit"`
}

type person struct {
	Nick     string   `json:"first_name"`
	Last     string   `json:"last_name"`
	s1       string   `json:"s1"` // not exposed (lowercase)
	sex      bool     // not exposed (lowercase)
	Age      uint8    `json:"AGE"` // age, AgE, AGE, ... all are correct.
	Courses  []string `json:"courses"`
	Metadata Meta     // exposed as case insensitive of 'metadata'
}

type person2 struct {
	Nick    string   `json:"first_name"`
	Last    string   `json:"last_name"`
	s1      string   `json:"s1"` // not exposed
	sex     bool     // not exposed
	Age     uint8    `json:"AGE"`
	Courses []string `json:"courses"`
	Meta    `json:"meta"`
}

type person3 struct {
	Nick    string   `json:"first_name"`
	Last    string   `json:"last_name"`
	s1      string   `json:"s1"` // not exposed
	sex     bool     // not exposed
	Age     uint8    `json:"AGE"`
	Courses []string `json:"courses"`
	Meta             //
}

func main() {
	fmt.Println("----- 1 -----")
	jsonstr := "{\"name\" : \"amirmohammad\"}"
	j := make(map[string]string)
	err := json.Unmarshal([]byte(jsonstr), &j)
	if err != nil {
		log.Println(err)
	} else {
		fmt.Println(j["name"])
	}

	fmt.Println("----- 2 -----")
	jsonstr = `{"name" : "amirmohammad"}`
	err = json.Unmarshal([]byte(jsonstr), &j)
	if err != nil {
		log.Println(err)
	} else {
		fmt.Printf("%T\n", j["name"])
	}

	fmt.Println("----- 3 -----")
	jsonstr = `{"name" : "amirmohammad", "courses": ["blockchain eng", "dist systems"]}`
	err = json.Unmarshal([]byte(jsonstr), &j)
	if err != nil {
		log.Println(err)
	} else {
		fmt.Println(j["name"])
	}

	fmt.Println("----- 4 -----")
	jsonstr = `{"name" : "amirmohammad", "courses": ["blockchain eng", "dist systems"]}`
	err = json.Unmarshal([]byte(jsonstr), j) // j vs &j
	if err != nil {
		log.Println(err)
	} else {
		fmt.Println(j["name"])
	}

	fmt.Println("----- 5 -----")
	jsonstr = `{"name" : "amirmohammad", "courses": ["blockchain_engineering", "distributed_systems"], "age": 22}`
	j2 := make(map[string]interface{})
	err = json.Unmarshal([]byte(jsonstr), &j2)
	if err != nil {
		log.Println(err)
	} else {
		fmt.Printf("%v    %T\n", j2["name"], j2["name"])
		fmt.Printf("%v    %T\n", j2["courses"], j2["courses"])
		fmt.Printf("%v    %T\n", j2["age"], j2["age"])
		// fmt.Printf("%v    %T\n", j2["courses"].([]string), j2["courses"].([]string)) // TODO
		// for _, val := range j2["courses"].([]string) { // TODO
		for _, val := range j2["courses"].([]interface{}) {
			fmt.Printf("%v   %T\n", val, val)
		}
	}

	fmt.Println("----- 6 -----")
	jsonstr = `100`
	// j3 := interface{}
	var j3 interface{}
	err = json.Unmarshal([]byte(jsonstr), &j3)
	if err != nil {
		log.Println(err)
	} else {
		fmt.Printf("%v   %T   %v\n", j3, j3, 134+j3.(float64))
		val, ok := j3.(int)
		if !ok {
			fmt.Println("faild to cast. interface {} is float64, not int")
		} else {
			fmt.Printf("%v   %T\n", val, val)
		}
	}

	fmt.Println("----- 8 -----")
	jsonstr = `100 100`
	// j3 := interface{}
	err = json.Unmarshal([]byte(jsonstr), &j3)
	if err != nil {
		log.Println(err)
	} else {
		fmt.Printf("%v   %T\n", j3, j3)
	}

	fmt.Println("----- 9 -----")
	jsonstr = `{"a":"b", "c": [33, 34.1, "hello", {"g":"h"}], "d": 22, "e": false, "f": {"lord": "commander", "savaran": "kamandaran"}}`
	j4 := make(map[string]interface{})
	err = json.Unmarshal([]byte(jsonstr), &j4)
	if err != nil {
		panic(err)
	}
	mar, err := json.Marshal(j4)
	if err != nil {
		panic(err)
	}
	fmt.Println(string(mar))

	fmt.Println("----- 10 -----")
	arr := []int{1, 2, 3, 4}
	mar, err = json.Marshal(arr)
	if err != nil {
		panic(err)
	}
	buff := bytes.Buffer{}
	err = json.NewEncoder(&buff).Encode(arr)
	if err != nil {
		panic(err)
	}
	fmt.Println(string(mar), mar, buff) // Look at the diff. 10 = \n

	fmt.Println("----- 11 -----")
	jsonstr = `{"a":"b", "c": [33, 34.1, "hello", {"g":"h"}], "d": 22, "e": false, "f": {"lord": "commander", "savaran": "kamandaran"}}`
	var j5 interface{}
	err = json.NewDecoder(strings.NewReader(jsonstr)).Decode(&j5)
	if err != nil {
		panic(err)
	}
	fmt.Println(j5)

	fmt.Println("----- 12 -----")
	jsonstr = `{"first_name": "amirmohammad", "Last": "phl", "sex": true, "s1": "ssss", "age": 22, "courses": ["DS", "Algo", "OS"], "MetaDatA": {"JoB": "Software_Arch", "Salary": 255000, "unit": "$"}}`
	var j6 person
	err = json.NewDecoder(strings.NewReader(jsonstr)).Decode(&j6)
	if err != nil {
		panic(err)
	}
	fmt.Println("lost: last_name(wrong keyword: Last), sex is not exposed(lowercase s), s1 is not exposed(lowercase s), AGE = age(case insensitive), salary is not exposd(lowercase s)")
	fmt.Println(j6)

	fmt.Println("----- 13 -----")
	jsonstr = `{"first_name": "amirmohammad", "Last": "phl", "sex": true, "s1": "ssss", "age": 22, "courses": ["DS", "Algo", "OS"], "meta": {"JoB": "Software_Arch", "Salary": 255000, "unit": "$"}}`
	var j7 person2
	err = json.NewDecoder(strings.NewReader(jsonstr)).Decode(&j7)
	if err != nil {
		panic(err)
	}
	fmt.Println("Compare with previous one:")
	fmt.Println(j7)

	fmt.Println("----- 14 -----")
	jsonstr = `{"first_name": "amirmohammad", "Last": "phl", "sex": true, "s1": "ssss", "age": 22, "courses": ["DS", "Algo", "OS"], "meta": {"JoB": "Software_Arch", "Salary": 255000, "unit": "$"}}`
	var j8 person3
	err = json.NewDecoder(strings.NewReader(jsonstr)).Decode(&j8)
	if err != nil {
		panic(err)
	}
	fmt.Println("Compare with previous one:")
	fmt.Println(j8)
	fmt.Println("----- 15 -----")
	mar, err = json.Marshal(j8)
	if err != nil {
		panic(err)
	}
	os.Stdout.Write(mar)
	os.Stdout.Write([]byte{10})
	os.Stdout.Write(mar)
	os.Stdout.Write([]byte{13})
}
