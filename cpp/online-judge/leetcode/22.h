#pragma once

#include "include/std.h"

class Solution {
    int n;
    vector<string> ret;

    void Backtracking(string &str, int idx, int ep, int up) {
        if (idx == n * 2) {
            ret.push_back(str);
            return;
        }
        if (ep) {
            str.push_back(')');
            Backtracking(str, idx+1, ep-1, up);
            str.pop_back();
        }
        if (up) {
            str.push_back('(');
            Backtracking(str, idx+1, ep+1, up-1);
            str.pop_back();
        }
    }


public:
    vector<string> generateParenthesis(int n) {
        this->n = n;
        ret = vector<string>();
        string str;
        Backtracking(str, 0, 0, n);
        return ret;
    }
};