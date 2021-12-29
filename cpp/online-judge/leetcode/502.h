#pragma once

#include "include/std.h"

/*
 * @lc app=leetcode.cn id=502 lang=cpp
 *
 * [502] IPO
 */

// @lc code=start
class Solution {
public:
    int findMaximizedCapital(int k, int w, vector<int>& p, vector<int>& c) {
        int n = p.size();
        std::vector<std::pair<int,int>> v;
        for (int i = 0; i < n; ++i)
            v.emplace_back(std::pair<int, int>{p[i], c[i]});
        std::sort(v.begin(), v.end(), [](const std::pair<int,int> &p1, const std::pair<int,int> &p2) {
            return p1.second < p2.second;
        });

        int i = 0;
        std::priority_queue<std::pair<int, int>> h;
        while (k--) {
            while (i < n) {
                if (v[i].second > w)
                    break;
                h.push(v[i]);
                ++i;
            }
            if (h.empty())
                break;
            auto k = h.top();
            w += k.first;
            h.pop();
        }
        return w;
    }
};
// @lc code=end

