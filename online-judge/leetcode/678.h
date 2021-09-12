#pragma once

#include "include/std.h"

// class Solution {
// public:
//     bool checkValidString(string str) {
//         std::stack<int> l, s;
//         for (int i = 0; i < str.size(); ++i) {
//             if (str[i] == '(') {
//                 l.push(i);
//             } else if (str[i] == '*') {
//                 s.push(i);
//             } else {
//                 if (!l.empty()) {
//                     l.pop();
//                 } else if (!s.empty()) {
//                     s.pop();
//                 } else {
//                     return false;
//                 }
//             }
//         }
//         while (!l.empty()) {
//             if (s.empty() || s.top() < l.top())
//                 return false;
//             l.pop();
//             s.pop();
//         }
//         return true;
//     }
// };


class Solution {
public:
    bool checkValidString(string str) {
        int a = 0, b = 0;
        for (int i = 0; i < str.size(); ++i) {
            if (str[i] == '(') {
                ++a, ++b;
            } else if (str[i] == ')') {
                --a, --b;
            } else {
                ++a, --b;
            }
            b = std::max(0, b);
            if (b > a)
                return false;
        }
        return b == 0;
    }
};