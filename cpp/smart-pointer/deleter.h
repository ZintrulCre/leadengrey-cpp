#pragma once

#include "include/std.h"

struct DefaultDeleter
{
    template<typename T>
    void operator()(T* p) const
    {
        static_assert(sizeof(p) > 0, "can't delete pointer to incomplete type");
        delete p;
    }
};

