#pragma once

#include "include/std.h"

class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int n = nums.size();
        int x = 0, y = nums.size() - 1;
        if (n == 1)
            return 0;
        if (nums[0] > nums[1])
            return 0;
        if (nums[y] > nums[y-1])
            return y;
        while (x <= y) {
            int m = (x + y) / 2;
            if (m-1 >= 0 && nums[m] > nums[m-1] && m+1 < n && nums[m] > nums[m+1])
                return m;
            else if (m-1 >= 0 && nums[m] < nums[m-1])
                y = m - 1;
            else if (m+1 < n && nums[m] < nums[m+1])
                x = m + 1;
        }
        return 0;
    }
};