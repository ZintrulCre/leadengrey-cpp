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

#endif