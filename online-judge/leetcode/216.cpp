// #include "base/pch.h"

// class Solution {
// public:
//     vector<vector<int>> combinationSum3(int k, int n) {
//         vector<vector<int>> res;
//         vector<int> vec;
//         function<void(int lv, int m, int s)> Backtracking = [&](int lv, int m, int s)
//         {
//             if (s == n && lv == k)
//                 res.emplace_back(vec);
            
//             if (lv == k || s >= n)
//                 return;

//             for (int i = m; i <= 9; ++i)
//             {
//                 vec.emplace_back(i);
//                 Backtracking(lv + 1, i + 1, s + i);
//                 vec.pop_back();
//             }
//         };
//         Backtracking(0, 1, 0);
//         return res;
//     }
// };
