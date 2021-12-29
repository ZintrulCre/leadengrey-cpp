#pragma once

#include "include/std.h"

class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int n = nums.size(), ret = 0;
        vector<int> prefix(n+1, 0);
        for (int i = 1; i <= n; ++i)
            prefix[i] = prefix[i-1] +nums[i-1];
        unordered_map<int, int> m;
        for (int i = 0; i <= n; ++i) {
            ret += m[prefix[i]-k];
            ++m[prefix[i]];
        }
        return ret;
    }
};