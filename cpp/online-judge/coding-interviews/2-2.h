#pragma once

#include "include/std.h"

class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        int x = 0;
        for (int m : nums)
            x ^= m;
        int k = 1;
        while ((k & x) == 0)
            k <<= 1;
        vector<int> a, b;
        for (int m : nums) {
            if ((k ^ (m & k)) == 0)
                a.push_back(m);
            else
                b.push_back(m);
        }
        int y = 0, z = 0;
        for (auto m : a)
            y ^= m;
        for (auto m : b)
            z ^= m;
        return {y, z};
    }
};