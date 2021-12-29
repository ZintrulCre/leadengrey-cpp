#pragma once

#include "include/std.h"

class Solution {
public:
    bool escapeGhosts(vector<vector<int>>& gs, vector<int>& t) {
        auto MD = [](int a, int b, int x, int y) { return abs(a-x) + abs(b-y); };
        for (auto& g : gs)
            if (MD(t[0], t[1], 0, 0) >= MD(g[0], g[1], t[0], t[1])) return false;
        return true;
    }
};