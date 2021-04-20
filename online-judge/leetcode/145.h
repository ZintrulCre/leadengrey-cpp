#include "include/std.h"
#include "online-judge/pch.h"

class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> res;
        function<void(TreeNode*)> PostorderTraverse = [&](TreeNode* node) -> void
        {
            if (!node)
                return;
            PostorderTraverse(node->left);
            PostorderTraverse(node->right);
            res.emplace_back(node->val);
        };
        PostorderTraverse(root);
        return res;
    }
};
