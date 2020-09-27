#pragma once

#include "universal/std-pch.h"

class Solution {
public:
    vector<double> averageOfLevels(TreeNode* root) {
        vector<double> res;
        queue<TreeNode*> que;
        if (root)
            que.push(root);

        while(!que.empty())
        {
            int m = que.size();
            double avg = 0.0;
            for (int i = 0; i < m; ++i)
            {
                TreeNode* node = que.front();
                que.pop();
                if (node->left)
                    que.push(node->left);
                if (node->right)
                    que.push(node->right);
                
                avg += node->val;
            }
            avg /= m;
            res.emplace_back(avg);
        }
        return res;
    }
};
