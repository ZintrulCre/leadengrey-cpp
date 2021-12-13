#pragma once

#include "include/std.h"
#include "online-judge/pch.h"

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
public:
    vector<TreeNode*> generateTrees(int n) {
        vector<TreeNode*> ret;
        vector<vector<TreeNode*>> dp(n + 1, vector<TreeNode*>());
        dp[0].push_back(nullptr);
        dp[1].push_back(new TreeNode(1));
        for (int i = 2; i <= n; ++i)
            for (int j = 1; j <= i; ++j)
                for (TreeNode* left : dp[j-1])
                    for (TreeNode* right : dp[i-j])
                        dp[i].push_back(new TreeNode(j, left, right));
        for (int i = 0; i <= n; ++i)
            for (TreeNode *node : dp[i])
                ret.push_back(node);
        return ret;
    }
};