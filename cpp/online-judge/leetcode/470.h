#pragma once

#include "include/std.h"

// The rand7() API is already defined for you.
// int rand7();
// @return a random integer in the range 1 to 7

class Solution {
public:
    int rand10() {
        while (true) {
            int m = rand7()-1 + (rand7()-1)*7;
            if (m < 40)
                return m % 10 + 1;
        }
        return 0;
    }
};