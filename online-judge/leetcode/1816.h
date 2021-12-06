#pragma once

#include "include/std.h"

class Solution {
public:
    string truncateSentence(string s, int k) {
        int i = 0, n = s.size();
        while (i < n) {
            if (s[i] == ' ') {
                --k;
                if (k == 0) {
                    return s.substr(0, i);
                }
            }
            ++i;
        }
        return s;
    }
};