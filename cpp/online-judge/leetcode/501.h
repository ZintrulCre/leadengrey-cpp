// //
// // Created by ZintrulCre on 2020-09-17.
// //

#pragma once

#include "include/std.h"
#include "online-judge/pch.h"

class Solution {
public:
    vector<int> findMode(TreeNode* root) {
        vector<int> res;
        int count{ 0 }, max_count{ 0 };
        TreeNode* prev{ nullptr };
        function<void(TreeNode*)> InorderTraverse = [&](TreeNode* node) -> void
        {
            if (!node)
                return;
            InorderTraverse(node->left);

            if (!prev || prev->val != node->val)
            {
                prev = node;
                count = 0;
            }

            ++count;
            if (count > max_count)
            {
                vector<int>().swap(res);
                max_count = count;
            }
            if (count == max_count)
                res.emplace_back(node->val);

            InorderTraverse(node->right);
        };
        InorderTraverse(root);
        return res;
    }
};
