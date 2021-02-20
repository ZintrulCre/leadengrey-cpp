//
// Created by ZintrulCre on 2020-11-25.
//

#ifndef LEADGREY_SMARTPOINTER_UNIQUEPOINTER_H
#define LEADGREY_SMARTPOINTER_UNIQUEPOINTER_H

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

template<typename ElementType, typename DeleterType = DefaultDeleter>
class UniquePointer
{
public:
    // constructors
    UniquePointer() noexcept : ptr_(nullptr) { std::cout << "UniquePointer::Constructor " << this << std::endl; }
    explicit UniquePointer(ElementType* p) noexcept : ptr_(p) { std::cout << "UniquePointer::Constructor " << this << std::endl; }
    UniquePointer(ElementType* p, DeleterType d) noexcept : ptr_(p), deleter_(d) { std::cout << "UniquePointer::Constructor " << this << std::endl; }

    // move-ctor
    UniquePointer(UniquePointer<ElementType, DeleterType>&& other) noexcept : ptr_(other.release()), deleter_(std::move(other.deleter_)) { std::cout << "UniquePointer::Move-ctor " << this << std::endl; }
    // move assignment operator
    UniquePointer<ElementType, DeleterType>& operator=(UniquePointer<ElementType, DeleterType>&& other) noexcept
    {
        ptr_ = other.release();
        deleter_ = std::move(other.deleter_);
        std::cout << "UniquePointer::MoveAssignment " << this << std::endl;
        return *this;
    }

    // copy-ctor
    UniquePointer(UniquePointer<ElementType, DeleterType>& other) noexcept = delete;
    // assignment operator
    UniquePointer<ElementType, DeleterType>& operator=(UniquePointer<ElementType, DeleterType>& other) = delete;

    // destructor
    ~UniquePointer() noexcept
    {
        if (ptr_)
        {
            get_deleter()(ptr_);
            ptr_ = nullptr;
        }
        std::cout << "UniquePointer::Destructor " << this << std::endl;
    }

    ElementType& operator*() noexcept { return *ptr_; }

    ElementType* operator->() const noexcept { return ptr_; }

    ElementType* get() const noexcept { return ptr_; }

    const DeleterType& get_deleter() const noexcept { return deleter_; }

    ElementType* release() noexcept
    {
        ElementType* ret = nullptr;
        std::swap(ptr_, ret);
        return ret;
    }

    void reset(ElementType* p) noexcept
    {
        if (ptr_ != p)
        {
            delete ptr_;
            ptr_ = p;
        }
    }

private:
    ElementType* ptr_;
    DeleterType deleter_;
};

#endif