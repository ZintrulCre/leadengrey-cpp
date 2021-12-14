#pragma once

#include "include/std.h"

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int idx = 1, n = nums.size();
        if (n == 0)
            return 0;
        for (int i = 1; i < n; ++i)
            if (nums[i] != nums[i-1])
                nums[idx++] = nums[i];
        return idx;
    }
};