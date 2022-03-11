package main

import (
	"fmt"
	"runtime"
	"sync"
	"sync/atomic"
	"time"
)

func init() {
	// If you include this line, we will have `parallelism` since we are using multiple cores
	// If you don't include this line, we will have `concurrency` since we are using only one core.
	// TODO changes after go v1.5?
	runtime.GOMAXPROCS(runtime.NumCPU())
}

var wg sync.WaitGroup

func foo1() {
	for i := 0; i < 10; i++ {
		fmt.Printf("foo_1	%v\n", i)
	}
}

func bar1() {
	for i := 0; i < 10; i++ {
		fmt.Printf("bar_1	%v\n", i)
	}
}

func foo2() {
	for i := 0; i < 10; i++ {
		fmt.Printf("foo_2	%v\n", i)
	}

	wg.Done()
}

func bar2() {
	for i := 0; i < 10; i++ {
		fmt.Printf("bar_2	%v\n", i)
	}

	wg.Done()
}

func foo3() {
	for i := 0; i < 10; i++ {
		fmt.Printf("foo_3	%v\n", i)
		time.Sleep(time.Duration(10 * time.Millisecond))
	}

	wg.Done()
}

func bar3() {
	for i := 0; i < 10; i++ {
		fmt.Printf("bar_3	%v\n", i)
		time.Sleep(time.Duration(10 * time.Millisecond))
	}

	wg.Done()
}

func foo4() {
	for i := 0; i < 10; i++ {
		fmt.Printf("foo_4	%v\n", i)
	}
}

func bar4() {
	for i := 0; i < 10; i++ {
		fmt.Printf("bar_4	%v\n", i)
	}
}

var counter int32

func inc(id string) {
	x := int32(0)

	for i := 0; i < 10; i++ {
		x = counter
		x++
		// Swap next two lines and see what happens!
		time.Sleep(time.Duration(3 * time.Millisecond))
		counter = x
		fmt.Printf("id: %v	x: %v	counter: %v\n", id, x, counter)
	}

	wg.Done()
}

var mutex sync.Mutex

func inc2(id string) {
	for i := 0; i < 10; i++ {
		time.Sleep(time.Duration(3 * time.Millisecond))
		mutex.Lock()
		counter++
		fmt.Printf("id: %v	counter: %v\n", id, counter)
		mutex.Unlock()
	}

	wg.Done()
}

func inc3(id string) {
	for i := 0; i < 10; i++ {
		time.Sleep(time.Duration(3 * time.Millisecond))
		atomic.AddInt32(&counter, 1)
		fmt.Printf("id: %v	counter: %v\n", id, counter)
	}

	wg.Done()
}

// Nothing will be printed!
// TODO What happen for the child processes (forks)? Zombie deamons?
func noGo() {
	foo1()
	bar1()
}

func noWait() {
	go foo1()
	go bar1()
}

func waitSync() {
	wg.Add(2) // TODO The logic behind it?
	go foo2()
	go bar2()
	wg.Wait()
}

func waitSyncDelayed() {
	wg.Add(2)
	go foo3()
	go bar3()
	wg.Wait()
}

func race() {
	wg.Add(2)
	go inc("id_1")
	go inc("id_2")
	wg.Wait()
	fmt.Printf("final counter must be 20 but it's: %v\n", counter)
}

func waitSyncWithoutDone() {
	wg.Add(2)
	go foo4()
	go bar4()
	wg.Wait()
}

func testMutex() {
	wg.Add(2)
	go inc2("id_3")
	go inc2("id_4")
	wg.Wait()
	fmt.Printf("final counter must be 20 and it's: %v\n", counter)
}

func testAtomic() {
	wg.Add(2)
	go inc3("id_5")
	go inc3("id_6")
	wg.Wait()
	fmt.Printf("final counter must be 20 and it's: %v\n", counter)
}

func main() {
	// noGo()
	// noWait()
	// waitSync()
	// waitSyncDelayed()
	// waitSyncWithoutDone() // fatal error: all goroutines are asleep - deadlock!
	// go run -race main.go
	// race()
	// testMutex()
	// testAtomic()
}
