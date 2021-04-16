//
// Created by ZintrulCre on 2020-11-25.
//

#ifndef LEADENGREY_TESTCASE_SMARTPOINTER_H
#define LEADENGREY_TESTCASE_SMARTPOINTER_H

#include "smart-pointer/pch.h"

template<typename T>
class Object
{
public:
    // constructor
    Object() : t_() { cout << "Object::Constructor " << this << endl; }
    Object(T t) : t_(t) { cout << "Object::Constructor " << this << endl; }

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
    // Object<int>* o = new Object<int>(1);
    // o->Print();

    // Object<int>* o = new Object<int>(1);
    // AutoPointer<Object<int>> a(o);
    // (*o).Set(2);
    // (*o).Print();
    // o->Set(3);
    // o->Print();

    // Object<int>* o = new Object<int>(1);
    // AutoPointer<Object<int>> a1(o);
    // AutoPointer<Object<int>> a2(a1);
    // cout << "a2: "; a2->Print();
    // cout << "a1: "; a1->Print();

    // int *a = new int[1000000];
    // AutoPointer<int> p(a);
    
    // Object<int>* o = new Object<int>(1);
    // AutoPointer<Object<int>> a1(o);
    // AutoPointer<Object<int>> a2(o);
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
    // Object<int>* o = new Object<int>(1);
    // UniquePointer<Object<int>> u1(o);
    // UniquePointer<Object<int>> u2{ u1 };

    // Object<int>* o = new Object<int>(1);
    // UniquePointer<Object<int>> u1(o);
    // UniquePointer<Object<int>> u2(std::move(u1));
    // UniquePointer<Object<int>> u3;
    // u3 = std::move(u2);
    
    // Object<int>* o_array = new Object<int>(1)[3];
    // int* int_arr = new int[3];
    // ArrayDeleter array_deleter;
    // UniquePointer<int, ArrayDeleter> u(o_array, array_deleter);

}

void SharedPointerFoo()
{
    // Object<int>* o = new Object<int>(1);
    // SharedPointer<Object<int>> s1(o);
    // SharedPointer<Object<int>> s2(s1);
    // s1.Reset(nullptr);
    // s2.Reset(nullptr);

    struct Node
    {
        int i_;
        SharedPointer<Node> prev_;
        SharedPointer<Node> next_;

        Node(int i) : i_(i) { std::cout << "Node::Constructor " << this << std::endl; }
        ~Node() { std::cout << "Node::Destructor " << this << std::endl; }
    };

    Node *n1 = new Node(1), *n2 = new Node(2);
    SharedPointer<Node> s1(n1), s2(n2);
    cout << s1.UseCount() << ' ' << s2.UseCount() << endl;
    s1->next_ = s2;
    s2->prev_ = s1;
    cout << s1.UseCount() << ' ' << s2.UseCount() << endl;
}

void WeakPointerFoo()
{
    Object<string> *o = new Object<string>("test");
    SharedPointer<Object<string>> s(o);
    WeakPointer<Object<string>> w(s);
    s.Reset();

    auto p = w.Lock().Get();
    cout << w.Expired() << endl;
    cout << static_cast<void*>(p) << endl;


    // struct Node
    // {
    //     int i_;
    //     WeakPointer<Node> prev_;
    //     WeakPointer<Node> next_;

    //     Node(int i) : i_(i) { std::cout << "Node::Constructor " << this << std::endl; }
    //     ~Node() { std::cout << "Node::Destructor " << this << std::endl; }
    // };

    // Node *n1 = new Node(1), *n2 = new Node(2);
    // SharedPointer<Node> s1(n1), s2(n2);
    // cout << s1.UseCount() << ' ' << s2.UseCount() << endl;
    // s1->next_ = s2;
    // s2->prev_ = s1;
    // cout << s1.UseCount() << ' ' << s2.UseCount() << endl;
}

#endif