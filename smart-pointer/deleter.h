//
// Created by ZintrulCre on 2021-02-20.
//

#ifndef LEADGREY_SMARTPOINTER_DELETER_H
#define LEADGREY_SMARTPOINTER_DELETER_H

#include "universal/std-pch.h"

struct DefaultDeleter
{
    template<typename T>
    void operator()(T* p) const
    {
        static_assert(sizeof(p) > 0, "can't delete pointer to incomplete type");
        delete p;
    }
};

#endif