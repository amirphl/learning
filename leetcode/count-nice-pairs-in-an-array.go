// https://leetcode.com/problems/count-nice-pairs-in-an-array/
package main

var mod = int64(1e9 + 7)

func rev(n int) int {
	y := 0
	for n > 0 {
		rem := n % 10
		y *= 10
		y += rem
		n /= 10
	}
	return y
}
func countNicePairs(nums []int) int {
	res := int64(0)
	m := make(map[int]int64)
	for _, v := range nums {
		m[v-rev(v)]++
	}
	for _, v := range m {
		res = (res + ((v * (v - 1) / 2) % mod)) % mod
	}
	return int(res)
}
