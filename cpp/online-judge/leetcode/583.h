#pragma once

#include "include/std.h"

class Solution {
public:
    int minDistance(string word1, string word2) {
        int m = word1.size(), n = word2.size();
        vector<vector<int>> dp(m+1, vector<int>(n+1, 1));
        for (int i = 1; i <= m; ++i) {
            for (int j = 1; j <= n; ++j) {
                dp[i][j]  = max(dp[i-1][j], dp[i][j-1]);
                if (word1[i] == word2[j])
                    dp[i-1][j-1] = max(dp[i-1][j-1] + 1, dp[i][j]);
            }
        }
        return m - dp[m][n] + 1 + n - dp[m][n] + 1;
    }
};