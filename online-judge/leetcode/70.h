#pragma once

#include "include/std.h"

class Solution {
public:
    int numWays(int n) {
        if (n == 0)
            return 0;
        if (n < 3)
            return n;
        int a = 1, b = 2, c = 0;
        for (int i = 0; i < n - 2; ++i) {
            c = (a + b) % 1000000007;
            a = b;
            b = c;
        }
        return c;
    }
};