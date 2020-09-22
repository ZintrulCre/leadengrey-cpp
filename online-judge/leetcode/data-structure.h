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
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
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