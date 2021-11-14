#pragma once

#include "include/std.h"

class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int n = nums.size(), a = 0, b = n-1, m;
        vector<int> res(2, -1);
        if (n == 0)
            return res;
        while (a <= b) {
            m = (b-a)/2 + a;
            if (nums[m] == target) {
                b = m - 1;
            } else if (nums[m] < target) {
                a = m + 1;
            } else if (nums[m] > target) {
                b = m - 1;
            }
        }
        res[0] = (a < n && nums[a] == target ? a : -1);
        
        a = 0, b = n-1;
        while (a <= b) {
            m = (b-a)/2 + a;
            if (nums[m] == target) {
                a = m + 1;
            } else if (nums[m] < target) {
                a = m + 1;
            } else if (nums[m] > target) {
                b = m - 1;
            }
        }
        res[1] = (b >=0 && nums[b] == target ? b : -1);
        return res;
    }
};