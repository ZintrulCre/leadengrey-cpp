#pragma once

#include "include/std.h"

class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n = nums.size(), x = 0, y = n-1, i;
        while (x <= y) {
            i = (x+y) / 2;
            if (nums[i] == target)
                return i;
            else if (nums[i] > target)
                y = i-1;
            else
                x = i+1;
        }
        return -1;
    }
};