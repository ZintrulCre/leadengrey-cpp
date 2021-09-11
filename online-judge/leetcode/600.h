#pragma once

#include "include/std.h"

class Solution {
public:
    int findIntegers(int n) {
        vector<int> dp(31, 0);
        dp[0] = dp[1] = 1;
        for (int i = 2; i < 31; ++i)
            dp[i] = dp[i-1] + dp[i-2];

        int prev = 0, ret = 0;
        for (int i = 30; i >= 0; --i) {
            int val = 1 << i;
            if ((n & val) == 0) { // 0
                prev = 0;
            } else { // 1
                ret += dp[i+1];
                if (prev == 1)
                    break;
                prev = 1;
            }

            if (i == 0)
                ++ret;
        }
        return ret;
    }
};