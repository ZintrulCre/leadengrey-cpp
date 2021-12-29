#pragma once

#include "include/std.h"

class Solution {
    unordered_map<char, int> m1, m2;

    bool isCovered() {
        for (auto &pair : m2) {
            auto iter = m1.find(pair.first);
            if (iter == m1.end() || iter->second < pair.second)
                return false;
        }
        return true;
    }

public:
    string minWindow(string s, string t) {
        m1 = unordered_map<char, int>(), m2 = unordered_map<char, int>();
        for (char c : t)
            m2[c]++;
        int start = 0, n = s.size(), m = t.size(), minLen = INT_MAX;
        string ret;
        for (int i = 0; i < n; ++i) {
            char c = s[i];
            m1[c]++;
            if (i >= m - 1) {
                while (isCovered()) {
                    if (minLen > i - start + 1) {
                        minLen = i - start + 1;
                        ret = s.substr(start, i - start + 1);
                    }
                    m1[s[start]]--;
                    ++start;
                }
            }
        }
        return ret;
    }
};