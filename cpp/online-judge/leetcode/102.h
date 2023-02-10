#pragma once

#include "include/std.h"
#include "online-judge/data-structure.h"

class Solution {

    vector<vector<int>> res;

    void foo(TreeNode* node, int lvl) {
        if (!node)
            return;
        if (res.size() < lvl)
            res.push_back({});
        res[lvl-1].push_back(node->val);
        foo(node->left, lvl+1);
        foo(node->right, lvl+1);
    }

public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        foo(root, 1);
        return res;
    }
};