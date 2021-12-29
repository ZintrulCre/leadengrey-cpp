#pragma once

#include "include/std.h"

class Solution {
public:
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        vector<vector<int>> res;
        std::function<void(int, vector<int>&)> DFS = [&graph, &res, &DFS](int i, vector<int> &r) -> void {
            r.emplace_back(i);
            if (i == int(graph.size()) - 1)
                res.emplace_back(r);
            for (auto g : graph[i])
                DFS(g, r);
            r.pop_back();
        };
        vector<int> r;
        DFS(0, r);
        return res;
    }
};