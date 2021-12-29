#pragma once

#include "include/std.h"

class Solution {
public:
    int maxIncreaseKeepingSkyline(vector<vector<int>>& grid) {
        int m = grid.size(), n = m == 0 ? 0 : grid.size(), v = 0, ret = 0;
        vector<int> row(m, 0), col(n, 0);
        for (int i = 0; i < m; ++i)
            for (int j = 0; j < n; ++j)
                row[i] = max(grid[i][j], row[i]);
        for (int j = 0; j < n; ++j)
            for (int i = 0; i < m; ++i)
                col[j] = max(grid[i][j], col[j]);
        for (int i = 0; i < m; ++i)
            for (int j = 0; j < n; ++j)
                ret += min(row[i], col[j]) - grid[i][j];
        return ret;
    }
};
