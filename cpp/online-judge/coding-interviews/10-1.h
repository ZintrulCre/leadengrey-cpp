#pragma once

#include "include/std.h"

class Solution {
public:
    int fib(int n) {
        if (n<2) return n;
        int a=0, b=1, c;
        for (int i=2; i<=n; ++i) {
            c = b;
            b = (a+b)%1000000007;
            a = c;
        }
        return b;
    }
};