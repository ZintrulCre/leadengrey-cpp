//
// Created by ZintrulCre on 2020-11-25.
//

#ifndef LEADGREY_SMARTPOINTER_AUTOPOINTER_H
#define LEADGREY_SMARTPOINTER_AUTOPOINTER_H

#include "universal/std-pch.h"

template<typename T>
class AutoPointer
{
public:
    // constructor
    explicit AutoPointer(T* t = nullptr) noexcept : ptr(t) { std::cout << "AutoPointer " << this << " constructed." << std::endl; }

    // copy-ctor
    AutoPointer(AutoPointer<T>& other) noexcept : ptr(other.release()) { std::cout << "AutoPointer " << this << " copied." << std::endl; }

    // assignment operator
    AutoPointer<T>& operator=(AutoPointer<T>& other)
    {
        std::cout << "AutoPointer " << this << " assigned." << std::endl;
        reset(other.release());
        return *this;
    }

    // destructor
    ~AutoPointer() noexcept
    {
        delete ptr;
        std::cout << "AutoPointer " << this << " destructed." << std::endl;
    }

    T& operator*() noexcept { return *ptr; }

    T* operator->() const noexcept { return ptr; }

    T* get() const noexcept { return ptr; }

    T* release() noexcept
    {
        T* ptr_ret = ptr;
        ptr = nullptr;
        return ptr_ret;
    }

    void reset(T* ptr_para) noexcept
    {
        if (ptr != ptr_para)
        {
            delete ptr;
            ptr = ptr_para;
        }
    }

private:
    T *ptr;
};

#endif