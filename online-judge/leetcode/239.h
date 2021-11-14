#pragma once

#include "include/std.h"

class Solution {
    struct windowQueue {
        std::list<int> l;

        void push(int k) {
            while(!l.empty() && l.back() < k)
                l.pop_back();
            l.push_back(k);
        }

        void pop(int k) {
            if (l.front() == k)
                l.pop_front();
        }

        int front() {
            return l.front();
        }
    };
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        windowQueue q;
        int n = nums.size();
        vector<int> res(n-k+1, 0);
        for (int i = 0; i < n; i++) {
            if (i >= k)
                q.pop(nums[i-k]);
            q.push(nums[i]);
            if (i >= k-1)
                res[i-k+1] = q.front();
        }
        return res;
    }
};