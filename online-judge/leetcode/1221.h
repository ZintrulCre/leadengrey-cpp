#pragma once

#include "include/std.h"

/*
 * @lc app=leetcode.cn id=1221 lang=cpp
 *
 * [1221] 分割平衡字符串
 */

// @lc code=start
class Solution {
public:
    int balancedStringSplit(string s) {
        int ret = 0, m = 0;
        for (int i = 0; i < s.size(); ++i) {
            if (s[i] == 'L')    ++m;
            if (s[i] == 'R')    --m;
            if (m == 0) ++ret;
        }
        return ret;
    }
};
// @lc code=end

