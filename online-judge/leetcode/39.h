#include "universal/std-pch.h"

class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        int n = candidates.size();
        vector<vector<int>> res;
        vector<int> combination;
        function<void(int i, int sum)> Backtracking = [&] (int i, int sum)
        {
            if (sum == target)
                res.emplace_back(combination);

            if (sum >= target)
                return;

            for (int j = i; j < n; ++j)
            {
                combination.emplace_back(candidates[j]);
                Backtracking(j, sum + candidates[j]);
                combination.pop_back();
            }
        };
        Backtracking(0, 0);
        return res;
    }
};