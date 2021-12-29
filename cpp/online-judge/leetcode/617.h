#pragma once

#include "include/std.h"
#include "online-judge/pch.h"

// class Solution {
// public:
//     TreeNode* mergeTrees(TreeNode* t1, TreeNode* t2) {
//         if (!t1 && !t2)
//             return nullptr;
//         TreeNode *t = t1;
//         if (!t1)
//             t = t2;
//         else if (t2)
//             t->val += t2->val;
//         t->left = mergeTrees(t1 ? t1->left : nullptr, t2 ? t2->left : nullptr);
//         t->right = mergeTrees(t1 ? t1->right : nullptr, t2 ? t2->right : nullptr);
//         return t;
//     }
// };

class Solution {
public:
    TreeNode* mergeTrees(TreeNode* t1, TreeNode* t2) {
        if (!t1)
            return t2;
        if (!t2)
            return t1;
        t1->left = mergeTrees(t1->left, t2->left);
        t1->right = mergeTrees(t1->right, t2->right);
        t1->val += t2->val;
        return t1;
    }
};
