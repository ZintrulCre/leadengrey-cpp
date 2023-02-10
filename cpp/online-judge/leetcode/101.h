#pragma once

#include "include/std.h"

class Solution {
private:
    bool foo(TreeNode* l, TreeNode* r) {
        if (!l && !r)
            return true;
        if (!l || !r)
            return false;
        return foo(l->left, r->right) && foo(l->right, r->left) && l->val == r->val;
    }
public:
    bool isSymmetric(TreeNode* root) {
        return foo(root, root);
    }
};