#pragma once

#include "online-judge/data-structure.h"

class Solution {
public:
    int numRescueBoats(vector<int>& p, int l) {
        std::sort(p.begin(), p.end());
        int n = p.size(), i = 0, j = n - 1, res = 0;
        while (i < j) {
            if (p[i] + p[j] <= l)
                ++i;
            --j;
            ++res;
        }
        if (i == j)
            ++res;
        return res;
    }
};