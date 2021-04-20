//
// Created by ZintrulCre on 2020-09-17.
//

#pragma once


#include "include/std.h"
#include "online-judge/leetcode/pch.h"

class Solution {
public:
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        vector<vector<int>> res;
        vector<int> curr;
        int remain{ sum };
        function<void(TreeNode*)> PreorderTraverse = [&](TreeNode* node) -> void
        {
            if (!node)
                return;
            remain -= node->val;
            curr.push_back(node->val);
            if (!node->left && !node->right && remain == 0)
                res.push_back(curr);
            PreorderTraverse(node->left);
            PreorderTraverse(node->right);
            curr.pop_back();
            remain += node->val;
        };
        PreorderTraverse(root);
        return res;
    }
};
