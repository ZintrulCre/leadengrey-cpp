#pragma once

#include "include/std.h"

class Solution {
public:
    bool carPooling(vector<vector<int>>& trips, int capacity) {
        map<int, int> m;
        for (auto& t : trips) {
            m[t[1]] += t[0];
            m[t[2]] -= t[0];
            cout <<  m[t[1]] << ' ' << m[t[2]] << endl;
        }
        int sum = 0;
        for (auto p : m) {
            sum += p.second;
            if (sum > capacity)
                return false;
        }
        return true;
    }
};