#pragma once

#include "include/std.h"

class Solution {
    struct Node {
        TreeNode* node;
        uint64_t idx;
    };
public:
    int widthOfBinaryTree(TreeNode* root) {
        if (!root)
            return 0;
        int num = 1, res = 0, leftMost = 0;
        queue<Node> s;
        s.push({root, 1});
        while(!s.empty()) {
            Node node = s.front();
            s.pop();
            --num;
            if (node.node->left)
                s.push({node.node->left, node.idx * 2});
            if (node.node->right)
                s.push({node.node->right, node.idx * 2 + 1});
            if (leftMost == 0)
                leftMost = node.idx;
            if (num == 0) {
                num = s.size();
                res = max<int>(res, node.idx - leftMost + 1);
                leftMost = 0;
            }
        }
        return res;
    }
};