#pragma once

#include "include/std.h"

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
    int incre;
    unordered_map<string, int> id_map;
    unordered_map<int, int> counter;
    vector<TreeNode*> ret;

    int generateID(TreeNode *node) {
        if (!node)
            return -1;
        int left = generateID(node->left);
        int right = generateID(node->right);
        string s = to_string(node->val) + "," + to_string(left) + to_string(right);
        auto iter = id_map.find(s);
        if (iter == id_map.end())
            id_map[s] = incre++;
        int id = id_map[s];
        counter[id]++;
        if (counter[id] == 2)
            ret.emplace_back(node);
        return id;
    }

public:
    vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
        incre = 1;
        id_map = unordered_map<string, int>();
        counter = unordered_map<int, int>();
        ret = vector<TreeNode*>();
        generateID(root);
        return ret;
    }
};

