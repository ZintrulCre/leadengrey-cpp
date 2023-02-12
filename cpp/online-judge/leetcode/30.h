#pragma once

#include "include/std.h"
#include "online-judge/data-structure.h"

class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        int n = words[0].size(), m = words.size();
        vector<int> res;
        unordered_map<string, int> um;
        // init
        for (string& s : words)
            ++um[s];
        // start from each letter
        for (int x = 0; x < n; ++x) {
            unordered_map<string, int> temp;
            // init sliding windows
            for (int i = x; i < n*m && i < s.size(); i += n)
                ++temp[s.substr(i, n)];
            if (temp == um)
                res.push_back(x);
            // move sliding windows
            for (int i = n + x; i + n*m <= s.size(); i += n) {
                string prev = s.substr(i - n, n), next = s.substr(i + n*(m-1), n);
                --temp[prev];
                if (temp[prev] == 0)
                    temp.erase(prev);
                ++temp[next];
                if (temp == um)
                    res.push_back(i);
            }
        }
        return res;
    }
};