#pragma once

#include "include/std.h"
#include "online-judge/data-structure.h"

class Solution {
public:
    bool isValidBST(TreeNode* root, int *mini = nullptr, int *maxi = nullptr) {
        if (!root)
            return true;
        if ((mini && root->val <= *mini) || (maxi && root->val >= *maxi))
            return false;
        return isValidBST(root->left, mini, &root->val) && isValidBST(root->right, &root->val, maxi);
    }
};