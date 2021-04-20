//
// Created by ZintrulCre on 2020-09-24.
//

#pragma once

#include "include/std.h"
#include "base/print.h"
#include "sort/quick-sort.h"

void SortTest()
{
    vector<int> v{7,5,2,1};
    QuickSort(v);
    leadengrey::Print(v);
    leadengrey::Print(v.size());
}

