#pragma once

#include "include/std.h"
#include "smart-pointer/deleter.h"

template<typename ElementType, typename DeleterType = DefaultDeleter>
class UniquePointer
{
public:
    // constructors
    UniquePointer() noexcept : ptr_(nullptr) { std::cout << "UniquePointer::Constructor " << this << std::endl; }
    explicit UniquePointer(ElementType* p) noexcept : ptr_(p) { std::cout << "UniquePointer::Constructor " << this << std::endl; }
    UniquePointer(ElementType* p, DeleterType d) noexcept : ptr_(p), deleter_(d) { std::cout << "UniquePointer::Constructor " << this << std::endl; }

    // move-ctor
    UniquePointer(UniquePointer<ElementType, DeleterType>&& other) noexcept : ptr_(other.Release()), deleter_(std::move(other.deleter_)) { std::cout << "UniquePointer::Move-ctor " << this << std::endl; }
    // move assignment operator
    UniquePointer<ElementType, DeleterType>& operator=(UniquePointer<ElementType, DeleterType>&& other) noexcept
    {
        std::cout << "UniquePointer::MoveAssignment " << this << std::endl;
        ptr_ = other.Release();
        deleter_ = std::move(other.deleter_);
        return *this;
    }

    // copy-ctor
    UniquePointer(UniquePointer<ElementType, DeleterType>& other) noexcept = delete;
    // assignment operator
    UniquePointer<ElementType, DeleterType>& operator=(UniquePointer<ElementType, DeleterType>& other) = delete;

    // destructor
    ~UniquePointer() noexcept
    {
        std::cout << "UniquePointer::Destructor " << this << std::endl;
        if (ptr_)
        {
            GetDeleter()(ptr_);
            ptr_ = nullptr;
        }
    }

    ElementType& operator*() noexcept { return *ptr_; }

    ElementType* operator->() const noexcept { return ptr_; }

    ElementType* Get() const noexcept { return ptr_; }

    const DeleterType& GetDeleter() const noexcept { return deleter_; }

    ElementType* Release() noexcept
    {
        ElementType* ret = nullptr;
        std::swap(ptr_, ret);
        return ret;
    }

    void Reset(ElementType* p) noexcept
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

