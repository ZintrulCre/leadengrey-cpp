#pragma once

#include "include/std.h"

// class Solution {
// public:
//     vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
//         unordered_map<int, int> rec;
//         stack<int> s;
//         for (int i = 0; i < nums2.size(); ++i) {
//             while (!s.empty() && nums2[i] > nums2[s.top()]) {
//                 rec[nums2[s.top()]] = nums2[i];
//                 s.pop();
//             }
//             s.push(i);
//         }
//         int n = nums1.size();
//         vector<int> res(n, -1);
//         for (int i = 0; i < n; ++i) {
//             int m = nums1[i];
//             auto iter = rec.find(m);
//             if (iter != rec.end())
//                 res[i] = iter->second;
//         }
//         return res;
//     }
// };

class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int, int> rec;
        int n = nums2.size(), m = nums1.size();
        vector<int> res(m, 0);
        stack<int> s;
        for (int i = n - 1; i >= 0; i--) {
            if (s.empty()) {
                rec[nums2[i]] = -1;
            } else if (nums2[i] < s.top()) {
                rec[nums2[i]] = s.top();
            } else {
                while (!s.empty() && nums2[i] >= s.top())
                    s.pop();
                rec[nums2[i]] = s.empty() ? -1 : s.top();
            }
            s.push(nums2[i]);
        }
        for (int i = 0; i < m; i++)
            res[i] = rec[nums1[i]];
        return res;
    }
};