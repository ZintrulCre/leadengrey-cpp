#pragma once

#include "include/std.h"

class Solution {
    int Count(int z) {
        int m = 0;
        while (z > 5) {
            m += z / 5;
            z /= 5;
        }
        return m;
    }

public:
    int preimageSizeFZF(int k) {
        int x = 0, y = INT_MAX, z;
        while (x < y) {
            z = x + (y - x) / 2;
            int m = Count(z);
            if (m > k)
                y = z - 1;
            else if (m < k)
                x = z + 1;
            else
                return 5;
        }
        return 0;
    }
};