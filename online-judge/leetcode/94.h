#include "universal/std-pch.h"

class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> res;
        stack<TreeNode*> stk;
        if (root)
            stk.push(root);
        while (!stk.empty())
        {
            TreeNode* node = stk.top();
            stk.pop();
            if (node->left)
            {
                while (node)
                {
                    stk.push(node);
                    TreeNode* temp = node;
                    node = node->left;
                    temp->left = nullptr;
                }
                continue;
            }

            res.push_back(node->val);
            leadengrey::Print(res);
            if (node->right)
                stk.push(node->right);
        }
        return res;
    }
};
