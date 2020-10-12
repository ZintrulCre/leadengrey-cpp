//
// Created by ZintrulCre on 2020-09-24.
//

#ifndef LEADGREY_SORT_TEST_H
#define LEADGREY_SORT_TEST_H

#include "universal/std-pch.h"
#include "sort/quick-sort.h"
#include "base/print.h"

void SortTest()
{
    vector<int> v{7,5,2,1};
    QuickSort(v);
    leadgrey::Print(v);
    leadgrey::Print(v.size());
}

#endif