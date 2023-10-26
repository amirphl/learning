// https://leetcode.com/problems/largest-number-after-mutating-substring/
package main

func maximumNumber(s string, change []int) string {
	n := len(s)
	u := make([]rune, 0, n)
	f1, f2 := true, false
	for _, ch := range s {
		n := int(ch - '0')
		if f1 {
			if change[n] > n {
				f1 = false
				f2 = true
				u = append(u, rune(change[n]+'0'))
				continue
			}
			u = append(u, ch)
		} else {
			if change[n] < n {
				f2 = false
			}
			if f2 {
				u = append(u, rune(change[n]+'0'))
			} else {
				u = append(u, ch)
			}
		}
	}
	return string(u)
}
