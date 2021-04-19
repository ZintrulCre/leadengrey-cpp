//
// Created by ZintrulCre on 2020-09-12.
//

#ifndef LEADENGREY_ONLINEJUDGE_PCH_H
#define LEADENGREY_ONLINEJUDGE_PCH_H

#include "online-judge/leetcode/leetcode.h"

void OnlineJudge()
{
    // leetcode
    // LeetCode();

    int N;
    cin >> N;
    for (int n = 0; n < N; ++n)
    {
        int m;
        cin >> m;
        vector<int> v(m);
        int res = 0;
        for (int i = 0; i < m; ++i)
        {
            cin >> v[i];
            if (v[i] > 0)
                ++res;
            else if (v[i] < 0)
                --res;
            else
                res += (res > 0 ? -1 : 1);
            
        }
        cout << (abs(res) <= 1 ? "Yes" : "No") << endl;
    }
}

#endif