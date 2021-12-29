package main

func checkRecord(n int) int {
	MOD := 1000000007

	var prev, curr [2][3]int
	curr[0][0] = 1 // p
	curr[1][0] = 1 // a
	curr[0][1] = 1 // l

	for i := 1; i < n; i++ {
		prev = curr
		// p
		for a := 0; a < 2; a++ {
			curr[a][0] = 0
			for l := 0; l < 3; l++ {
				curr[a][0] = (curr[a][0] + prev[a][l]) % MOD
			}
		}
		// a
		for l := 0; l < 3; l++ {
			curr[1][0] = (curr[1][0] + prev[0][l]) % MOD
		}
		// l
		for a := 0; a < 2; a++ {
			for l := 1; l < 3; l++ {
				curr[a][l] = prev[a][l-1]
			}
		}
	}

	res := 0
	for a := 0; a < 2; a++ {
		for l := 0; l < 3; l++ {
			res = (res + curr[a][l]) % MOD
		}
	}

	return res
}
