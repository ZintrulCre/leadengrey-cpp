#pragma once

#include "include/std.h"

class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        unordered_map<char, int> s_map, p_map;
        for (char c : p)
            p_map[c]++;
        int m = p.size(), n = s.size(), start = 0;
        vector<int> ret;
        for (int i = 0; i < n; i++) {
            ++s_map[s[i]];
            while (s_map[s[i]] > p_map[s[i]]) {
                --s_map[s[start]];
                ++start;
            }
            if (i - start + 1 == m)
                ret.emplace_back(start);
        }
        return ret;
    }
};