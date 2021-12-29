package main

func fib(n int) int {
	if n < 2 {
		return n
	}
	a, b, c := 0, 1, 0
	for i := 2; i <= n; i++ {
		c = b
		b = (a + b) % 1000000007
		a = c
	}
	return b
}
