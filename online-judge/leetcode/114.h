#pragma once

#include "include/std.h"

class Solution {
public:
    void flatten(TreeNode* root) {
        TreeNode *node = root, *next = nullptr, *temp = nullptr;
        while (node) {
            if (node->left) {
                next = node->left;
                temp = next;
                while (temp->right)
                    temp = temp->right;
                temp->right = node->right;
                node->left = nullptr;
                node->right = next;
            }
            node = node->right;
        }
    }
};
