#pragma once

#include "include/std.h"
#include "base/base.h"

class Solution {
    vector<vector<string>> ret;
    int n;

    bool CheckAvailability(vector<string> &res, int x, int y) {
        int u = x - 1, v = y - 1, w = y + 1;
        while (u >= 0) {
            if (res[u][y] == 'Q')
                return false;
            if (v >= 0 && res[u][v] == 'Q')
                return false;
            if (w < n && res[u][w] == 'Q')
                return false;
            --u;
            --v;
            ++w;
        }
        return true;
    }

    void Backtracking(vector<string> &res, int idx) {
        if (idx >= n) {
            ret.push_back(res);
            return;
        }
        for (int j = 0; j < n; ++j) {
            if (!CheckAvailability(res, idx, j))
                continue;
            string str;
            str.append(j, '.');
            str += 'Q';
            str.append(n-j-1, '.');
            res.push_back(str);
            Backtracking(res, idx + 1);
            res.pop_back();
        }
    }
public:
    vector<vector<string>> solveNQueens(int n) {
        this->n = n;
        ret = vector<vector<string>>();
        vector<string> res;
        Backtracking(res, 0);
        return ret;
    }
};