#pragma once

#include "include/std.h"

class Solution {
    int dir[4][2] = {{0,1}, {1,0}, {0,-1}, {-1,0}};
public:
    vector<vector<int>> colorBorder(vector<vector<int>>& grid, int row, int col, int color) {
        int m = grid.size(), n = grid[0].size();
        vector<vector<int>> ret(m, vector<int>(n, 0));
        std::queue<std::pair<int, int>> q;
        q.push({row, col});
        int cnt = 0, c = grid[row][col];
        while (!q.empty()) {
            std::pair<int, int> p = q.front();
            q.pop();
            int i = p.first, j = p.second;
            cnt = 0;
            for (auto d : dir) {
                int x = i + d[0], y = j + d[1];
                if (x < 0 || x >= m || y < 0 || y >= n || grid[x][y] != c)
                    continue;
                ++cnt;
                if (ret[x][y] != 0)
                    continue;
                q.push({x,y});
            }
            ret[i][j] = cnt == 4 ? grid[i][j] : color;
        }

        for(int i = 0; i < m; ++i)
            for (int j = 0; j < n; ++j)
                if (ret[i][j] == 0)
                    ret[i][j] = grid[i][j];
        return ret;
    }
};