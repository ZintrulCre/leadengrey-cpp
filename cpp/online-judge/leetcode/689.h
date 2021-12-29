#pragma once

#include "include/std.h"

class Solution {
public:
    vector<int> maxSumOfThreeSubarrays(vector<int>& nums, int k) {
        int n = nums.size(), m = n-k+1, sum = 0;
        vector<int> prefix(m, 0);
        for (int i = 0; i < n; ++i) {
            sum += nums[i];
            if (i >= k - 1) {
                prefix[i-k+1] = sum;
                sum -= nums[i-k+1];
            }
        }
        vector<int> ret(3, 0);
        int s1 = 0, s2 = 0, s3 = 0, i1, i2, i3, r1 = 0, r21 = 0, r22 = k;
        for (int i = k*2; i < m; ++i) {
            i1 = i - k*2;
            i2 = i - k*1;
            i3 = i;
            cout << i1 << ' ' << i2 << ' ' << i3 << ' ' << endl;
            if (s1 < prefix[i1]) {
                s1 = prefix[i1];
                r1 = i1;
            }
            if (s2 < prefix[i2] + s1) {
                s2 = prefix[i2] + s1;
                r21 = r1;
                r22 = i2;
            }
            if (s3 < prefix[i3] + s2) {
                s3 = prefix[i3] + s2;
                ret = {r21, r22, i3};
                cout << "s3 " << s3 << ' ' << r21<< ' '  <<  r22 << ' ' << i3 << ' ' << endl;
            }
        }
        return ret;
    }
};