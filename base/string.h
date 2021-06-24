#pragma once

namespace leadengrey
{
template<typename T, size_t size>
size_t GetArraySize(T (&)[size])
{
    return size;
}

} // namespace leadengrey
