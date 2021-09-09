#include "include/std.h"
#include "base/base.h"
#include "online-judge/leetcode/leetcode.h"
#include "online-judge/data-structure.h"

void TreeNodeTest()
{
    // TreeNode* a = new TreeNode(7);
    // TreeNode* b = new TreeNode(3);
    // TreeNode* c = new TreeNode(15);
    // TreeNode* d = new TreeNode(9);
    // TreeNode* e = new TreeNode(20);
    // TreeNode* f = new TreeNode(4);
    // TreeNode* h = new TreeNode(6);
    // a->left = b;
    // a->right = c;
    // c->left = d;
    // c->right = e;
    // // leadengrey::Print(a);

    // // Solution solution;
    // BSTIterator tre(a);
    // while(tre.hasNext())
    // {cout << tre.next() << endl;}
    // int res = solution.maxPathSum(a);
    // leadengrey::Print(res);
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
    // vector<vector<int>> board{{'5','3','.','.','7','.','.','.','.'},{'6','.','.','1','9','5','.','.','.'},{'.','9','8','.','.','.','.','6','.'},{'8','.','.','.','6','.','.','.','3'},{'4','.','.','8','.','3','.','.','1'},{'7','.','.','.','2','.','.','.','6'},{'.','6','.','.','.','.','2','8','.'},{'.','.','.','4','1','9','.','.','5'},{'.','.','.','.','8','.','.','7','9'}};

    // vector<vector<int>> test{{1,2},{2,3},{5},{0},{5},{},{}};

    // vector<vector<int>> test{{4,3,1},{3,2,4},{3},{4},{}};
    // Solution solution;
    // auto r = solution.compareVersion("1.2", "1.10");
    // leadengrey::Print(r);
    // r = solution.compareVersion("1.01", "1.001");
    // leadengrey::Print(r);
    // r = solution.compareVersion("1.0", "1.0.0");
    // leadengrey::Print(r);
    // r = solution.compareVersion("0.1", "1.1");
    // leadengrey::Print(r);
    // r = solution.compareVersion("1.0.1", "1");
    // leadengrey::Print(r);
    // r = solution.compareVersion("7.5.2.4", "7.5.3");
    // leadengrey::Print(r);

    // Test()
    // ConcurrencyTest();
    // TreeNodeTest();

    // 502
    // Solution s;
    // vector<int> p{1,2,3}, c{0,1,2};
    // auto r = s.findMaximizedCapital(3, 0, p, c);
    // leadengrey::Print(r);

    //68
    Solution s;
    vector<string> str{"Science","is","what","we","understand","well","enough","to","explain","to","a","computer.","Art","is","everything","else","we","do"};
    vector<string> r;
    r = s.fullJustify(str, 20);
    leadengrey::Print(r);
}

