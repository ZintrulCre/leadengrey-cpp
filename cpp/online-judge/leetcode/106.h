#pragma once

#include "include/std.h"

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
    TreeNode* buildTree(vector<int>& inorder, int x, int y, vector<int>& postorder, int u, int v) {
        if (x > y)
            return nullptr;
        int val = postorder[v], idx = -1;
        for (int i = x; i <= y; ++i) {
            if (val == inorder[i]) {
                idx = i;
                break;
            }
        }
        int left_len = idx - x;
        TreeNode *left = buildTree(inorder, x, idx - 1, postorder, u, u + left_len - 1);
        TreeNode *right = buildTree(inorder, idx + 1, y, postorder, u + left_len, v - 1);
        return new TreeNode(val, left, right);
    }

public:
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        return buildTree(inorder, 0, inorder.size() - 1, postorder, 0, postorder.size() - 1);
    }
};