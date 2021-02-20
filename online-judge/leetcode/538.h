//
// Created by ZintrulCre on 2020-09-22.
//

#include "universal/std-pch.h"
#include "online-judge/pch.h"

class Solution {
public:
    TreeNode* convertBST(TreeNode* root) {
        function<int(TreeNode*, int)> Traverse = [&](TreeNode* node, int root_val) -> int
        {
            if (!node)
                return 0;
            int right_val = Traverse(node->right, root_val);
            int left_val = Traverse(node->left, root_val + right_val + node->val);
            int ret_val = node->val + left_val + right_val;
            node->val += right_val + root_val;
            return ret_val;
        };
        Traverse(root, 0);
        return root;
    }
};
