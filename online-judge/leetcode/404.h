// //
// // Created by ZintrulCre on 2020-09-17.
// //

#include "universal/std-pch.h"

class Solution {
public:
    int sumOfLeftLeaves(TreeNode* root) {
        int res = 0;
        function<void(TreeNode*)> Traverse = [&](TreeNode* node) -> void
        {
            if (!node)
                return;
            auto left = node->left, right = node->right;
            if (left && !left->left && !left->right)
                res += left->val;
            Traverse(left);
            Traverse(right);
        };
        Traverse(root);
        return res;
    }
};
