#pragma once

#include "include/std.h"

class Solution {
public:
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        vector<string> ret;
        int n = words.size(), i = 0, s = 0, l = 0, e = 0;
        string str;
        while (i < n) {
            s = i;
            e = 0, l = 0;
            while (i < n && l + e + (i > s ? 1 : 0) + words[i].size() <= maxWidth) {
                l += words[i].size();
                if (i > s)
                    ++e;
                ++i;
            }
            if (i == n) {
                e = maxWidth;
                for (int x = s; x < i; ++x) {
                    str.append(words[x]);
                    e -= words[x].size();
                    if (e > 0) {
                        str.append(" ");
                        --e;
                    }
                }
                for (int y = 0; y < e; ++y)
                    str.append(" ");
                ret.emplace_back(str);
                cout << str << endl;
                break;
            }
            int b = i - s - 1 == 0 ? (maxWidth - l) : (maxWidth - l) / (i - s - 1);
            int p = i - s - 1 == 0 ? 0 : (maxWidth - l) % (i - s - 1);
            for (int x = s; x < i; ++x) {
                str.append(words[x]);
                if (str.size() < maxWidth) {
                    for (int y = 0; y < b; ++y)
                        str.append(" ");
                }
                if (p > 0) {
                    str.append(" ");
                    --p;
                }
            }
            cout << str << endl;
            ret.emplace_back(str);
            str.clear();
        }
        return ret;
    }
};