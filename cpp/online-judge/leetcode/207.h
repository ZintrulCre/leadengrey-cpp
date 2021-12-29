#pragma once

#include "include/std.h"

class Solution {
    vector<unordered_set<int>> g;
    vector<bool> s;

    bool DFS(int i, vector<bool> &visited) {
        if (s[i])
            return true;
        for (int j : g[i]) {
            if (visited[j] == true)
                return false;
            visited[j] = true;
            if (!DFS(j, visited))
                return false;
            visited[j] = false;
        }
        return true;
    }

public:
    bool canFinish(int n, vector<vector<int>>& prerequisites) {
        g = vector<unordered_set<int>>(n, unordered_set<int>());
        s = vector<bool>(n, false);
        for (auto &p : prerequisites)
            g[p[0]].insert(p[1]);
        for (int i = 0; i < n; ++i)
            if (g[i].size() == 0)
                s[i] = true;
        for (int i = 0; i < n; ++i) {
            vector<bool> visited(n, false);
            visited[i] = true;
            if (DFS(i, visited) == false)
                return false;
            s[i] = true;
        }
        return true;
    }
};