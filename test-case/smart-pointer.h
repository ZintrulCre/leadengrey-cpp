//
// Created by ZintrulCre on 2020-11-25.
//

#ifndef LEADGREY_TESTCASE_SMARTPOINTER_H
#define LEADGREY_TESTCASE_SMARTPOINTER_H

template<typename T>
class Object
{
public:
    // constructor
    Object(int t) : t_(t) { cout << "Object " << this << " Constructed." << endl; }

    // copy-ctor
    Object(const Object &other) { cout << "Object " << this << " Copied." << endl; }

    // destructor
    ~Object() { cout << "Object " << this << " Destructed." << endl; }

    void Set(T t) { t_ = t; }

    void Print() { cout << t_ << endl; }

private:
    T t_ = 0;
};

void AutoPointerFoo()
{
    // Object<int>* obj_ptr = new Object<int>(6);
    // obj_ptr->Print();

    // AutoPointer<Object<int>> obj_ptr(new Object<int>(6));
    // (*obj_ptr).Set(5);
    // (*obj_ptr).Print();
    // obj_ptr->Set(4);
    // obj_ptr->Print();

    // AutoPointer<Object<int>> p1(new Object<int>(6));
    // AutoPointer<Object<int>> p2(p1);
    // if (p2.get()) { cout << "p2: "; p2->Print(); }
    // if (p1.get()) { cout << "p1: "; p1->Print(); }

    // AutoPointer<Object<int>> p3(new Object<int>(6));
    // AutoPointer<Object<int>> p4;
    // p4 = p3;
    // cout << "p4: "; p4->Print();
    // cout << "p3: "; p3->Print();

    // Object<int>* obj_ptr = new Object<int>(6);
    // AutoPointer<Object<int>> p1(obj_ptr);
    // AutoPointer<Object<int>> p2(obj_ptr);
}

void UniquePointerFoo()
{
    
}

#endif