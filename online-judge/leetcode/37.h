
// Created by ZintrulCre on 2020-09-17.

#pragma once

#include "universal/std-pch.h"

class Solution {
public:
    void solveSudoku(vector<vector<char>>& board) {
        function<bool(int, int, char)> Check = [&](int x, int y, char c)
        {
            for (int i = 0; i < 9; ++i)
                if (board[x][i] == c || board[i][y] == c)
                    return false;
            
            for (int i = 0; i < 3; ++i)
                for (int j = 0; j < 3; ++j)
                    if (board[i + x / 3 * 3][j + y / 3 * 3] == c)
                        return false;

            return true;
        };

        function<bool(int, int)> Backtracking = [&](int x, int y)
        {
            if (x == 9)
                return true;
            
            auto NextIter = bind(Backtracking, x + (y + 1) / 9, (y + 1) % 9);

            if (board[x][y] != '.')
                return NextIter();
            
            for (char c = '1'; c <= '9'; ++c)
            {
                if (Check(x, y, c))
                {
                    board[x][y] = c;
                    if (NextIter())
                        return true;
                    board[x][y] = '.';
                }
            }

            return false;
        };

        Backtracking(0, 0);
    }
};
