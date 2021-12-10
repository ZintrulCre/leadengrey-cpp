#pragma once

#include "include/std.h"
#include "online-judge/online-judge.h"

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
    TreeNode *BuildTree(vector<int>& nums, int x, int y) {
        if (x > y)
            return nullptr;
        int m = INT_MIN, idx = -1;
        for (int i = x; i <= y; ++i) {
            if (m < nums[i]) {
                m = nums[i];
                idx = i;
            }
        }
        TreeNode *left = BuildTree(nums, x, idx - 1);
        TreeNode *right = BuildTree(nums, idx + 1, y);
        TreeNode *node = new TreeNode(m, left, right);
        return node;
    }

public:
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        return BuildTree(nums, 0, nums.size() - 1);
    }
};