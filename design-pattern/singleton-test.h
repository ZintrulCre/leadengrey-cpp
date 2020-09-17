//
// Created by ZintrulCre on 2020-09-10.
//

#ifndef LEADGREY_DESIGNPATTERN_SINGLETONTEST_H
#define LEADGREY_DESIGNPATTERN_SINGLETONTEST_H

#include "universal/std-pch.h"

class Foo : public Singleton<Foo>
{
public:
    void operator() ()
    {
        cout << &GetInstance() << endl;
    }
};

class LazyFoo : public LazySingleton<LazyFoo, false>
{
public:
    void operator() ()
    {
        cout << &GetInstance() << endl;
    }
};

class ThreadSafeLazyFoo : public LazySingleton<ThreadSafeLazyFoo>
{
public:
    void operator() ()
    {
        cout << &GetInstance() << endl;
    }
};

class EagerFoo : public EagerSingleton<EagerFoo>
{
public:
    void operator() ()
    {
        cout << &GetInstance() << endl;
    }
};

void SingletonTest()
{
    thread t1((Foo()));
    thread t2((Foo()));
    t1.join();
    t2.join();
    this_thread::sleep_for(chrono::milliseconds(100));
    
    t1 = thread((LazyFoo()));
    t2 = thread((LazyFoo()));
    t1.join();
    t2.join();
    this_thread::sleep_for(chrono::milliseconds(100));
    
    t1 = thread((ThreadSafeLazyFoo()));
    t2 = thread((ThreadSafeLazyFoo()));
    t1.join();
    t2.join();
    this_thread::sleep_for(chrono::milliseconds(100));
    
    t1 = thread((EagerFoo()));
    t2 = thread((EagerFoo()));
    t1.join();
    t2.join();
}

#endif