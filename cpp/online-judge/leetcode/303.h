#pragma once

#include "include/std.h"
#include "online-judge/data-structure.h"

class NumArray {
    vector<int> prefix;

public:
    NumArray(vector<int>& nums) {
        int n = nums.size();
        prefix = vector<int>(n + 1);
        prefix[0] = 0;
        for (int i = 0; i < n; ++i)
            prefix[i+1] = prefix[i] + nums[i];
    }
    
    int sumRange(int left, int right) {
        return prefix[right + 1] - prefix[left];
    }
};
