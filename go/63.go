package main

import "fmt"

func uniquePathsWithObstacles(g [][]int) int {
	m := len(g)
	if m == 0 {
		return 0
	}
	n := len(g[0])
	if n == 0 {
		return 0
	}

	l, r := make([]int, n), make([]int, n)
	for j := 0; j < m; j++ {
		if g[0][0] == 1 {
			r[0] = 0
		} else {
			r[0] = 1
		}
	}

	for i := 0; i < n; i++ {
		copy(l, r)
		if g[0][i] == 1 {
			r[0] = 0
		} else {
			r[0] = 1
		}
		for j := 1; j < m; j++ {
			r[j] = 0
			if g[j][i] == 1 {
				continue
			}
			if g[j-1][i] != 1 {
				r[j] += r[j-1]
			}
			fmt.Println(r[j])
			if i > 0 && g[j][i-1] != 1 {
				r[j] += l[j]
			}
			fmt.Println(r[j])
		}
	}
	return r[m-1]
}
