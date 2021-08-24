#include "leetcode.h"
#include "base/base.h"

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

    vector<vector<int>> test{{0,1,100},{1,2,100},{0,2,500}};
    Solution solution;
    int r = solution.findCheapestPrice(3,test,0,2,1);
    leadengrey::Print(r);

    // Test()
    // ConcurrencyTest();
    // TreeNodeTest();
}

