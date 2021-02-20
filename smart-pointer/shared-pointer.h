//
// Created by ZintrulCre on 2021-02-20.
//

#ifndef LEADGREY_SMARTPOINTER_SHAREDPOINTER_H
#define LEADGREY_SMARTPOINTER_SHAREDPOINTER_H

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
class SharedPointer
{
public:
    // constructors
    SharedPointer() noexcept : ptr_(nullptr), ref_count_(nullptr) { std::cout << "SharedPointer::Constructor " << this << std::endl; }
    explicit SharedPointer(ElementType* p) noexcept : ptr_(p), ref_count_(new int(1)) { std::cout << "SharedPointer::Constructor " << this << std::endl; }
    SharedPointer(ElementType* p, DeleterType d) noexcept : ptr_(p), ref_count_(new int(1)), deleter_(d) { std::cout << "SharedPointer::Constructor " << this << std::endl; }

    // copy-ctor
    SharedPointer(SharedPointer<ElementType>& other) noexcept : ptr_(other.ptr_), ref_count_(other.ref_count_), deleter_(other.deleter_)
    {
        IncreaseReferenceCount();
    }

    // assignment operator
    SharedPointer& operator=(SharedPointer<ElementType>& other)
    {
        if (ptr_ != other.ptr_)
        {
            release();
            ptr_ = other.ptr_;
            ref_count_ = other.ref_count_;
            mutex_ = other.mutex_;
            deleter_ = other.deleter_;
            IncreaseReferenceCount();
        }
    }

    // move-ctor
    SharedPointer(SharedPointer<ElementType, DeleterType>&& other) noexcept : ptr_(other.release()), deleter_(std::move(other.deleter_)) { std::cout << "SharedPointer::Move-ctor " << this << std::endl; }
    // move assignment operator
    SharedPointer<ElementType, DeleterType>& operator=(SharedPointer<ElementType, DeleterType>&& other) noexcept
    {
        ptr_ = other.release();
        deleter_ = std::move(other.deleter_);
        std::cout << "SharedPointer::MoveAssignment " << this << std::endl;
        return *this;
    }

    // copy-ctor
    SharedPointer(SharedPointer<ElementType, DeleterType>& other) noexcept = delete;
    // assignment operator
    SharedPointer<ElementType, DeleterType>& operator=(SharedPointer<ElementType, DeleterType>& other) = delete;

    // destructor
    ~SharedPointer() noexcept
    {
        if (ptr_)
        {
            get_deleter()(ptr_);
            ptr_ = nullptr;
        }
        std::cout << "SharedPointer::Destructor " << this << std::endl;
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
	void IncreaseReferenceCount()
	{
		mutex_->lock();
		++(*ref_count_);
		mutex_->unlock();
	}

    int *ref_count_;
    ElementType* ptr_;
	mutex* mutex_;
    DeleterType deleter_;
};

#endif