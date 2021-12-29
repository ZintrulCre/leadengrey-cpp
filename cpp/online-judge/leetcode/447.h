#pragma once

#include "include/std.h"

class Solution {
public:
    int numberOfBoomerangs(vector<vector<int>>& p) {
        int n = p.size(), ret = 0;
        for (int i = 0; i < n; ++i) {
            std::unordered_map<int, int> m;
            for (int j = 0; j < n; ++j) {
                int d = (p[i][0] - p[j][0]) * (p[i][0] - p[j][0]) + (p[i][1] - p[j][1]) * (p[i][1] - p[j][1]);
                ++m[d];
            }
            for (auto& q : m)
                ret += q.second * (q.second - 1);
        }
        return ret;
    }
};