#pragma once

#include "include/std.h"

class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        vector<int> ind(n, 0), out(n, 0);
        for (vector<int> &t : trust) {
            ++ind[t[0] - 1];
            ++out[t[1] - 1];
        }
        int cnt = 0, res = 0;
        for (int i = 0; i < n; ++i) {
            if (ind[i] == 0 && out[i] == n) {
                res = i + 1;
                ++cnt;
            }
        }
        return cnt == 1 ? res : -1;
    }
};