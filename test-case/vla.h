#pragma once

#include "universal/std-pch.h"
#include "universal/boost-pch.h"

// https://en.cppreference.com/w/c/language/array
// variable-length arrays

void VlaTest(int n)
{
    int a[n];
    cout << sizeof(a) << endl;
}