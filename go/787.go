package main

import (
	"math"
)

func findCheapestPrice(n int, flights [][]int, src int, dst int, k int) int {
	prev, curr := make([]int, n), make([]int, n)
	for i := 0; i < n; i++ {
		prev[i], curr[i] = math.MaxInt32/2, math.MaxInt32/2
	}
	curr[src] = 0
	for i := 0; i <= k; i++ {
		copy(prev, curr)
		for _, flight := range flights {
			from, to, cost := flight[0], flight[1], flight[2]
			newCost := prev[from] + cost
			if curr[to] > newCost {
				curr[to] = newCost
			}
		}
	}
	if curr[dst] == math.MaxInt32/2 {
		return -1
	}
	return curr[dst]
}
