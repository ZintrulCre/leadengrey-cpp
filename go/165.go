package main

func compareVersion(s1 string, s2 string) int {
	i1, i2 := 0, 0
	n1, n2 := len(s1), len(s2)

	getSub := func(s *string, i *int, n int) int {
		var v int = 0
		for *i < n && (*s)[*i] != '.' {
			v = v*10 + int((*s)[*i]) - '0'
			*i++
		}
		*i++
		return v
	}

	for i1 < n1 || i2 < n2 {
		v1, v2 := getSub(&s1, &i1, n1), getSub(&s2, &i2, n2)
		if v1 < v2 {
			return -1
		} else if v1 > v2 {
			return 1
		}
	}
	return 0
}
