#pragma once

#include "include/std.h"

class Solution {
public:
    vector<int> corpFlightBookings(vector<vector<int>>& bookings, int n) {
        vector<int> s(n + 1, 0), res(n, 0);
        for (vector<int> &b : bookings) {
            s[b[0]] += b[2];
            s[b[1] + 1] -= b[2];
        }
        for (int i = 0; i < n; ++i)
            res[i] += s[i];
        return res;
    }
};