#pragma once

#include "include/std.h"

/*
 * @lc app=leetcode.cn id=1894 lang=cpp
 *
 * [1894] 找到需要补充粉笔的学生编号
 */

// @lc code=start
class Solution {
public:
    int chalkReplacer(vector<int>& c, int k) {
        uint64_t s = 0;
        int n = c.size();
        for (int i = 0; i < n; ++i) s += c[i];
        int r = k / s;
        k -= s * r;
        for (int i = 0; i < n; ++i) {
            if (k < c[i])
                return i;
            k -= c[i];
        }
        return 0;
    }
};
// @lc code=end

