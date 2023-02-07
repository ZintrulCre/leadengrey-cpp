#pragma once

#include "include/std.h"

// abstract a pre-0-indexed element

class Solution {
public:
    int jump(vector<int>& nums) {
        int n = nums.size(), rm = 0, end = 0, res = 0;
        for (int i = 0; i < n-1; ++i) {
            rm = max(rm, i+nums[i]);
            if (i == end) {
                ++res;
                end = rm;
            }
        }
        return res;
    }
};

// [2,3,1,1,4]