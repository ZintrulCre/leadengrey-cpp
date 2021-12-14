#pragma once

#include "include/std.h"

class Solution {
public:
    vector<int> corpFlightBookings(vector<vector<int>>& bookings, int n) {
        map<int, int> m;
        vector<int> ret(n, 0);
        for (vector<int> &b : bookings) {
            m[b[0]] += b[2];
            m[b[1]+1] -= b[2];
        }
        int acc = 0;
        for (int i = 0; i < n; ++i) {
            acc += m[i+1];
            ret[i] = acc;
        }
        return ret;
    }
};