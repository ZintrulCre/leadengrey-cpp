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
    int Traverse(TreeNode *node, int root_value) {
        if (!node)
            return 0;
        int right = Traverse(node->right, root_value);
        int left = Traverse(node->left, right + node->val + root_value);
        int ret = left + right + node->val;
        node->val += right + root_value;
        return ret;
    }

public:
    TreeNode* bstToGst(TreeNode* root) {
        Traverse(root, 0);
        return root;
    }
};