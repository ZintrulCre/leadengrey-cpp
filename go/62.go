package main

func uniquePaths(m int, n int) int {
	left, right := make([]int, m), make([]int, m)
	for r := 0; r < m; r++ {
		right[r] = 1
	}
	for c := 1; c < n; c++ {
		copy(left, right)
		right[0] = 1
		for r := 1; r < m; r++ {
			right[r] = right[r-1] + left[r]
		}
	}
	return right[m-1]
}
