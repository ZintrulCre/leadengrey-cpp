//
// Created by ZintrulCre on 2020-11-25.
//

#ifndef LEADGREY_SMARTPOINTER_UNIQUEPOINTER_H
#define LEADGREY_SMARTPOINTER_UNIQUEPOINTER_H

#include "universal/std-pch.h"

template<typename ElementType, typename DeleterType = std::default_delete<ElementType>>
class UniquePointer {
public:
    // constructors
    constexpr UniquePointer() noexcept : ptr_() { std::cout << "UniquePointer " << this << " constructed." << std::endl; }
    constexpr UniquePointer(ElementType* ptr) noexcept : ptr_(ptr) { std::cout << "UniquePointer " << this << " constructed." << std::endl; }

    // move-ctor
    constexpr UniquePointer(T* t) noexcept : t_(t.release()) { std::cout << "UniquePointer " << this << " moved." << std::endl; }

    // copy-ctor
    UniquePointer(UniquePointer<T>& other) noexcept = delete;

    // assignment operator
    UniquePointer<T>& operator=(UniquePointer<T>& other) = delete;

    // destructor
    ~UniquePointer() noexcept
    {
        if (t_)
        {
            get_deleter()(ptr);
            t_ = nullptr;
        }
        std::cout << "UniquePointer " << this << " destructed." << std::endl;
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
    ElementType* ptr_ = nullptr;
};

void Foo()
{
    // Object<int>* obj_ptr = new Object<int>(6);
    // obj_ptr->Print();

    // UniquePointer<Object<int>> obj_ptr(new Object<int>(6));
    // (*obj_ptr).Set(5);
    // (*obj_ptr).Print();
    // obj_ptr->Set(4);
    // obj_ptr->Print();

    // UniquePointer<Object<int>> p1(new Object<int>(6));
    // UniquePointer<Object<int>> p2(p1);
    // if (p2.get()) { cout << "p2: "; p2->Print(); }
    // if (p1.get()) { cout << "p1: "; p1->Print(); }

    // UniquePointer<Object<int>> p3(new Object<int>(6));
    // UniquePointer<Object<int>> p4;
    // p4 = p3;
    // cout << "p4: "; p4->Print();
    // cout << "p3: "; p3->Print();

    // Object<int>* obj_ptr = new Object<int>(6);
    // UniquePointer<Object<int>> p1(obj_ptr);
    // UniquePointer<Object<int>> p2(obj_ptr);
}

int main()
{
    Foo();
    return 0;
}

#endif