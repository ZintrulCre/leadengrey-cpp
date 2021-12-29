#pragma once

#include "include/std.h"

class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& t) {
        int n = t.size();
        vector<int> res(n, 0);
        stack<int> s;
        for (int i = n-1; i >= 0; --i) {
            if (!s.empty()) {
                int v = t[s.top()];
                if (t[i] < v) {
                    res[i] = s.top() - i;
                } else {
                    while (!s.empty() && t[i] >= v)
                        s.pop();
                    if (!s.empty())
                        res[i] = s.top() - i;
                }
            }
            s.push(i);
            cout << s.top() << endl;
        }
        return res;
    }
};