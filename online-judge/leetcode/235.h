#pragma once

#include "universal/std-pch.h"

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* node, TreeNode* p, TreeNode* q) {
        if (node->val > p->val && node->val > q->val)
            return lowestCommonAncestor(node->left, p, q);
        if (node->val < p->val && node->val < q->val)
            return lowestCommonAncestor(node->right, p, q);
        // if ((node->val - p->val) * (node->val - q->val) <= 0)
        return node;
    }
};
