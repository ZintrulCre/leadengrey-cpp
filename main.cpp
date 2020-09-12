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

    Solution solution;
    vector<vector<int>> res = solution.combinationSum3(3, 9);
    leadgrey::Print(res);

    SingletonTest();

    return 0;
}
