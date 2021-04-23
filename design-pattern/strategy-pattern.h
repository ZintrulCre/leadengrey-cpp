#pragma once

#include "include/std.h"

template<typename T>
class BaseStrategy
{
public:
    virtual ~BaseStrategy() {}
    virtual void StrategyImpl() = 0;
};

template<typename T>
class StrategyA : public BaseStrategy<T>
{
public:
    virtual void StrategyImpl()
    {
        cout << "A" << endl;
    }
};

template<typename T>
class StrategyB : public BaseStrategy<T>
{
public:
    virtual void StrategyImpl()
    {
        cout << "B" << endl;
    }
};
