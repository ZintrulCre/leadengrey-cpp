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
        vector<bool> visited(n, false);
        priority_queue<int, vector<int>, greater<int>> h;
        h.push(k-1);
        dis[k-1] = 0;
        while (!h.empty()) {
            int p = h.top();
            cout << "p " << p  << ' ' << dis[p]<< endl;
            h.pop();
            visited[p] = true;
            --n;
            if (edges[p].size() == 0)
                ret = max(ret, dis[p]);
            for (auto &e : edges[p]) {
                int end = e.first;
                int distance = e.second;
                dis[end] = min(dis[end], dis[p] + distance);
                if (visited[end] == false) {
                    visited[end] == true;
                    h.push(end);
                }
            }
        }
        return n == 0 ? ret : -1;
    }
};

class Solution {
public:
    int networkDelayTime(vector<vector<int>> &times, int n, int k) {
        const int inf = INT_MAX / 2;
        vector<vector<pair<int, int>>> g(n);
        for (auto &t : times) {
            int x = t[0] - 1, y = t[1] - 1;
            g[x].emplace_back(y, t[2]);
        }

        vector<int> dist(n, inf);
        dist[k - 1] = 0;
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> q;
        q.emplace(0, k - 1);
        while (!q.empty()) {
            auto p = q.top();
            q.pop();
            int time = p.first, x = p.second;
            if (dist[x] < time) {
                continue;
            }
            for (auto &e : g[x]) {
                int y = e.first, d = dist[x] + e.second;
                if (d < dist[y]) {
                    dist[y] = d;
                    q.emplace(d, y);
                }
            }
        }

        int ans = *max_element(dist.begin(), dist.end());
        return ans == inf ? -1 : ans;
    }
};
