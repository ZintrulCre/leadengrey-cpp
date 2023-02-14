#pragma once

#include "include/std.h"

class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();
        for (int i = 0; i < n; ++i)
            for (int j = n-1-i; j >= 0; --j)
                swap(matrix[i][j], matrix[n-j-1][n-i-1]);
        for(int i = 0 ; i < n; ++ i) {
            for(int j = 0 ; j < n; ++ j)
                printf("%d ", matrix[i][j]);
            cout << endl;
        }

        for (int j = 0; j < n; ++j)
            for (int i = 0; i < n / 2; ++i)
                swap(matrix[i][j], matrix[n-i-1][j]);
        return matrix;
    }
};