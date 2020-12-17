//
// Created by ZintrulCre on 2020-11-25.
//

#ifndef LEADGREY_TESTCASE_SMARTPOINTER_H
#define LEADGREY_TESTCASE_SMARTPOINTER_H

#include "smart-pointer/pch.h"

template<typename T>
class Object
{
public:
    // constructor
    Object() : t_() { cout << "Object::Constructor " << this << endl; }
    Object(int t) : t_(t) { cout << "Object::Constructor " << this << endl; }

    // copy-ctor
    Object(const Object &other) { cout << "Object::Copy-ctor " << this << endl; }

    // destructor
    ~Object() { cout << "Object::Destructor " << this << endl; }

    void Set(T t) { t_ = t; }

    void Print() { cout << t_ << endl; }

private:
    T t_;
};

void AutoPointerFoo()
{
    // Object<int>* obj_ptr = new Object<int>(6);
    // obj_ptr->Print();

    // AutoPointer<Object<int>> obj_ptr(new Object<int>(1));
    // (*obj_ptr).Set(2);
    // (*obj_ptr).Print();
    // obj_ptr->Set(3);
    // obj_ptr->Print();

    // AutoPointer<Object<int>> p1(new Object<int>(6));
    // AutoPointer<Object<int>> p2(p1);
    // cout << "p2: "; p2->Print();
    // cout << "p1: "; p1->Print();

    // int *a = new int[1000000];
    // AutoPointer<int> p(a);
    
    Object<int>* obj_ptr = new Object<int>(6);
    AutoPointer<Object<int>> p1(obj_ptr);
    AutoPointer<Object<int>> p2(obj_ptr);
}

struct ArrayDeleter
{
    template<typename T>
    void operator()(T* p) const
    {
        static_assert(sizeof(p) > 0, "can't delete pointer to incomplete type");
        delete[] p;
    }
};

void UniquePointerFoo()
{
    // UniquePointer<Object<int>> p1(new Object<int>(6));
    // UniquePointer<Object<int>> p2{ p1 };

    // UniquePointer<Object<int>> p1(new Object<int>(6));
    // UniquePointer<Object<int>> p2(std::move(p1));
    // UniquePointer<Object<int>> p3;
    // p3 = std::move(p2);
    
    int* int_arr = new int[1000000];
    ArrayDeleter array_deleter;
    UniquePointer<int, ArrayDeleter> p(int_arr, array_deleter);

}

#endif