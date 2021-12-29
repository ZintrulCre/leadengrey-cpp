package main

import "fmt"

func escapeGhosts(gs [][]int, t []int) bool {
	abs := func(v int) int {
		if v > 0 {
			return v
		}
		return -v
	}
	MD := func(a int, b int, x int, y int) int {
		return abs(a-x) + abs(b-y)
	}

	dist := MD(t[0], t[1], 0, 0)
	fmt.Println(dist)
	for _, g := range gs {
		if dist >= MD(t[0], t[1], g[0], g[1]) {
			return false
		}
	}
	return true
}
