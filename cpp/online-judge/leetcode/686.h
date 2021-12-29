#pragma once

#include "base/base.h"
#include "include/std.h"

// class Solution {
// public:
//     int repeatedStringMatch(string a, string b) {
//         unordered_map<char, int> m1, m2;
//         for (char c : a)
//             m1[c]++;
//         for (char c : b)
//             m2[c]++;
//         int min_m = 0;
//         for (char c : a)
//             min_m = max(min_m, m2[c] / m1[c] + (m2[c] % m1[c] == 0 ? 0 : 1));
//         for (char c : b)
//             if (m2[c] > 0 && m1[c] == 0)
//                 return -1;
//         string temp;
//         for (int i = 0; i < min_m; ++i)
//             temp += a;
//         if (temp.find(b) != string::npos)
//             return min_m;
//         temp += a;
//         return temp.find(b) != string::npos ? min_m + 1 : -1;
//     }
// };

class Solution {
public:
    int repeatedStringMatch(string a, string b) {
        int m = a.size(), n = b.size();
        string s;
        int l = 0;
        while (l * m < n) {
            s.append(a);
            ++l;
        }
        if (s.find(b) != string::npos)
            return l;
        s.append(a);
        return s.find(b) != string::npos ? l + 1 : -1;
    }
};