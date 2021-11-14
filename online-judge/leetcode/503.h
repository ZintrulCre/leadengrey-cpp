#pragma once

#include "include/std.h"

class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int n = nums.size();
        vector<int> res(n, 0);
        stack<int> s;
        for (int i = n*2 - 1; i >= 0; i--) {
            int k = i%n;
            if (!s.empty()) {
                if (nums[k] < s.top()) {
                    res[k] = s.top();
                } else {
                    while (!s.empty() && nums[k] >= s.top())
                        s.pop();
                    res[k] = s.empty() ? -1 : s.top();
                }
            }
            s.push(nums[k]);
        }
        return res;
    }
};