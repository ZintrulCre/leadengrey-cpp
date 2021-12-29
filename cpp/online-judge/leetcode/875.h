#pragma once

#include "include/std.h"

class Solution {
private:
    bool FinishEating(vector<int>& piles, int h, int speed) {
        int time = 0;
        for (int p : piles)
            time += p/speed + (p%speed!=0);
        return time <= h;
    }

public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int n = piles.size();
        if (n == 0 || n > h)
            return -1;
        int a = 1, b = *max_element(piles.begin(), piles.end()), m;
        cout << b << endl;
        while (a <= b) {
            m = (b-a)/2 + a;
            if (FinishEating(piles, h, m))
                b = m - 1;
            else
                a = m + 1;
        }
        return a;
    }
};