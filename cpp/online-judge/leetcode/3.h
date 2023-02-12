#pragma once

#include "include/std.h"

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int start = 0, res = 0;
        unordered_map<char, int> m;
        for (int i = 0; i < s.size(); ++i) {
            if (m.find(s[i]) == m.end())
                m.insert({s[i], -1});
            if (m[s[i]] >= start)
                start = m[s[i]] + 1;
            res = max(res, i - start + 1);
            m[s[i]] = i;
        }
        return res;
    }
};