#include "base/pch.h"
#include "design-pattern/pch.h"
#include "online-judge/pch.h"

int main()
{
    // uint8 a{200}, b{60};
    // uint8 temp = LeadGrey::Minus(b, a);
    // std::cout << typeid(temp).name() << ' ' << static_cast<uint32>(temp) << std::endl;
    // int a, b, c;
    // std::cin >> a >> b >> c;
    // std::cout << LeadGrey::Add<int>() << std::endl;

    // uint16 a, b;
    // cin >> a >> b;
    // cout << LeadGrey::Max(a) << endl;
    // cout << LeadGrey::Max(int(3)) << endl;
    // std::cout << LeadGrey::Minus(a, b) << std::endl;
    
    // SingletonTest();

    // TreeNode* a = new TreeNode(1);
    // TreeNode* b = new TreeNode(2);
    // TreeNode* c = new TreeNode(3);
    // TreeNode* d = new TreeNode(4);
    // TreeNode* e = new TreeNode(5);
    // TreeNode* f = new TreeNode(6);
    // TreeNode* h = new TreeNode(7);
    // a->left = b;
    // b->right = c;
    // a->right = e;
    // e->left = f;
    // f->right = h;

    vector<vector<char>> board{{'5','3','.','.','7','.','.','.','.'},{'6','.','.','1','9','5','.','.','.'},{'.','9','8','.','.','.','.','6','.'},{'8','.','.','.','6','.','.','.','3'},{'4','.','.','8','.','3','.','.','1'},{'7','.','.','.','2','.','.','.','6'},{'.','6','.','.','.','.','2','8','.'},{'.','.','.','4','1','9','.','.','5'},{'.','.','.','.','8','.','.','7','9'}};

    Solution solution;
    vector<int> res;
    solution.solveSudoku(board);
    leadgrey::Print(board);

    // vector<vector<char>> vec {{'A','B','C','E'},{'S','F','C','S'},{'A','D','E','E'}};
    // string w{'ABCB'};
    // bool res = solution.exist(vec,w);
    // leadgrey::Print(res);


    return 0;
}
