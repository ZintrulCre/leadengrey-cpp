package main

import "sort"

func numRescueBoats(people []int, limit int) int {
	sort.Ints(people)
	i, j, res := 0, len(people)-1, 0
	for i < j {
		if people[i]+people[j] <= limit {
			i++
		}
		j--
		res++
	}
	if i == j {
		res++
	}
	return res
}
