#pragma once

#include "include/std.h"

class Solution {
public:
    int getMaximumGenerated(int n) {
        if (n == 0) return 0;
        if (n == 1) return 1;
        vector<int> v(n + 1, 0);
        v[0] = 0, v[1] = 1;
        for (int i = 1; i <= n / 2; ++i) {
            v[i*2] = v[i];
            if (i*2+1 <= n) v[i*2+1] = v[i]+v[i+1];
        }
        return *std::max_element(v.begin(), v.end());
    }
};