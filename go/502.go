package main

import (
	"container/heap"
	"sort"
)

/*
 * @lc app=leetcode.cn id=502 lang=golang
 *
 * [502] IPO
 */

// @lc code=start
func findMaximizedCapital(k int, w int, p []int, c []int) int {
	n := len(p)
	type s struct { p, c int }
	v := make([]s, n)
	for i := 0; i < n; i++ {
		v[i] = s{p[i], c[i]}
	}
	sort.Slice(v, func(i, j int) bool { return v[i].c < v[j].c })

	h := &hp{}
	i := 0
	for k > 0 {
		for i < n {
			if v[i].c > w {
				break
			}
			heap.Push(h, v[i].p)
			i++
		}
		if h.Len() == 0 {
			break
		}
		w += heap.Pop(h).(int)
		k--
	}
    return w
}

type hp struct{ sort.IntSlice }
func (h hp) Less(i, j int) bool  { return h.IntSlice[i] > h.IntSlice[j] }
func (h *hp) Push(v interface{}) { h.IntSlice = append(h.IntSlice, v.(int)) }
func (h *hp) Pop() interface{}   { a := h.IntSlice; v := a[len(a)-1]; h.IntSlice = a[:len(a)-1]; return v }

// @lc code=end

