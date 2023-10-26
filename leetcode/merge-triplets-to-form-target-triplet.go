// https://leetcode.com/problems/merge-triplets-to-form-target-triplet/
package main

func mergeTriplets(triplets [][]int, target []int) bool {
	temp := []int{0, 0, 0}
	for _, t := range triplets {
		flag := true
		for i, v := range t {
			if v > target[i] {
				flag = false
				break
			}
		}
		if flag {
			for i, v := range t {
				if v > temp[i] {
					temp[i] = v
				}
			}
		}
	}
	flag := true
	for i, v := range temp {
		if v != target[i] {
			flag = false
			break
		}
	}
	return flag
}
