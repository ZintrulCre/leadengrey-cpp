#pragma once

#include "include/std.h"
#include "online-judge/pch.h"

class Solution {
    TreeNode* foo(vector<int>& nums, int i, int n) {
        if (i > n)
            return nullptr;
        if (i == n)
            return new TreeNode(nums[i]);
        int idx = (n + i) / 2;
        return new TreeNode(nums[idx], foo(nums, i, idx - 1), foo(nums, idx + 1, n));
    }

public:
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return foo(nums, 0, nums.size() - 1);
    }
};