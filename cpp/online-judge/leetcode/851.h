#pragma once

#include "include/std.h"

class Solution {
    vector<unordered_set<int>> edges;
    vector<int> cacheIdx;
    vector<bool> visited;
    vector<int> quiet;

    void DFS(int i) {
        if (visited[i] == true)
            return;
        visited[i] = true;
        cacheIdx[i] = i;
        for (int j : edges[i]) {
            DFS(j);
            if (quiet[cacheIdx[i]] > quiet[cacheIdx[j]])
                cacheIdx[i] = cacheIdx[j];
        }
    }

public:
    vector<int> loudAndRich(vector<vector<int>>& richer, vector<int>& quiet) {
        int n = quiet.size();
        edges = vector<unordered_set<int>>(n, unordered_set<int>());
        cacheIdx = vector<int>(n, INT_MAX);
        visited = vector<bool>(n, false);
        this->quiet = quiet;
        for (auto &r : richer)
            edges[r[1]].insert(r[0]);
        for (int i = 0; i < n; ++i)
            DFS(i);
        return cacheIdx;
    }
};