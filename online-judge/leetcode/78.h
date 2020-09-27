#pragma once

#include "universal/std-pch.h"

class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        vector<vector<int>> res;
        vector<int> curr;
        function<void(int)> Backtracking = [&](int x) -> void
        {
            res.push_back(curr);
            if (x == n)
                return;

            for (int i = x; i < n; ++i)
            {
                curr.emplace_back(nums[i]);
                Backtracking(i + 1);
                curr.pop_back();
            }
        };
        Backtracking(0);
        return res;
    }
};

class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        int n = nums.size(), bits = (1 << n);
        vector<vector<int>> res;
        for (int i = 0; i < bits; ++i)
        {
            vector<int> curr;
            for (int j = 0; j < n; ++j)
                if (i & (1 << j))
                    curr.emplace_back(nums[j]);
            res.push_back(curr);
        }
        return res;
    }
};
