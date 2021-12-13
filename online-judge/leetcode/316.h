#pragma once

#include "include/std.h"

struct STK {
    void push() {

    }

    void pop() {
        
    }
}

class Solution {
public:
    string removeDuplicateLetters(string s) {
        unordered_map<char> ori;
        for (char c : s)
            ori[c]++;
        stack<char> stk;
        string ret;
        int i = 0, n = s.size();
        while (!ori.empty()) {
            char c = s[i];
            if (ori[c] > 0) {

            }
            ++i;
        }
    }
};