#pragma once

#include "include/std.h"

class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        int a = 0, n = nums.size(), b = n-1;
        while (a <= b) {
            int &pivot = nums[b];
            int mid = a;
            for (int i = a; i < b; ++i) {
                if (nums[i] <= pivot) {
                    swap(nums[i], nums[mid++]);
                }
            }
            swap(nums[b], nums[mid]);
            if (k == b-mid+1) {
                return nums[mid];
            } else if (k < b-mid+1) {
                a = mid+1;
            } else if (k > b-mid+1) {
                k -= (b-mid+1);
                b = mid-1;
            }
        }
        return -1;
    }
};

// [3,2,1,5,6,4]
// 2
// [3,2,3,1,2,4,5,5,6]
// 4
// [3,2,3,1,2,4,5,5,6]
// 1
// [3,2,3,1,2,4,5,5,6]
// 8
// [0]
// 1