package main

func findIntegers(n int) int {
	dp := make([]int, 31)
	dp[0], dp[1] = 1, 1
	for i := 2; i < 31; i++ {
		dp[i] = dp[i-1] + dp[i-2]
	}
	prev, ret := 0, 0
	for i := 30; i >= 0; i-- {
		val := 1 << i
		if (n & val) == 0 {
			prev = 0
		} else {
			ret += dp[i+1]
			if prev == 1 {
				break
			}
			prev = 1
		}
		if i == 0 {
			ret++
		}
	}
	return ret
}