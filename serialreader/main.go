package main

import (
	"fmt"
	"log"
	"time"

	"github.com/tarm/serial"
)

func main() {
	fmt.Println("Start app")
	c := &serial.Config{Name: "COM8", Baud: 9600}
	s, err := serial.OpenPort(c)
	if err != nil {
		log.Fatal(err)
	}

	/*n, err := s.Write([]byte("test"))
	if err != nil {
		log.Fatal(err)
	}*/

	for {
		buf := make([]byte, 1)
		n, err := s.Read(buf)
		if err != nil {
			log.Fatal(err)
		}
		log.Printf("%q\n", buf[:n])
		time.Sleep(1 * time.Second)
	}
}
