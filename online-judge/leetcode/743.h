#pragma once

#include "include/std.h"

class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        int ret = 0;
        vector<unordered_map<int, int>> edges(n, unordered_map<int, int>());
        for (auto &time : times)
            edges[time[0]-1].insert({time[1]-1, time[2]});
        vector<int> dis(n, INT_MAX);
        priority_queue<int, vector<int>, greater<int>> h;
        h.push(k-1);
        dis[k-1] = 0;
        while (!h.empty() && n > 0) {
            int p = h.top();
            h.pop();
            for (auto &e : edges[p]) {
                int end = e.first;
                int distance = e.second + dis[p];
                if (dis[end] > distance) {
                    dis[end] = distance;
                    h.push(end);
                }
            }
        }
        for (int i = 0; i < n; ++i)
            ret = max(ret, dis[i]);
        return ret == INT_MAX ? -1 : ret;
    }
};