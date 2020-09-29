//
// Created by ZintrulCre on 2020-09-17.
//

#ifndef LEADGREY_ONLINEJUDGE_LEETCODE_DATASTRUCTURE_H
#define LEADGREY_ONLINEJUDGE_LEETCODE_DATASTRUCTURE_H

#include "universal/std-pch.h"

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};

void Print(TreeNode *root) {
    if (!root)
        return;
    queue<TreeNode *> que;
    que.push(root);
    while (!que.empty()) {
        auto curr = que.front();
        cout << curr->val << ' ';
        que.pop();
        if (curr->left)
            que.push(curr->left);
        if (curr->right)
            que.push(curr->right);
    }
    cout << endl;
}


#endif