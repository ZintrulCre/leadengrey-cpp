#pragma once

#include "include/std.h"
#include "include/boost.h"

// https://en.cppreference.com/w/c/language/array
// variable-length arrays

void VlaTest(int n)
{
    int a[n];
    cout << sizeof(a) << endl;
}