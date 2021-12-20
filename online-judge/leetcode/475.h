#pragma once

#include "include/std.h"

class Solution {
    vector<int> houses, heaters;
    int nh;

    bool Check(int radius) {
        int i = 0, j = 0;
        int hi = 0;
        while (j < nh && hi < heaters.size()) {
            if (heaters[hi] - radius > houses[i])
                return false;
            while (j < nh && houses[j] <= heaters[hi] + radius)
                ++j;
            i = j;
            ++hi;
        }
        return j == nh;
    }

public:
    int findRadius(vector<int>& houses, vector<int>& heaters) {
        nh = houses.size();
        this->houses = houses;
        this->heaters = heaters;
        sort(this->houses.begin(), this->houses.end());
        sort(this->heaters.begin(), this->heaters.end());
        int x = 0, y = 1000000000, z;
        while (x < y) {
            z = x + (y - x) / 2;
            printf("z %d\n", z);
            if (Check(z)) {
                y = z;
            } else {
                x = z + 1;
            }
        }
        return y;
    }
};