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
        int x1, x2;
        s1+='.', s2+='.';
        while (!s1.empty() || !s2.empty()) {
            GetSub(s1, x1);
            GetSub(s2, x2);
            if (x1 > x2)    return 1;
            if (x1 < x2)    return -1;
        }
        return 0;
    }

    void GetSub(string& s, int& x) {
        int p = s.find(".");
        string temp = p == -1 ? "0" : s.substr(0, p);
        s = s.substr(p+1);
        while (temp.size() > 1 && temp[0] == '0')
            temp = temp.substr(1);
        x = std::stoi(temp);
    }
};
// @lc code=end

