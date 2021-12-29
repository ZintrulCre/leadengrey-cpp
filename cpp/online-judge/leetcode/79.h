#pragma once

#include "include/std.h"

class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        int m = board.size(), n = m == 0 ? 0 : board[0].size(), l = word.size();
        if (m == 0 || l == 0)
            return true;
        int dir[4][2]{{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
        function<bool(int, int, int)> Backtracking;
        Backtracking = [&](int x, int y, int k)
        {
            if (word[k] != board[x][y])
                return false;

            if (k == l - 1)
                return true;

            char temp = board[x][y];
            board[x][y] = '0';
            for (auto& d : dir)
            {
                int u = x + d[0], v = y + d[1];
                if (u >= 0 && u < m && v >= 0 && v < n && board[u][v] != '0' && Backtracking(u, v, k + 1))
                        return true;
            }
            board[x][y] = temp;

            return false;
        };
        for (int i = 0; i < m; ++i)
            for (int j = 0; j < n; ++j)
                if (Backtracking(i, j, 0))
                    return true;
        return false;
    }
};
