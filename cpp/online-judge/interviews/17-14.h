#pragma once

#include "include/std.h"
#include "online-judge/data-structure.h"

class Solution {
public:
    vector<int> smallestK(vector<int>& arr, int k) {
        vector<int> ret;
        if (arr.size() == 0)    return ret;
        int x = 0, y = arr.size() - 1;
        while(true) {
            int pivot = arr[y];
            int m = x;
            for (int i = x; i < y; ++i) {
                if (arr[i] < pivot)
                    swap(arr[i], arr[m++]);
            }
            swap(arr[m], arr[y]);

            if (m-x+1 <= k) {
                ret.insert(ret.end(), arr.begin()+x, arr.begin()+m+1);
                k -= (m-x+1);
                x = m+1;
            } else {
                y = m-1;
            }
            if (k == 0) {
                break;
            }
        }
        return ret;
    }
};