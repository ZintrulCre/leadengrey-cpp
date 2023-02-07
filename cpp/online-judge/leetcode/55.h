#pragma once

#include "include/std.h"
#include "base/base.h"

class Solution {
public:
    bool canJump(vector<int>& nums) {
        int l = 0, r = 0, n = nums.size();
        for (int i = 0; i < n; ++i)
            if (l <= i && i <= r)
                r = max(r, i + nums[i]);
        return r >= n;
    }
};