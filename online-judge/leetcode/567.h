#pragma once

#include "include/std.h"

class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        unordered_map<char, int> m1, m2;
        for (char c : s1)
            m1[c]++;
        int m = s1.size(), n = s2.size(), start = 0;
        for (int i = 0; i < n; ++i) {
            char c = s2[i];
            m2[c]++;
            while (m2[c] > m1[c]) {
                --m2[s2[start]];
                ++start;
            }
            if (i - start + 1 == m)
                return true;
        }
        return false;
    }
};