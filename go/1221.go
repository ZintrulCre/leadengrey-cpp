package main

/*
 * @lc app=leetcode.cn id=1221 lang=golang
 *
 * [1221] 分割平衡字符串
 */

// @lc code=start
func balancedStringSplit(s string) int {
	ret, m := 0, 0
	for i := 0; i < len(s); i++ {
		if s[i] == 'L' {
			m++
		} else if s[i] == 'R' {
			m--
		}
		if m == 0 {
			ret++
		}
	}
	return ret
}
// @lc code=end

