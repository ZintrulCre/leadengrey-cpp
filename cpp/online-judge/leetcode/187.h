#pragma once

#include "include/std.h"

class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        int m = 10, n = s.size();
        vector<string> res;
        if (n < m)
            return res;
        string temp = s.substr(0, 10);
        unordered_map<string, int> um;
        for (int i = m; i < n; ++i) {
            temp.erase
        }

    }
};