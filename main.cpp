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

    Solution solution;
    vector<vector<char>> vec {{'A','B','C','E'},{'S','F','C','S'},{'A','D','E','E'}};
    string w{"ABCB"};
    bool res = solution.exist(vec,w);
    leadgrey::Print(res);


    return 0;
}
