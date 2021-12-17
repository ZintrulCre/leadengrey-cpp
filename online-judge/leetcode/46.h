#pragma once

#include "include/std.h"

class Solution {
    vector<vector<int>> ret;
    vector<int> nums;
    vector<bool> visited;

    void Backtracking(vector<int> &current, int idx) {
        if (idx >= nums.size()) {
            ret.push_back(current);
            return;
        }
        for (int i = 0; i < nums.size(); ++i) {
            if (visited[i])
                continue;
            visited[i] = true;
            current.push_back(nums[i]);
            Backtracking(current, idx + 1);
            current.pop_back();
            visited[i] = false;
        }
    }
public:
    vector<vector<int>> permute(vector<int>& nums) {
        this->nums = nums;
        ret = vector<vector<int>>();
        visited = vector<bool>(nums.size(), false);
        vector<int> current;
        Backtracking(current, 0);
        return ret;
    }
};