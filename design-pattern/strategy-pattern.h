#pragma once

#include "include/std.h"

class BaseStrategy
{
public:
    virtual ~BaseStrategy() {}
    virtual void StrategyImpl() = 0;
};

class StrategyA : public BaseStrategy
{
public:
    virtual void StrategyImpl()
    {
        int a = 1;
        cout << a << endl;
    }
};

class StrategyB : public BaseStrategy
{
public:
    virtual void StrategyImpl()
    {
        int b = 2;
        cout << b << endl;
    }
};
