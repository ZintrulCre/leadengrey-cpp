#pragma once

#include "include/std.h"

// class Solution {
// public:
//     int missingNumber(vector<int>& nums) {
//         int ret = 0;
//         for (int m : nums)
//             ret ^= m;
//         for (int i = 0; i <= nums.size(); ++i)
//             ret ^= m;
//         return ret;
//     }
// };

class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int ret = 0, n = nums.size();
        for (int i = 0; i < n; ++i)
            ret += i - nums[i];
        ret += n;
        return ret;
    }
};