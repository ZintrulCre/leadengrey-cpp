//
// Created by ZintrulCre on 2020-09-17.
//

#ifndef LEADENGREY_ONLINEJUDGE_LEETCODE_TEST_H
#define LEADENGREY_ONLINEJUDGE_LEETCODE_TEST_H

#include "universal/std-pch.h"
#include "base/print.h"

#include "online-judge/leetcode/data-structure.h"
// #include "online-judge/leetcode/37.h"
// #include "online-judge/leetcode/39.h"
// #include "online-judge/leetcode/40.h"
// #include "online-judge/leetcode/47.h"
// #include "online-judge/leetcode/77.h"
// #include "online-judge/leetcode/78.h"
// #include "online-judge/leetcode/79.h"
// #include "online-judge/leetcode/94.h"
// #include "online-judge/leetcode/216.h"
// #include "online-judge/leetcode/226.h"
// #include "online-judge/leetcode/235.h"
// #include "online-judge/leetcode/404.h"
// #include "online-judge/leetcode/538.h"
// #include "online-judge/leetcode/617.h"
// #include "online-judge/leetcode/637.h"
// #include "online-judge/leetcode/968.h"
// #include "online-judge/leetcode/1114.h"
// #include "online-judge/leetcode/1115.h"

void TreeNodeTest()
{
    TreeNode* a = new TreeNode(3);
    TreeNode* b = new TreeNode(1);
    TreeNode* c = new TreeNode(2);
    TreeNode* d = new TreeNode(7);
    TreeNode* e = new TreeNode(5);
    TreeNode* f = new TreeNode(4);
    TreeNode* h = new TreeNode(6);
    a->left = b;
    a->right = d;
    b->right = c;
    d->left = e;
    e->left = f;
    e->right = h;

    Print(a);
    // Solution solution;
    // int r = solution.minCameraCover(a);
    // leadengrey::Print(r);

}

// void ConcurrencyTest()
// {
//     Foo foo;
//     foo.first();
//     foo.second();
//     foo.third();
// }

void LeetCode()
{
    // ConcurrencyTest();
    // TreeNodeTest();

    // vector<vector<char>> board{{'5','3','.','.','7','.','.','.','.'},{'6','.','.','1','9','5','.','.','.'},{'.','9','8','.','.','.','.','6','.'},{'8','.','.','.','6','.','.','.','3'},{'4','.','.','8','.','3','.','.','1'},{'7','.','.','.','2','.','.','.','6'},{'.','6','.','.','.','.','2','8','.'},{'.','.','.','4','1','9','.','.','5'},{'.','.','.','.','8','.','.','7','9'}};

    // vector<int> test{4,2,1};
    // Solution solution;
    // vector<vector<int>> res = solution.subsets(test);
    // leadengrey::Print(res);
}

#endif