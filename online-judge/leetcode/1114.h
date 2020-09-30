
// Created by ZintrulCre on 2020-09-17.


#pragma once

#include "universal/std-pch.h"

class Foo {
    condition_variable cv;
    mutex mtx;
    int k = 0;
public:
    void first(function<void()> printFirst) {
        printFirst();
        k = 1;
        cv.notify_all();
    }

    void second(function<void()> printSecond) {
        unique_lock<mutex> lock(mtx);
        cv.wait(lock, [this](){ return k == 1; });
        printSecond();
        k = 2;
        cv.notify_one();
    }

    void third(function<void()> printThird) {
        unique_lock<mutex> lock(mtx);
        cv.wait(lock, [this](){ return k == 2; });
        printThird();
    }
};