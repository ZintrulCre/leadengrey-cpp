#pragma once

#include "include/std.h"

class Solution {
public:
    Node* connect(Node* root) {
        
    }
};


class Solution {
public:
    Node* connect(Node* root) {
        if (!root)
            return nullptr;
        queue<Node*> q;
        q.push(root);
        int s = 1;
        while(!q.empty()) {
            Node *node = q.front();
            q.pop();
            --s;
            if (!q.empty() && s > 0)
                node->next = q.front();
            if (node->left) q.push(node->left);
            if (node->right) q.push(node->right);
            if (s == 0)
                s = q.size();
        }
        return root;
    }
};


class Solution {
public:
    Node* connect(Node* root) {
        Node *node = root;
        while (node) {
            Node *temp = node;
            while (temp) {
                if (temp->left)
                    temp->left->next = temp->right;
                if (temp->right && temp->next)
                    temp->right->next = temp->next->left;
                temp = temp->next;
            }
            node = node->left;
        }
        return root;
    }
};