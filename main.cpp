#include "Base/base.h"

#include <iostream>
#include <stdio.h>

int main() {
    // uint8 a{200}, b{60};
    // uint8 temp = LeadGrey::Minus(b, a);
    // std::cout << typeid(temp).name() << ' ' << static_cast<uint32>(temp) << std::endl;
    // int a, b, c;
    // std::cin >> a >> b >> c;
    // std::cout << LeadGrey::Add<int>() << std::endl;
    uint16 a, b;
    std::cin >> a >> b;
    std::cout << LeadGrey::Minus(a, b) << std::endl;

    return 0;
}
