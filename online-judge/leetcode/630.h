#pragma once

#include "include/std.h"

class Solution {
public:
    int scheduleCourse(vector<vector<int>>& c) {
        sort(c.begin(), c.end(), [](const auto &lhs, const auto &rhs) {
            return lhs[1] < rhs[1];
        });
        priority_queue<int> h;
        int sum = 0;
        for (const auto &p : c) {
            int du = p[0], end = p[1];
            if (sum + du <= end) {
                sum += du;
                h.push(du);
            } else if (!h.empty() && h.top() > du) {
                sum -= h.top() - du;
                h.pop();
                h.push(du);
            }
        }
        return h.size();
    }
};