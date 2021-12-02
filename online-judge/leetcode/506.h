#pragma once

#include "include/std.h"

class Solution {
    struct Node {
        int val;
        int idx;
        Node(int v, int i) : val(v), idx(i) {}
    };
public:
    vector<string> findRelativeRanks(vector<int>& score) {
        int n = score.size();
        vector<string> ret(n);
        vector<Node> v;
        for (int i = 0; i < n; ++i)
            v.push_back(Node(score[i], i));
        std::sort(v.begin(), v.end(), [](const Node &lhs, const Node &rhs) {
            return lhs.val > rhs.val;
        });
        for (int i = 0; i < n; ++i) {
            ret[v[i].idx] = to_string(i + 1);
            if (i == 0)
                ret[v[i].idx] = "Gold Medal";
            else if (i == 1)
                ret[v[i].idx] = "Silver Medal";
            else if (i == 2)
                ret[v[i].idx] = "Bronze Medal";
        }
        return ret;
    }
};