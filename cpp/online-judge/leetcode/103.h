#pragma once

#include "include/std.h"
#include "online-judge/data-structure.h"

// 1

// class Solution {
//     vector<vector<int>> res;

//     void foo(TreeNode* node, int lvl) {
//         if (!node)
//             return;
//         if (res.size() < lvl)
//             res.push_back({});
//         res[lvl-1].push_back(node->val);
//         foo(node->left, lvl+1);
//         foo(node->right, lvl+1);
//     }

// public:
//     vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
//         foo(root, 1);
//         for (int i = 0; i < res.size(); ++i) {
//             if (i % 2 != 0) {
//                 for (int j = 0, k = res[i].size() - 1; j < k; ++j, --k)
//                     swap(res[i][j], res[i][k]);
//             }
//         }
//         return res;
//     }
// };

// 2

class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> res;
        if (!root)
            return res;
        queue<TreeNode*> q;
        q.push(root);
        bool reverse = true;
        int size = 1;
        vector<int> temp;
        while (!q.empty()) {
            TreeNode* node = q.front();
            q.pop();
            cout << node->val << endl;
            for (int i = 0; i < size; ++i) {

            }
            if (reverse) {
                if (node->right)    q.push(node->right);
                if (node->left)    q.push(node->left);
            } else {
                if (node->left)    q.push(node->left);
                if (node->right)    q.push(node->right);
            }
            --size;
            if (size == 0) {
                size = q.size();
                reverse = !reverse;
                res.push_back(temp);
                temp.clear();
            }
        }
        return res;
    }
};
