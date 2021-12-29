#pragma once

#include "include/std.h"

class Solution {
public:
    string removeDuplicateLetters(string str) {
        vector<int> rec(26, 0);
        vector<uint8_t> used(26, 0);
        for (char c : str)
            rec[c-'a']++;
        string ret;
        for (char c : str) {
            if (!used[c-'a']) {
                while (!ret.empty() && ret.back() >= c && rec[ret.back()-'a'] > 0) {
                    used[ret.back() - 'a'] = 0;
                    ret.pop_back();
                }
                ret += c;
                used[c-'a'] = 1;
            }
            rec[c-'a']--;
        }
        return ret;
    }
};