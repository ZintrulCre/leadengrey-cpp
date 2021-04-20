//
// Created by ZintrulCre on 2021-02-20.
//

#pragma once

#include "include/std.h"
#include "smart-pointer/deleter.h"

template<typename ElementType, typename DeleterType> class SharedPointer;

template<typename ElementType, typename DeleterType = DefaultDeleter>
class WeakPointer
{
public:
    // constructors
    WeakPointer() noexcept : ptr_(nullptr), ref_count_(nullptr), deleter_(nullptr), mutex_(nullptr) { std::cout << "WeakPointer::Constructor " << this << std::endl; }
    explicit WeakPointer(SharedPointer<ElementType, DeleterType>& sp) noexcept : ptr_(sp.ptr_), ref_count_(sp.ref_count_), deleter_(sp.deleter_), mutex_(sp.mutex_) { std::cout << "WeakPointer::Constructor " << this << std::endl; }

    // copy-ctor
    WeakPointer(WeakPointer<ElementType>& other) noexcept : ptr_(other.ptr_), ref_count_(other.ref_count_), deleter_(other.deleter_), mutex_(other.mutex_)
    {
        std::cout << "WeakPointer::Copy-ctor " << this << std::endl;
    }

    // assignment operator
    WeakPointer& operator=(SharedPointer<ElementType, DeleterType>& sp)
    {
        ptr_ = sp.ptr_;
        ref_count_ = sp.ref_count_;
        mutex_ = sp.mutex_;
        deleter_ = sp.deleter_;
        return *this;
    }

    // destructor
    ~WeakPointer() noexcept { std::cout << "WeakPointer::Destructor " << this << std::endl; }

    void Swap(WeakPointer& other)
    {
        std::swap(ptr_, other.ptr_);
        std::swap(ref_count_, other.ref_count_);
        std::swap(deleter_, other.deleter_);
        std::swap(mutex_, other.mutex_);
    }

    void Reset() { WeakPointer().Swap(*this); }

    SharedPointer<ElementType, DeleterType> Lock() const
    {
        return Expired() ? SharedPointer<ElementType, DeleterType>()
                         : SharedPointer<ElementType, DeleterType>(*this);
    }

    int UseCount() { return *ref_count_; }

    const DeleterType& GetDeleter() const noexcept { return *deleter_; }

    bool Expired() const { return *ref_count_ == 0; }

    ElementType* ptr_;
    int *ref_count_;
    DeleterType* deleter_;
	mutex* mutex_;
};

