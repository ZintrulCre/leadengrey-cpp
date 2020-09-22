//
// Created by ZintrulCre on 2020-09-17.
//

#pragma once

#include "universal/std-pch.h"

class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        int n = candidates.size();
        vector<vector<int>> res;
        vector<int> vec;
        function<void(int i, int sum)> Backtracking = [&](int i, int sum)
        {
            if (sum == target)
                res.emplace_back(vec);

            if (sum >= target || i >= n)
                return;

            int prev = -1;

            for (int j = i; j < n; ++j)
            {
                if (candidates[j] == prev)
                    continue;
                vec.emplace_back(candidates[j]);
                Backtracking(j + 1, sum + candidates[j]);
                prev = vec.back();
                vec.pop_back();
            }
        };
        Backtracking(0, 0);
        return res;
    }
};
