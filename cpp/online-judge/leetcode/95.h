#pragma once

#include "include/std.h"
#include "online-judge/pch.h"

class Solution {
    TreeNode* deepCopy(TreeNode* node, int offset) {
        if (!node)
            return nullptr;
        return new TreeNode(node->val + offset, deepCopy(node->left, offset), deepCopy(node->right, offset));
    }

public:
    vector<TreeNode*> generateTrees(int n) {
        vector<TreeNode*> res;
        vector<vector<TreeNode*>> dp(n+1, vector<TreeNode*>());
        dp[0].push_back(nullptr);
        dp[1].push_back(new TreeNode(1));
        for (int i = 2; i <= n; ++i)
            for (int root = 1; root <= i; ++root)
                for (TreeNode* l : dp[root-1])
                    for (TreeNode* r : dp[i-root]) {
                        auto temp = deepCopy(r, root);
                        dp[i].push_back(new TreeNode(root, l, temp));
                        // printf("%d %d ", i, root);
                        // if(l) printf("l %d ", l->val);
                        // if(temp) printf("r %d ", temp->val);
                        // printf("\n");
                    }
        return dp[n];
    }
};