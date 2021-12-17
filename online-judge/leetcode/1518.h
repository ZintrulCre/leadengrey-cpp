#pragma once

#include "include/std.h"

class Solution {
public:
    int numWaterBottles(int n, int m) {
        int ret = 0, emp = 0;
        while (n > m) {
            ret += n;

            emp = n + emp;
            n = emp / m;
            emp = n % m;
        }
        return ret;
    }
};