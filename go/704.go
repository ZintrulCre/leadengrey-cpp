package main

func search(nums []int, target int) int {
	x, y, i := 0, len(nums)-1, 0
	for x <= y {
		i = (x + y) >> 1
		if nums[i] == target {
			return i
		} else if nums[i] < target {
			x = i + 1
		} else {
			y = i - 1
		}
	}
	return -1
}
