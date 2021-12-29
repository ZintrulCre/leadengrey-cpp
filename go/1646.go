package main

func getMaximumGenerated(n int) int {
	if n < 2 {
		return n
	}
	v := make([]int, n+1)
	v[0] = 0
	v[1] = 1
	for i := 1; i <= n/2; i++ {
		v[i*2] = v[i]
		if i*2+1 <= n {
			v[i*2+1] = v[i] + v[i+1]
		}
	}
	maxVal := 0
	for _, val := range v {
		if maxVal < val {
			maxVal = val
		}
	}
	return maxVal
}
