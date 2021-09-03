#include "base/print.h"
#include "online-judge/interviews/interviews.h"

void Interviews()
{
    vector<int> v{1,3,5,7,2,4,6,8};
    int k = 4;
    Solution s;
    auto r = s.smallestK(v, k);
    leadengrey::Print(r);
}