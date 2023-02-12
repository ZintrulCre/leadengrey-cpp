#pragma once

#include "include/std.h"

class Solution {
    bool covered(unordered_map<char, int> &um, unordered_map<char, int> &comp) {
        for (auto p : comp)
            if (um[p.first] < p.second)
                return false;
        return true;
    }

public:
    string minWindow(string s, string t) {
        string temp = s + 'x', res = temp;
        int n = s.size(), m = t.size(), len = INT_MAX, idx = -1;
        unordered_map<char, int> um, comp;
        for (char c : t)
            ++comp[c];
        for (int l = 0, r = 0; r < n; ++r) {
            ++um[s[r]];
            while (l <= r && covered(um, comp)) {
                if (len > r - l + 1) {
                    len = r - l + 1;
                    idx = l;
                }
                --um[s[l]];
                ++l;
            }
        }
        return idx == -1 ? "" : s.substr(idx, len);
    }
};