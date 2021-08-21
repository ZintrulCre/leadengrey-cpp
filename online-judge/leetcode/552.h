#pragma once

#include "include/std.h"

// class Solution {
//     vector<vector<vector<int>>> c;
//     int MOD = 1000000007;
//     int DFS(int n,  int a, int l) {
//         if (a == 2 || l == 3) return 0;
//         if (n == 0) return 1;
//         if (c[n-1][a][l] != -1)    return c[n-1][a][l];
//         int res = DFS(n-1, a+1, 0) % MOD;
//         res = (res + DFS(n-1, a, l + 1)) % MOD;
//         res = (res + DFS(n-1, a, 0)) % MOD;
//         c[n-1][a][l] = res;
//         return res;
//     };

// public:
//     int checkRecord(int n) {
//         c = vector<vector<vector<int>>>(n, vector<vector<int>>(2, vector<int>(3, -1)));
//         return DFS(n, 0, 0);
//     }
// };

class Solution {
    int MOD = 1000000007;
public:
    int checkRecord(int n) {
        auto prev = vector<vector<long long>>(2, vector<long long>(3, 0)), curr = prev;
        curr[0][0] = 1;
        curr[1][0] = 1;
        curr[0][1] = 1;
        

        for (int i = 1; i < n; ++i) {
            prev = curr;
            // p
            curr[0][0] = (prev[0][0] + prev[0][1] + prev[0][2]) % MOD;
            curr[1][0] = (prev[1][0] + prev[1][1] + prev[1][2]) % MOD;
            // a
            curr[1][0] = (curr[1][0] + prev[0][0] + prev[0][1] + prev[0][2]) % MOD;
            // l    
            curr[0][1] = prev[0][0];
            curr[0][2] = prev[0][1];
            curr[1][1] = prev[1][0];
            curr[1][2] = prev[1][1];
        }

        int res = 0;
        for (int a = 0; a < 2; ++a)
            for (int l = 0; l < 3; ++l)
                res = (res + curr[a][l]) % MOD;

        return res;
    }
};