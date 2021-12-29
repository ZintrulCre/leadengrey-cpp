#pragma once

#include "include/std.h"
#include "online-judge/online-judge.h"

class BSTIterator {
    std::stack<TreeNode*> s;
public:
    BSTIterator(TreeNode* root) {
        s = std::stack<TreeNode*>();
        while (root)
        {
            s.push(root);
            root = root->left;
        }
    }
    
    int next() {
        TreeNode* root = s.top();
        s.pop();
        
        auto node = root->right;
        while (node)
        {
            s.push(node);
            node = node->left;
        }

        return root->val;
    }
    
    bool hasNext() {
        return !s.empty();
    }
};
