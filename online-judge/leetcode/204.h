#pragma once

#include "include/std.h"

class Solution {
public:
    int countPrimes(int n) {
        vector<bool> rec(n, true);
        for (int i = 2; i * i < n; i++)
            for (int j = i * i; j < n; j += i)
                rec[j] = false;
        int res = 0;
        for (int i = 2; i < n; i++)
            res += rec[i];
        return res;
    }
};