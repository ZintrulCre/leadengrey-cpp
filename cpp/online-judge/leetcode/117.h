#pragma once

#include "include/std.h"
#include "online-judge/data-structure.h"

class Solution {
public:
    Node* connect(Node* root) {
        queue<Node*> que;
        if (root)
            que.push(root);
        while ((int m = que.size()) != 0)
        {
            for (int i = m - 1; i >= 0; --i)
            {
                Node* node = que.front();
                que.pop();
                if (!que.empty() && i != 0)
                    node->next = que.front();
                if (node->left)
                    que.push(node->left);
                if (node->right)
                    que.push(node->right);
            }
        }
        return root;
    }
};
