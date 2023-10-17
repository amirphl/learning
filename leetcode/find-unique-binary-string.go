// https://leetcode.com/problems/find-unique-binary-string/
package main

import (
	"math"
	"strconv"
	"strings"
)

func findDifferentBinaryString(nums []string) string {
	n := len(nums)
	all := make(map[int64]bool)

	for _, v := range nums {
		i, _ := strconv.ParseInt(v, 2, 64)
		all[i] = true
	}

	m := int64(math.Pow(2, float64(n)))
	for i := int64(0); i < m; i++ {
		if _, exists := all[i]; !exists {
			x := strconv.FormatInt(i, 2)
			return strings.Repeat("0", n-len(x)) + x
		}
	}
	return "1"
}
