#pragma once

#include "include/std.h"

class Solution {
public:
    string reverseWords(string s) {
        int n = s.size(), x = 0, y = 0;
        // trim
        while (y < n) {
            while (y < n && s[y] == ' ')
                ++y;
            while (y < n && s[y] != ' ')
                s[x++] = s[y++];
            if (y < n && s[y] == ' ') {
                s[x++] = ' ';
                ++y;
            }
        }
        if (x - 1 >= 0 && s[x-1] == ' ')
            s.resize(--x);
        else 
            s.resize(x);
        // reverse string
        for (int i = 0; i < x / 2; ++i)
            swap(s[i], s[x-i-1]);
        // reverse words
        n = x, x = 0, y = 0;
        while (y < n) {
            while (y < n && s[y] != ' ')
                ++y;
            for (int i = 0; i < (y-x)/2; ++i)
                swap(s[x+i], s[y-i-1]);
            x = ++y;
        }
        return s;
    }
};