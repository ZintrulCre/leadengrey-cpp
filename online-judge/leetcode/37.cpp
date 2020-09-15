#include "base/pch.h"

class Solution {
public:
    void solveSudoku(vector<vector<char>>& board) {
        function<bool(int, int)> CheckRow = [&](int x, int y)
        {
            for (int col = 0; col < 9; ++col)
            {
                if (col == y)
                    continue;
                if (board[x][col] == board[x][y])
                    return false;
            }
            return true;
        };

        function<bool(int, int)> CheckCol = [&](int x, int y)
        {
            for (int row = 0; row < 9; ++row)
            {
                if (row == x)
                    continue;
                if (board[row][y] == board[x][y])
                    return false;
            }
            return true;
        };

        function<bool(int, int)> CheckDiagnoal = [&](int x, int y)
        {
            for (int i = 0; i < 8; ++i)
            {
                int pos_x = (x + i) % 9, pos_y = (y + i) % 9;
                if (pos_x == x && pos_y == y)
                    continue;
                if (board[pos_x][pos_y] == '.')
                    continue;
                if (board[pos_x][pos_y] == board[x][y])
                    return false;
            }
            return true;
        };

        function<bool(int, int)> CheckGrid = [&](int x, int y)
        {
            for (int i = 0; i < 3; ++i)
            {
                for (int j = 0; j < 3; ++j)
                {
                    int pos_x = i + x / 3 * 3, pos_y = j + y / 3 * 3;
                    if (pos_x == x && pos_y == y)
                        continue;
                    if (board[pos_x][pos_y] == board[x][y])
                        return false;
                }
            }
            return true;
        };

        function<bool(int, int)> Backtracking = [&](int x, int y)
        {
            if (x == 9)
                return true;
            
            auto NextIter = bind(Backtracking, x + (y + 1) / 9, (y + 1) % 9);

            cout << x << ' ' << y << endl;
            if (board[x][y] != '.')
                return NextIter();
            
            for (char c = '0'; c < '9'; ++c)
            {
                board[x][y] = c;
                if (CheckRow(x, y) && CheckCol(x, y) && CheckDiagnoal(x, y) && CheckGrid(x, y))
                {
                    leadgrey::Print(board);
                    if (NextIter())
                        return true;
                }
            }

            return false;
        };

        Backtracking(0, 0);
    }
};