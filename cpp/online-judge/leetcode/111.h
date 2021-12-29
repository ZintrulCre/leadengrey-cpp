#pragma once


#pragma once

#include "include/std.h"
#include "online-judge/leetcode/pch.h"

class Solution {
public:
    int minDepth(TreeNode* root) {
        if (!root)
            return 0;
        queue<TreeNode*> q;
        q.push(root);
        int lvl = 1, num = 1, next_num = 0;;
        while (!q.empty()) {
            for (int i = 0; i < num; ++i) {
                TreeNode *node = q.front();;
                q.pop();
                if (!node->left && !node->right)
                    return lvl;
                if (node->left) {
                    q.push(node->left);
                    ++next_num;
                }
                if (node->right) {
                    q.push(node->right);
                    ++next_num;
                }
            }
            num = next_num;
            next_num = 0;
            ++lvl;
        }
        return -1;
    }
};