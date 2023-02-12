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

// Notes:
// 0- Setup multicore flags.
// 1- Always specify the size of channel.
// 2- Remember to check all conditions. What happens in the case of concurrency vs parallelism?
// 3- directed channels
// 4- Close the channels. Take care of reading from a closed channel.
// TODO Can I read from a closed channel if it's not empty?
// 5- waitGroup, mutex, atomic, channels, pipeline, fanInfanOut
// 6- range is blocking unless the channel is closed!

func init() {
	// If you include this line, we will have `parallelism` since we are using multiple cores
	// If you don't include this line, we will have `concurrency` since we are using only one core.
	// TODO changes after go v1.5?
	runtime.GOMAXPROCS(runtime.NumCPU())
}

// TODO What's the default value of `WaitGroup`?
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

		// Take care! You might close a non-empty channel!
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
			fmt.Printf("added to channel at iteration %d \n", i)
			time.Sleep(time.Duration(time.Second))
		}

	}()

	time.Sleep(time.Duration(3) * time.Second)
	close(c)

	for v := range c {
		fmt.Printf("v:	%v	time:	%v\n", v, time.Now())
	}

	// panic: send on closed channel
}

// TODO what's the diff between this one and closeChan3?
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

	wg.Wait() // This line causes the problem.
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

func testSemaphore1() {
	c := make(chan int, 5)
	s := make(chan string, 2) // 2 = number of routines. It can be more than 2.

	go func() {
		for i := 0; i < 10; i++ {
			c <- i
		}

		s <- "routine_1"
	}()

	go func() {
		for i := 0; i < 10; i++ {
			c <- i
		}

		s <- "routine_2"
	}()

	go func() {
		res := <-s
		<-s
		fmt.Printf("\nwhich routine finished sooner?	%v\n", res)
		fmt.Println("going to close the channel...")
		close(c)
	}()

	for v := range c {
		fmt.Printf("%v	", v)
	}

	fmt.Println()
}

// `testSemaphore1` also works with a queue of length one.
func testSemaphore2() {
	c := make(chan int, 5)
	s := make(chan string) // unbuffered channel (length = 1)

	go func() {
		for i := 0; i < 10; i++ {
			c <- i
		}

		s <- "routine_1"
	}()

	go func() {
		for i := 0; i < 10; i++ {
			c <- i
		}

		s <- "routine_2"
	}()

	go func() {
		res := <-s
		<-s
		fmt.Printf("\nwhich routine finished sooner?	%v\n", res)
		fmt.Println("going to close the channel...")
		close(c)
	}()

	for v := range c {
		fmt.Printf("%v	", v)
	}

	fmt.Println()
}

// m to n is possible too.
// This is misleading!
// See difference of `testOneProducerManyConsumer1` and `testOneProducerManyConsumer2`.
func testOneProducerManyConsumer1() {
	c := make(chan int, 100)
	s := make(chan bool)

	go func() {
		for i := 0; i < 20; i++ {
			c <- i
		}

		close(c)
	}()

	n := 3
	for i := 0; i < n; i++ {
		go func() {
			for v := range c {
				fmt.Printf("consumer%v: %v\n", i, v)
				time.Sleep(time.Duration(rand.Intn(20)*(i+1)) * time.Millisecond)
			}
			s <- true
		}()
	}

	for i := 0; i < n; i++ {
		<-s
	}
}

// This works as expected.
// See difference of `testOneProducerManyConsumer1` and `testOneProducerManyConsumer2`.
func testOneProducerManyConsumer2() {
	c := make(chan int, 100)
	s := make(chan bool)

	go func() {
		for i := 0; i < 20; i++ {
			c <- i
		}

		close(c)
	}()

	n := 3
	for i := 0; i < n; i++ {
		go func(id int) {
			for v := range c {
				fmt.Printf("consumer%v: %v\n", id, v)
				time.Sleep(time.Duration(rand.Intn(20)*(id+1)) * time.Millisecond)
			}
			s <- true
		}(i)
	}

	for i := 0; i < n; i++ {
		<-s
	}
}

// This doesn't work.
// fatal error: all goroutines are asleep - deadlock!
func testOneProducerManyConsumer3() {
	c := make(chan int, 100)
	s := make(chan bool)

	go func() {
		for i := 0; i < 20; i++ {
			c <- i
		}

		// close(c)
	}()

	n := 3
	for i := 0; i < n; i++ {
		go func(id int) {
			for v := range c {
				fmt.Printf("consumer%v: %v\n", id, v)
				time.Sleep(time.Duration(rand.Intn(20)*(id+1)) * time.Millisecond)
			}
			s <- true
		}(i)
	}

	for i := 0; i < n; i++ {
		<-s
	}
}

// This doesn't work.
func testOneProducerManyConsumer4() {
	c := make(chan int, 100)
	s := make(chan bool)

	go func() {
		for i := 0; i < 20; i++ {
			c <- i
		}

		close(c)
	}()

	n := 3
	for i := 0; i < n; i++ {
		go func(id int) {
			for v := range c {
				fmt.Printf("consumer%v: %v\n", id, v)
				time.Sleep(time.Duration(rand.Intn(20)*(id+1)) * time.Millisecond)
			}
			s <- true
		}(i)
	}

	// for i := 0; i < n; i++ {
	for i := 0; i < n-1; i++ {
		<-s
	}

	fmt.Println("reached the end ...")
}

func pusher() chan int {
	c := make(chan int)

	go func() {
		for i := 0; i < 1000; i++ {
			c <- i
			fmt.Printf("pusher: %v\n", i)
			time.Sleep(time.Duration(rand.Intn(2)) * time.Millisecond)
		}

		close(c)
	}()

	return c
}

func puller(c chan int) chan int {
	out := make(chan int)

	go func() {
		s := 0
		for v := range c {
			fmt.Printf("puller: %v\n", v)
			s += v
		}
		out <- s
		close(out)
	}()

	return out
}

func pusher2() <-chan int {
	c := make(chan int)

	go func() {
		for i := 0; i < 1000; i++ {
			c <- i
			fmt.Printf("pusher2: %v\n", i)
			time.Sleep(time.Duration(rand.Intn(2)) * time.Millisecond)
		}

		close(c)
	}()

	return c
}

func puller2(c <-chan int) <-chan int {
	out := make(chan int)

	go func() {
		s := 0
		for v := range c {
			fmt.Printf("puller2: %v\n", v)
			s += v
		}
		out <- s
		close(out)
	}()

	return out
}

// There is no dead lock!
// This a pipeline pattern.
func testReturnChan1() {
	c := pusher()
	// There are still stuffs are being pushed to the `c`.
	out := puller(c)
	// There are still stuffs are being pushed to the `out`.

	for s := range out {
		fmt.Println(s)
	}
}

// Channel direction example
func testReturnChan2() {
	c := pusher2()
	// There are still stuffs are being pushed to the `c`.
	out := puller2(c)
	// There are still stuffs are being pushed to the `out`.

	for s := range out {
		fmt.Println(s)
	}
}

func testReturnChan3() {
	c1 := pusher2()
	c2 := pusher2()
	out1 := puller2(c1)
	out2 := puller2(c2)
	fmt.Println(<-out1 + <-out2)
}

// fatal error: all goroutines are asleep - deadlock!
// TODO What the hell is wrong with it?
func makeDeadlock() {
	c := make(chan int)
	c <- 1
	fmt.Println(<-c)
}

func solveDeadlock1() {
	c := make(chan int, 1)
	c <- 1
	fmt.Println(<-c)
}

func solveDeadlock2() {
	c := make(chan int, 1)
	go func() { c <- 1 }()
	fmt.Println(<-c)
}

// challenge: Why it only prints `0`?
func challenge1() {
	c := make(chan int)

	go func() {
		for i := 0; i < 10; i++ {
			c <- i
		}
	}()

	fmt.Println(<-c)
}

// TODO What happens if the NumCPU = 1?
// TODO effect of channel size, 0, 1, n
func solveChallenge1() {
	c := make(chan int)

	go func() {
		for i := 0; i < 10; i++ {
			c <- i
		}

		// If you do not close the channel: fatal error: all goroutines are asleep - deadlock!
		// reason: `range(c)` is always waiting to receive something from the channel (blocking) unless you close the channel.
		close(c)
	}()

	for v := range c {
		fmt.Println(v)
	}

	// This causes deadlock!
	// for {
	// 	fmt.Println(<-c)
	// }
}

// Compute factorial with goroutines.
func challenge2(x int) int {
	if x == 0 {
		return 1
	}

	return x * challenge2(x-1)
}

func solveChallenge2(x int) {
	n := int(x / 2)
	c := make(chan int)

	go func() {
		s := 1

		for i := 1; i <= n; i++ {
			s *= i
		}

		c <- s
	}()

	go func() {
		s := 1

		for i := n + 1; i <= x; i++ {
			s *= i
		}

		c <- s
	}()

	fmt.Println(<-c * <-c)
	close(c)
}

func fanInfanOutExample() {
	c1 := make(chan int)

	go func() {
		for {
			c1 <- rand.Intn(100)
			time.Sleep(time.Duration(10 * time.Millisecond))
		}
		// no close, it works forever.
	}()

	c2 := make(chan int)

	worker := func() {
		for v := range c1 {
			c2 <- v * v
			time.Sleep(time.Duration(10 * time.Millisecond))
		}
		// no close, it works forever.
	}

	go worker()
	go worker()

	for i := 0; i < 10; i++ {
		fmt.Printf("%v ", <-c2)
	}

	// Uncomment and run with `-race` argument: WARNING: DATA RACE
	// close(c1)
	// close(c2)

	fmt.Println()
}

func fact(x int64) int64 {
	if x == 0 || x == 1 {
		return 1
	}

	return x * fact(x-1)
}

func multiFactFanInFanOut() {
	n := 3
	c1 := make(chan int)
	c2 := make([]chan int64, n)
	c3 := make(chan int64)

	for i := 0; i < n; i++ {
		c2[i] = make(chan int64)
	}

	producer := func() {
		for {
			c1 <- rand.Intn(20)
			// time.Sleep(time.Duration(10 * time.Millisecond))
		}
		// no close, it works forever.
	}

	worker := func(id int) {
		for v := range c1 {
			c2[id] <- fact(int64(v))
			// time.Sleep(time.Duration(10 * time.Millisecond))
		}
		// no close, it works forever.
	}

	merger := func(id int) {
		for v := range c2[id] {
			c3 <- v
			// time.Sleep(time.Duration(10 * time.Millisecond))
		}
		// no close, it works forever.
	}

	go producer()

	for i := 0; i < n; i++ {
		go worker(i)
		go merger(i)
	}

	for i := 0; i < 100000; i++ {
		fmt.Printf("%v ", <-c3)
	}

	fmt.Println()
}

// challenge: fix `fatal error: all goroutines are asleep - deadlock!`
func deadLockChallenge() {
	gen := func() <-chan int {
		out := make(chan int)

		go func() {
			for i := 0; i < 10000; i++ {
				for j := 3; j < 13; j++ {
					out <- j
				}
			}

			close(out)
		}()

		return out
	}

	factorial := func(in <-chan int) <-chan int {
		out := make(chan int)

		go func() {
			for n := range in {
				out <- int(fact(int64(n)))
			}

			close(out)
		}()

		return out
	}

	fanOut := func(in <-chan int, n int) []<-chan int {
		xc := make([]<-chan int, n)

		for i := 0; i < n; i++ {
			xc = append(xc, factorial(in))
		}

		return xc
	}

	merge := func(cs ...<-chan int) <-chan int {
		var wg sync.WaitGroup
		out := make(chan int)

		output := func(c <-chan int) {
			for n := range c {
				out <- n
			}

			wg.Done()
		}

		wg.Add(len(cs))

		for _, c := range cs {
			go output(c)
		}

		go func() {
			wg.Wait()
			close(out)
		}()

		return out
	}

	in := gen()

	xc := fanOut(in, 10)

	for n := range merge(xc...) {
		fmt.Printf("%v ", n)
	}
}

func deadLockChallengeSolution() {
	gen := func() <-chan int {
		out := make(chan int)

		go func() {
			for i := 0; i < 10000; i++ {
				for j := 3; j < 13; j++ {
					out <- j
				}
			}

			close(out)
		}()

		return out
	}

	factorial := func(in <-chan int) <-chan int {
		out := make(chan int)

		go func() {
			for n := range in {
				out <- int(fact(int64(n)))
			}

			close(out)
		}()

		return out
	}

	fanOut := func(in <-chan int, n int) []<-chan int {
		xc := make([]<-chan int, n)

		for i := 0; i < n; i++ {
			xc[i] = factorial(in)
		}

		return xc
	}

	merge := func(cs ...<-chan int) <-chan int {
		var wg sync.WaitGroup
		out := make(chan int)

		output := func(c <-chan int) {
			for n := range c {
				out <- n
			}

			wg.Done()
		}

		wg.Add(len(cs))

		for _, c := range cs {
			go output(c)
		}

		go func() {
			wg.Wait()
			close(out)
		}()

		return out
	}

	in := gen()

	xc := fanOut(in, 10)

	for n := range merge(xc...) {
		fmt.Printf("%v ", n)
	}
}

// challenge: replace `sync` and `atomic` with `channel`.
func incrementorChallenge() {
	var count int64
	var wg sync.WaitGroup

	inc := func(s string) {
		for i := 0; i < 20; i++ {
			atomic.AddInt64(&count, 1)
			fmt.Printf("-- inc %v	%v\n", s, i)
		}

		wg.Done()
	}

	wg.Add(2)
	go inc("1")
	go inc("2")
	wg.Wait()
	fmt.Println(count)
}

func incrementorChallengeSolution() {
	var count int64
	c := make(chan bool)
	// d := make(chan bool) // Uncomment and see what happens! deadlock!
	d := make(chan bool, 1)
	d <- true

	inc := func(s string) {
		for i := 0; i < 20; i++ {
			<-d
			count++
			fmt.Printf("++ inc %v	%v\n", s, i)
			d <- true
		}

		c <- false
	}

	go inc("1")
	go inc("2")
	<-c
	<-c
	fmt.Println(count)
}

func what() {
	m := map[int]int{}
	m[4] = 7
	m[3] = 87
	m[72] = 19

	ch := make(chan int)

	// for closing ch
	ch2 := make(chan int)
	go func() {
		var i int
		for n := range ch2 {
			i += n
			if i == len(m) {
				close(ch)
			}
		}
	}()

	go func() {
		for _, v := range m {
			ch <- v
			ch2 <- 1
		}
	}()

	for v := range ch {
		fmt.Println(v)
	}

	// good housekeeping
	close(ch2)
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
	// closeChan9()
	// testSemaphore1()
	// testSemaphore2()
	// testOneProducerManyConsumer1()
	// testOneProducerManyConsumer2()
	// testOneProducerManyConsumer3()
	// testOneProducerManyConsumer4()
	// testReturnChan1()
	// testReturnChan2()
	// testReturnChan3()
	// makeDeadlock()
	// solveDeadlock1()
	// solveDeadlock2()
	// challenge1()
	// solveChallenge1()
	// challenge2(10)
	// solveChallenge2(10)
	// fanInfanOutExample()
	// multiFactFanInFanOut()
	// deadLockChallenge()
	// deadLockChallengeSolution()
	// incrementorChallenge()
	// incrementorChallengeSolution()
	// what()
}
