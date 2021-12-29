#include "online-judge/online-judge.h"

void OnlineJudge()
{
    int N;
    cin >> N;
    for (int n = 0; n < N; ++n)
    {
        int m;
        cin >> m;
        vector<int> v(m);
        for (int i = 0; i < m; ++i)
            cin >> v[i];
        if (m == 2)
        {
            cout << (v[0] <= v[1] ? "Yes" : "No") << endl;
            continue;
        }
        if (v[1] > v[m - 1])
            swap(v[1], v[m - 1]);
        if (v[0] > v[m - 2])
            swap(v[0], v[m - 2]);
        for (int i = m - 1; i >= 2; --i)
            if (v[i] > v[i - 2])
                swap(v[i], v[i - 2]);
        for (int i = m - 1; i >= 2; --i)
            if (v[i] > v[i - 2])
                swap(v[i], v[i - 2]);
        bool f = true;
        for (int i = 0; i < m - 1; ++i)
            if (v[i] > v[i + 1])
            {
                f = false;
                break;
            }
        cout << (f ? "Yes" : "No") << endl;
    }
}

