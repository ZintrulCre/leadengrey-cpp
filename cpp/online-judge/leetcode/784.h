#pragma once

#include "include/std.h"

class Solution {
    void Count(vector<int> &rec, string &s) {
        for (char c : s) {
            if (c >= 'a' && c <= 'z')
                rec[c-'a']++;
            else if (c >= 'A' && c <= 'Z')
                rec[c-'A']++;
        }
    }

public:
    string shortestCompletingWord(string licensePlate, vector<string>& words) {
        vector<int> rec(26, 0);
        Count(rec, licensePlate);
        string ret;
        for (string &w : words) {
            vector<int> curr(26, 0);
            Count(curr, w);
            bool b = true;
            for (int i = 0; i < 26; ++i) {
                if (curr[i] < rec[i]) {
                    b = false;
                    break;
                }
            }
            if (b && (ret.size() == 0 || ret.size() > w.size()))
                ret = w;
        }
        return ret;
    }
};