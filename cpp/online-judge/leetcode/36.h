#pragma once

#include "include/std.h"

class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        vector<int> r(10, 0), c(10, 0), b(10, 0);
        auto Duplicate = [](int x, int shift) -> bool {
            return ((x >> shift) & 1) == 1;
        };

        for (int i = 0; i < 9; ++i) {
            for (int j = 0; j < 9; ++j) {
                char ch = board[i][j];
                if (ch == '.')
                    continue;
                int shift = ch - '1';
                int k = i / 3 * 3 + j / 3;
                if (Duplicate(r[i], shift) || Duplicate(c[j], shift) || Duplicate(b[k], shift))
                    return false;
                r[i] |= (1 << shift);
                c[j] |= (1 << shift);
                b[k] |= (1 << shift);
            }
        }
        return true;
    }
};