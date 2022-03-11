package main

import (
	"fmt"
	"math/rand"
	"runtime"
	"strconv"
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

// TODO What's the zero value of `WaitGroup`?
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

func producer1(c chan string, id string) {
	for i := 0; i < 10; i++ {
		c <- id + "_" + strconv.FormatInt(int64(i), 10)
		fmt.Printf("producer	%v	put	%v	at	%v\n", id, i, time.Now())
		time.Sleep(time.Duration(rand.Intn(20)) * time.Millisecond)
	}

	wg.Done()
}

func consumer1(c chan string, id string) {
	for i := 0; i < 20; i++ {
		fmt.Printf("consumer	%v	rec	%v	at	%v	at	%v\n", id, <-c, time.Now(), i)
		time.Sleep(time.Duration(time.Second))
	}

	wg.Done()
}

func noGo() {
	foo1()
	bar1()
}

// Nothing will be printed!
// TODO What happen for the child processes (forks)? Zombie deamons?
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

func produceManyConsumeOneCapOne() {
	c := make(chan string)

	wg.Add(3)
	go producer1(c, "p1")
	go producer1(c, "p2")
	go consumer1(c, "c1")
	wg.Wait()
}

func produceManyConsumeOneCapTen() {
	c := make(chan string, 10)

	wg.Add(3)
	go producer1(c, "p3")
	go producer1(c, "p4")
	go consumer1(c, "c2")
	wg.Wait()
}

func closeChan1() {
	c := make(chan int)

	go func() {
		for i := 0; i < 10; i++ {
			c <- i
			time.Sleep(time.Duration(time.Second))
		}
	}()

	// This section is blocking.
	for v := range c {
		fmt.Printf("v:	%v	time:	%v\n", v, time.Now())
	}

	// fatal error: all goroutines are asleep - deadlock!
}

func closeChan2() {
	c := make(chan int)

	go func() {
		for i := 0; i < 10; i++ {
			c <- i
			time.Sleep(time.Duration(time.Second))
		}

		close(c)
	}()

	for v := range c {
		fmt.Printf("v:	%v	time:	%v\n", v, time.Now())
	}
}

func closeChan3() {
	c := make(chan int, 2)

	go func() {
		for i := 0; i < 10; i++ {
			c <- i
			time.Sleep(time.Duration(time.Second))
		}

	}()

	time.Sleep(time.Duration(2) * time.Second)
	close(c)

	for v := range c {
		fmt.Printf("v:	%v	time:	%v\n", v, time.Now())
	}

	// panic: send on closed channel
}

func closeChan4() {
	c := make(chan int, 5)

	go func() {
		for i := 0; i < 10; i++ {
			c <- i
			time.Sleep(time.Duration(time.Second))
		}

	}()

	time.Sleep(time.Duration(2) * time.Second)
	close(c)

	for v := range c {
		fmt.Printf("v:	%v	time:	%v\n", v, time.Now())
	}
}

func closeChan5() {
	c := make(chan int, 2)

	go func() {
		for i := 0; i < 10; i++ {
			c <- i
			time.Sleep(time.Duration(time.Second))
		}

	}()

	for v := range c {
		fmt.Printf("v:	%v	time:	%v\n", v, time.Now())
		time.Sleep(time.Duration(2) * time.Second)
		close(c)
	}

	// panic: send on closed channel
}

// This ain't gonna work since two go routines are concurrently adding to `wg`.
// possible outputs:
// 	all 20 numbers (there is no order)
// 	some of 20 numbers
// 	panic: send on closed channel
func closeChan6() {
	var wg sync.WaitGroup // shadowed global wg
	c := make(chan int, 5)

	go func() {
		wg.Add(1)

		for i := 0; i < 10; i++ {
			c <- i
		}

		wg.Done()
	}()

	go func() {
		wg.Add(1)

		for i := 0; i < 10; i++ {
			c <- i
		}

		wg.Done()
	}()

	go func() {
		wg.Wait()
		fmt.Println("going to close the channel...")
		close(c)
	}()

	time.Sleep(time.Duration(2) * time.Second)

	for v := range c {
		fmt.Printf("%v	", v)
	}

	fmt.Println()
}

// This works.
// Some numbers may get printed after printing "going to close the channel...".
// reason: capacity of 5
func closeChan7() {
	var wg sync.WaitGroup // shadowed global wg
	c := make(chan int, 5)
	wg.Add(2)

	go func() {
		for i := 0; i < 10; i++ {
			c <- i
		}

		wg.Done()
	}()

	go func() {
		for i := 0; i < 10; i++ {
			c <- i
		}

		wg.Done()
	}()

	go func() {
		wg.Wait()
		fmt.Println("going to close the channel...")
		close(c)
	}()

	time.Sleep(time.Duration(2) * time.Second)

	for v := range c {
		fmt.Printf("%v	", v)
	}

	fmt.Println()
}

// This doesn't work since there's no consumer.
// fatal error: all goroutines are asleep - deadlock!
func closeChan8() {
	var wg sync.WaitGroup // shadowed global wg
	c := make(chan int)
	wg.Add(2)

	go func() {
		for i := 0; i < 10; i++ {
			c <- i
		}

		wg.Done()
	}()

	go func() {
		for i := 0; i < 10; i++ {
			c <- i
		}

		wg.Done()
	}()

	wg.Wait()
	fmt.Println("going to close the channel...")
	close(c)

	time.Sleep(time.Duration(2) * time.Second)

	for v := range c {
		fmt.Printf("%v	", v)
	}

	fmt.Println()
}

// This works.
// All numbers are printed after "going to close the channel..." gets printed.
func closeChan9() {
	var wg sync.WaitGroup   // shadowed global wg
	c := make(chan int, 20) // Note: Capacity is increased to solve the problem of `closeChan8`.
	wg.Add(2)

	go func() {
		for i := 0; i < 10; i++ {
			c <- i
		}

		wg.Done()
	}()

	go func() {
		for i := 0; i < 10; i++ {
			c <- i
		}

		wg.Done()
	}()

	wg.Wait()
	fmt.Println("going to close the channel...")
	close(c)

	time.Sleep(time.Duration(2) * time.Second)

	for v := range c {
		fmt.Printf("%v	", v)
	}

	fmt.Println()
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
	// produceManyConsumeOneCapOne()
	// produceManyConsumeOneCapTen()
	// closeChan1()
	// closeChan2()
	// closeChan3()
	// closeChan4()
	// closeChan5()
	// closeChan6()
	// closeChan7()
	// closeChan8()
	closeChan9()
}
