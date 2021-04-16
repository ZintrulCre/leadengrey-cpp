//
// Created by ZintrulCre on 2021-02-20.
//

#ifndef LEADENGREY_SMARTPOINTER_SHAREDPOINTER_H
#define LEADENGREY_SMARTPOINTER_SHAREDPOINTER_H

#include "universal/std-pch.h"
#include "smart-pointer/pch.h"

template<typename ElementType, typename DeleterType = DefaultDeleter>
class SharedPointer
{
public:
    // constructors
    SharedPointer() noexcept : ptr_(nullptr), ref_count_(nullptr), deleter_(nullptr), mutex_(nullptr) { std::cout << "SharedPointer::Constructor " << this << std::endl; }
    explicit SharedPointer(ElementType* p) noexcept : ptr_(p), ref_count_(new int(1)), deleter_(new DeleterType()), mutex_(new mutex()) { std::cout << "SharedPointer::Constructor " << this << std::endl; }
    SharedPointer(ElementType* p, DeleterType *d) noexcept : ptr_(p), ref_count_(new int(1)), deleter_(d), mutex_(new mutex()) { std::cout << "SharedPointer::Constructor " << this << std::endl; }
    explicit SharedPointer(const WeakPointer<ElementType, DeleterType>& wp) noexcept : ptr_(wp.ptr_), ref_count_(wp.ref_count_), deleter_(wp.deleter_), mutex_(wp.mutex_)
    {
        std::cout << "SharedPointer::Constructor " << this << std::endl;
        IncreaseReferenceCount();
    }

    // copy-ctor
    SharedPointer(const SharedPointer<ElementType>& other) noexcept : ptr_(other.ptr_), ref_count_(other.ref_count_), deleter_(other.deleter_), mutex_(other.mutex_)
    {
        std::cout << "SharedPointer::Copy-ctor " << this << std::endl;
        IncreaseReferenceCount();
    }

    // assignment operator
    SharedPointer& operator=(SharedPointer<ElementType>& other)
    {
        if (ptr_ != other.ptr_)
        {
            Release();
            ptr_ = other.ptr_;
            ref_count_ = other.ref_count_;
            mutex_ = other.mutex_;
            deleter_ = other.deleter_;
            IncreaseReferenceCount();
        }
        return *this;
    }

    // destructor
    ~SharedPointer() noexcept
    {
        std::cout << "SharedPointer::Destructor " << this << std::endl;
        Release();
    }

    void Swap(SharedPointer<ElementType, DeleterType>& other)
    {
        std::swap(ptr_, other.ptr_);
        std::swap(ref_count_, other.ref_count_);
        std::swap(deleter_, other.deleter_);
        std::swap(mutex_, other.mutex_);
    }

    void Reset() { SharedPointer().Swap(*this); }
    void Reset(ElementType* p, DeleterType* d = nullptr) { SharedPointer(p, d).Swap(*this); }

    int UseCount() { return ref_count_ ? *ref_count_ : 0; }

    ElementType& operator*() noexcept { return *ptr_; }

    ElementType* operator->() const noexcept { return ptr_; }

    ElementType* Get() const noexcept { return ptr_; }

    const DeleterType& GetDeleter() const noexcept { return *deleter_; }
    
    void Release()
    {
        if (!ptr_)
            return;
        bool delete_flag = false;
        mutex_->lock();
        if (--(*ref_count_) == 0)
        {
            GetDeleter()(ptr_);
            delete ref_count_;
            delete deleter_;
            delete_flag = true;
        }
        mutex_->unlock();
        
        if (delete_flag)
        {
            delete mutex_;
        }
        
    }

	void IncreaseReferenceCount()
	{
        if (!ptr_)
            return;
		mutex_->lock();
        ++(*ref_count_);
		mutex_->unlock();
	}
    
    ElementType* ptr_;
    int *ref_count_;
    DeleterType* deleter_;
	mutex* mutex_;
};

#endif