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
    explicit AutoPointer(T* t = nullptr) noexcept : ptr_(t) { std::cout << "AutoPointer::Constructor " << this << std::endl; }

    // copy-ctor
    AutoPointer(AutoPointer<T>& other) noexcept : ptr_(other.release()) { std::cout << "AutoPointer::Copyctor " << this << std::endl; }

    // assignment operator
    AutoPointer<T>& operator=(AutoPointer<T>& other)
    {
        reset(other.release());
        std::cout << "AutoPointer::Assignment " << this << std::endl;
        return *this;
    }

    // destructor
    ~AutoPointer() noexcept
    {
        delete ptr_;
        std::cout << "AutoPointer::Destructor " << this << std::endl;
    }

    T& operator*() noexcept { return *ptr_; }

    T* operator->() const noexcept { return ptr_; }

    T* get() const noexcept { return ptr_; }

    T* release() noexcept
    {
        T* ptr_ret = ptr_;
        ptr_ = nullptr;
        return ptr_ret;
    }

    void reset(T* ptr_para) noexcept
    {
        if (ptr_ != ptr_para)
        {
            delete ptr_;
            ptr_ = ptr_para;
        }
    }

private:
    T *ptr_;
};

#endif