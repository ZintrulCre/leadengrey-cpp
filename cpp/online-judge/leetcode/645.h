#pragma once

#include "include/std.h"

class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        vector<int> ret{0, 0};
        int n = nums.size();
        for (int i = 0; i < n; ++i) {
            int idx = abs(nums[i]) - 1;
            if (nums[idx] < 0) {
                ret[0] = abs(nums[i]);
                continue;
            }
            nums[idx] *= -1;
        }
        for (int i = 0; i < n; ++i)
            if (nums[i] > 0)
                ret[1] = i + 1;
        return ret;
    }
};