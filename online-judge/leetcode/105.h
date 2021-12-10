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
    TreeNode* buildTree(vector<int>& preorder, int x, int y, vector<int>& inorder, int u, int v) {
        if (x > y)
            return nullptr;
        int val = preorder[x];
        int pos = 0;
        for (int i = u; i <= v; ++i) {
            if (inorder[i] == val) {
                pos = i;
                break;
            }
        }
        int left_len = pos - u;
        TreeNode *left = buildTree(preorder, x + 1, x + left_len, inorder, u, pos - 1);
        TreeNode *right = buildTree(preorder, x + left_len + 1, y, inorder, pos + 1, v);
        return new TreeNode(val, left, right);
    }

public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        return buildTree(preorder, 0, preorder.size() - 1, inorder, 0, inorder.size() - 1);
    }
};