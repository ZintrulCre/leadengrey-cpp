#pragma once

#include "include/std.h"

class Solution {
public:
    string findLongestWord(string s, vector<string>& d) {
        std::sort(d.begin(), d.end(), [](const string& s1, const string& s2) {
            if (s1.size() == s2.size())
                return s1 < s2;
            return s1.size() > s2.size();
        });
        for (string& x : d) {
            int i = 0, j = 0;
            while (i < s.size() && j < x.size()) {
                if (s[i] == x[j])
                    ++j;
                ++i;
            }
            if (j == x.size())
                return x;
        }
        return "";
    }
};