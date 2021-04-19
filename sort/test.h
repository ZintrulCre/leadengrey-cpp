//
// Created by ZintrulCre on 2020-09-24.
//

#pragma once

#include "universal/std-pch.h"
#include "sort/quick-sort.h"
#include "base/print.h"

void SortTest()
{
    vector<int> v{7,5,2,1};
    QuickSort(v);
    leadengrey::Print(v);
    leadengrey::Print(v.size());
}

