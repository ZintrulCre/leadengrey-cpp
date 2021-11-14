#pragma once

#include "include/std.h"

class Solution {
    bool Delivery(vector<int>& weights, int days, int capacity) {
        int carry = 0, total = 0;
        for (int w : weights) {
            if (w > capacity)
                return false;
            if (carry + w > capacity) {
                ++total;
                carry = 0;
            }
            carry += w;
        }
        return total + 1 <= days;
    }
public:
    int shipWithinDays(vector<int>& weights, int days) {
        int n = weights.size(), a = 1, b = std::accumulate(weights.begin(), weights.end(), 0), m;
        while (a <= b) {
            m = (b-a)/2 + a;
            if (Delivery(weights, days, m)) {
                b = m - 1;
            } else {
                a = m + 1;
            }
        }
        return a;
    }
};