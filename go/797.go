package main

func allPathsSourceTarget(graph [][]int) (res [][]int) {
	//r := []int{0}
	r := make([]int, 0)
	var dfs func(int)
	dfs = func(i int) {
		r = append(r, i)
		if i == len(graph)-1 {
			res = append(res, append([]int(nil), r...))
		}
		for _, g := range graph[i] {
			dfs(g)
		}
		r = r[:len(r)-1]
	}
	dfs(0)
	return res
}
