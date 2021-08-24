#pragma once

#include "include/std.h"

class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<int> prev(n, INT_MAX/2), curr(n, INT_MAX/2);
        curr[src] = 0;
        for (int i = 0; i <= k; ++i) {
            prev = curr;
            for (auto& flight : flights) {
                int from = flight[0], to = flight[1], cost = flight[2];
                curr[to] = std::min(curr[to], prev[from] + cost);
            }
        }
        return curr[dst] == INT_MAX/2 ? -1 : curr[dst];
    }
};