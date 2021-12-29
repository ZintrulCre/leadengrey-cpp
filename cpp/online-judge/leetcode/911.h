#pragma once

#include "include/std.h"

class TopVotedCandidate {
    vector<int> result, times;
    int n;
public:
    TopVotedCandidate(vector<int>& persons, vector<int>& times) {
        n = persons.size();
        result = vector<int>(n, 0);
        this->times = times;
        unordered_map<int, int> m;
        int max_num = 0, p = 0;
        for (int i = 0; i < n; ++i) {
            m[persons[i]]++;
            if (m[persons[i]] >= max_num) {
                max_num = m[persons[i]];
                p = persons[i];
            }
            result[i] = p;
        }
    }
    
    int q(int t) {
        int x = 0, y = n - 1, z, m;
        while (x <= y) {
            z = x + (y - x) / 2;
            m = times[z];
            cout << "z " << z << " m " << m << endl;
            if (m < t)
                x = z + 1;
            else if (m > t)
                y = z;
        }
        return result[y];
    }
};
