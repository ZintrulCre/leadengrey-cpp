#pragma once

#include "include/std.h"

class Solution {
public:
    bool carPooling(vector<vector<int>>& trips, int capacity) {
        int n = trips.size();
        vector<int> s(n, 0);
        for (vector<int> &t : trips) {
            s[t[1]] += t[0];
            s[t[2]] -= t[0];
        }
        for (int i = 0; i < n; ++i) {
            capacity -= s[i];
            if (capacity < 0)
                return false;
        }
        return true;
    }
};