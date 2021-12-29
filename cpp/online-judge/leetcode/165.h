#pragma once

#include "include/std.h"

/*
 * @lc app=leetcode.cn id=165 lang=cpp
 *
 * [165] 比较版本号
 */

// @lc code=start
class Solution {
public:
    int compareVersion(string s1, string s2) {
        int i1 = 0, i2 = 0;
        while (i1 < s1.size() || i2 < s2.size()) {
            int v1 = GetSub(s1, i1), v2 = GetSub(s2, i2);
            if (v1 > v2)    return 1;
            if (v1 < v2)    return -1;
        }
        return 0;
    }

    int GetSub(string& s, int& i) {
        int n = s.size(), v = 0;
        while (i < n && s[i] != '.') {
            v = v*10+s[i]-'0';
            ++i;
        }
        ++i;
        return v;
    }
};
// @lc code=end

