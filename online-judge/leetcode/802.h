#pragma once

#include "include/std.h"
#include "base/print.h"

class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<vector<int>> rg(n, vector<int>());
        vector<int> cnt(n, 0);
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < graph[i].size(); ++j) {
                rg[graph[i][j]].emplace_back(i);
                ++cnt[i];
            }
        }

        std::queue<int> q;
        for (int i = 0; i < n; ++i)
            if (cnt[i] == 0)
                q.push(i);

        while (!q.empty())
        {
            int m = q.front();
            q.pop();

            for (int j = 0; j < rg[m].size(); ++j) {
                if (--cnt[rg[m][j]] == 0)
                    q.push(rg[m][j]);
            }
        }

        vector<int> res;
        for (int i = 0; i < n; ++i)
            if (cnt[i] == 0)
                res.emplace_back(i);

        return res;
    }
};