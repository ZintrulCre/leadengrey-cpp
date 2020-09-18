
// // Created by ZintrulCre on 2020-09-18.

// #pragma once

// #include "universal/std-pch.h"
// #include "base/print.h"

// class Solution {
// public:
//     vector<vector<int>> permuteUnique(vector<int>& nums) {
//         vector<vector<int>> res;
//         vector<int> curr;
//         const int n = nums.size();
//         unordered_set<int> used;
//         sort(nums.begin(), nums.end());

//         function<void(int)> Backtracking = [&](int m) -> void
//         {
//             if (m == n)
//             {
//                 res.push_back(curr);
//                 return;
//             }
//             unique_ptr<int> prev = nullptr;
//             for (int i = 0; i < n; ++i)
//             {
//                 if (prev && *prev == nums[i])
//                     continue;

//                 if (used.find(i) != used.end())
//                     continue;
//                 auto pair_res = used.insert(i);
//                 // leadgrey::Print(used);

//                 if (!prev)
//                     prev = make_unique<int>();
//                 *prev = nums[i];
//                 curr.emplace_back(nums[i]);
//                 Backtracking(m + 1);
//                 curr.pop_back();

//                 used.erase(pair_res.first);
//             }
//         };

//         Backtracking(0);
//         return res;
//     }
// };
