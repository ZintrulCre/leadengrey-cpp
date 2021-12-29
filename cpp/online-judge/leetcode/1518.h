#pragma once

#include "include/std.h"

class Solution {
public:
    int numWaterBottles(int n, int m) {
        int ret = 0, emp = 0;
        while (n > 0) {
            ret += n;
            printf("ret %d\n", ret);
            emp = n + emp;
            printf("emp %d\n", emp);
            n = emp / m;
            emp = emp % m;
            printf("n %d emp %d\n", n, emp);
        }
        return ret;
    }
};