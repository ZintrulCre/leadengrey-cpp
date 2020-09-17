//
// Created by ZintrulCre on 2020-09-17.
//

//#pragma once

// #include "universal/std-pch.h"

// class Solution {
// public:
//     vector<vector<int>> combine(int n, int k)
//     {
//         vector<vector<int>> res;
//         vector<int> vec;
//         function<void(int)> Backtracking = [&](int prev)
//         {
//             if (vec.size() == k)
//             {
//                 res.emplace_back(vec);
//                 return;
//             }

//             for (int x = prev + 1; x <= n && n - x + 1 >= k - vec.size(); ++x)
//             {
//                 vec.emplace_back(x);
//                 Backtracking(x);
//                 vec.pop_back();
//             }
//         };
//         Backtracking(0);
//         return res;
//     }
// };
