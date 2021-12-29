package main

func checkValidString(s string) bool {
	a, b := 0, 0
	for _, c := range s {
		if c == '(' {
			a++
			b++
		} else if c == ')' {
			a--
			b--
		} else {
			a++
			b--
		}
		if b < 0 {
			b = 0
		}
		if b > a {
			return false
		}
	}
	return b == 0
}