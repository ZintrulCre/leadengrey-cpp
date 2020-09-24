#include "universal/std-pch.h"

int AddressSanitizerTest()
{
    int* arr = new int[1000];
    delete []arr;
    return arr[1];
    return 0;
}