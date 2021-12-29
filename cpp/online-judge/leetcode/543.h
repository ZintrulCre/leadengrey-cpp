#pragma once

#include "include/std.h"

class Solution {
    int res = 0;
public:
    int postorderTraverse(TreeNode* node) {
        if (!node)
            return 0;
        int left = postorderTraverse(node->left);
        int right = postorderTraverse(node->right);
        res = max(res, left + right);
        return max(left, right) + 1;
    }

    int diameterOfBinaryTree(TreeNode* root) {
        res = 0;
        postorderTraverse(root);
        return res;
    }
};