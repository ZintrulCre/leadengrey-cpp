#pragma once

#include "include/std.h"
#include "online-judge/data-structure.h"

class NumMatrix {
    vector<vector<int>> prefix;

public:
    NumMatrix(vector<vector<int>>& matrix) {
        int n = matrix.size(), m = n == 0 ? 0 : matrix[0].size();
        prefix = vector<vector<int>>(n + 1, vector<int>(m + 1, 0));
        for (int i = 0; i < n; ++i) {
            vector<int> row(m + 1, 0);
            for (int j = 0; j < m; ++j) {
                row[j+1] = row[j] + matrix[i][j];
                prefix[i+1][j+1] = prefix[i][j+1] + row[j+1];
            }
        }
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        return prefix[row2+1][col2+1] - prefix[row2+1][col1] - prefix[row1][col2+1] + prefix[row1][col1];
    }
};