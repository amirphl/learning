// https://leetcode.com/problems/add-two-numbers/
package main

import "fmt"

type Node struct {
	val  int
	next *Node
}

const Base int = 10

func reverse(n *Node) *Node {
	var prev *Node = nil
	var temp *Node
	for n != nil {
		temp = n.next
		n.next = prev
		prev = n
		n = temp
	}
	return prev
}

func add(x *Node, y *Node) *Node {
	if x == nil {
		return y
	}
	if y == nil {
		return x
	}

	carry := 0
	var head *Node
	var curr *Node

	for x != nil || y != nil {
		if x != nil {
			carry += x.val
			x = x.next
		}
		if y != nil {
			carry += y.val
			y = y.next
		}
		z := &Node{
			val:  carry % Base,
			next: nil,
		}
		if head != nil {
			curr.next = z
			curr = z
		} else {
			head = z
			curr = z
		}
		carry /= Base
	}

	if carry != 0 {
		z := &Node{
			val:  carry,
			next: nil,
		}
		curr.next = z
	}

	return head
}

func main() {
	x := &Node{
		val: 8,
		next: &Node{
			val: 5,
			next: &Node{
				val:  9,
				next: nil,
			},
		},
	}

	y := &Node{
		val: 7,
		next: &Node{
			val: 6,
			next: &Node{
				val: 6,
				next: &Node{
					val:  3,
					next: nil,
				},
			},
		},
	}

	z := add(x, y)

	for z != nil {
		fmt.Println(z.val)
		z = z.next
	}
}
