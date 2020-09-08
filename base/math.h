#ifndef LEADGREY_BASE_MATH_H
#define LEADGREY_BASE_MATH_H

#include "base/pch.h"

namespace leadgrey
{

template<typename ValueType>
ValueType Max(ValueType)
{
    return std::numeric_limits<ValueType>::max();
}

template<typename ValueType>
ValueType Min(ValueType)
{
    return std::numeric_limits<ValueType>::min();
}

template<typename ValueType>
ValueType Add()
{
    return 0;
}

template<typename ValueType, typename ...ValueTypes>
ValueType Add(const ValueType &value, const ValueTypes &...other_values)
{
    ValueType sum = Add<ValueType>(other_values...);
    if (value > Max(sum) - sum)
    {
        return Max(sum);
    }
    return value + sum;
}

template<typename ValueType>
ValueType Minus()
{
    return 0;
}

template<typename ValueType, typename ...ValueTypes>
ValueType Minus(const ValueType &value, const ValueTypes &...other_values)
{
    ValueType difference = Minus<ValueType>(other_values...);
    if (value < Min(difference) + difference)
    {
        return Min(difference);
    }
    return value - difference;
}

} // namespace LeadGrey

#endif