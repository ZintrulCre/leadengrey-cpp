#pragma once

#include "include/std.h"
#include "online-judge/data-structure.h"

class Solution {
public:
    vector<int> smallestK(vector<int>& arr, int k) {
        vector<int> ret;
        int x = 0, y = arr.size() - 1;
        while(true) {
            int pivot = arr[y];
            int m = x;
            for (int i = x; i < y; ++i) {
                if (arr[i] < pivot)
                    swap(arr[i], arr[m++]);
            }
            swap(arr[m++], pivot);

            if (m-x <= k) {
                ret.insert(ret.end(), arr.begin()+x, arr.begin()+y);
                x = m+1;
                k -= (m-x);
            } else {
                y = m+1;
            }
            if (k == 0) {
                break;
            }
        }
        return ret;
    }
};