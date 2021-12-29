#pragma once

#include "include/std.h"

class Solution {
    struct T {
        int val;
        int m_i;
        int primes_i;
    };

    struct cmp {
        bool operator()(const T& t1, const T& t2) {
            return t1.val > t2.val;
        }
    };

public:
    int nthSuperUglyNumber(int n, vector<int>& primes) {
        int l = primes.size();
        std::sort(primes.begin(), primes.end());
        vector<int> m({1});
        std::priority_queue<T, std::vector<T>, cmp> q;
        for (int i = 0; i < l; ++i)
            q.push({primes[i], 0, i});
        int k = 1;
        T t{1, 0, 0};
        while (k < n) {
            t = q.top();
            q.pop();

            cout << t.val << ' '  << t.m_i << ' ' << t.primes_i << endl;

            if (t.val != m[k - 1])
            {
                m.push_back(t.val);
                ++k;
            }
            q.push({primes[t.primes_i] * m[t.m_i], t.m_i + 1, t.primes_i});
        }

        return t.val;
    }
};