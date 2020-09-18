
// // Created by ZintrulCre on 2020-09-18.

// #pragma once

// #include "universal/std-pch.h"

// class Solution {
// public:
//     vector<vector<int>> permuteUnique(vector<int>& nums) {
//         vector<vector<int>> res;
//         vector<int> curr;
//         const int n = nums.size();
//         vector<bool> used(n, false);
//         sort(nums.begin(), nums.end());

//         function<void()> Backtracking = [&]() -> void
//         {
//             if (curr.size() == n)
//             {
//                 res.push_back(curr);
//                 return;
//             }
            
//             unique_ptr<int> prev = nullptr;
//             for (int i = 0; i < n; ++i)
//             {
//                 if (prev && *prev == nums[i])
//                     continue;

//                 if (used.at(i))
//                     continue;
//                 used.at(i) = true;

//                 if (!prev)
//                     prev = make_unique<int>();
//                 *prev = nums[i];
//                 curr.emplace_back(nums[i]);
//                 Backtracking();
//                 curr.pop_back();

//                 used.at(i) = false;
//             }
//         };

//         Backtracking();
//         return res;
//     }
// };
