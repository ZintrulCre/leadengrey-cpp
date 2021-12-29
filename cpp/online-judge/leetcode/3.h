#pragma once

#include "include/std.h"

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int start = 0, res = 0;
        unordered_map<int, int> m;
        for (int i = 0; i < s.size(); ++i) {
            char c = s[i];
            if (m.find(c-'a') == m.end())
                m[c-'a'] = -1;
            if (m[c-'a'] >= start)
                start = m[c-'a'] + 1;
            res = max(res, i - start + 1);
            m[c-'a'] = i;
            cout << c << ' ' << start << ' ' << res << endl;
        }
        return res;
    }
};