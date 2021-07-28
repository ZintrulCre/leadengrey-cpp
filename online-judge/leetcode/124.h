#pragma once

#include "include/std.h"
#include "online-judge/online-judge.h"

class Solution {
private:
    int res = INT_MIN;
public:
    int maxPathSum(TreeNode* root) {
        maxPathSumImpl(root);
        return res;
    }
    
    int maxPathSumImpl(TreeNode* node) {
        if (!node)
            return 0;
        int left_val = max(0, maxPathSumImpl(node->left));
        int right_val = max(0, maxPathSumImpl(node->right));
        res = max(res, left_val + node->val + right_val);
        return max(left_val, right_val) + node->val;
    }
};

