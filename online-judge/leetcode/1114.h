//
// Created by ZintrulCre on 2020-09-17.
//

//#pragma once

// #include "universal/std-pch.h"

// class Foo {
//     mutex mtx_1, mtx_2;
//     unique_lock<mutex> lock_1, lock_2;
// public:
//     Foo() : lock_1(mtx_1, try_to_lock), lock_2(mtx_2, try_to_lock) {
//     }

//     void first(function<void()> printFirst) {
//         printFirst();
//         lock_1.unlock();
//     }

//     void second(function<void()> printSecond) {
//         lock_guard<mutex> guard(mtx_1);
//         printSecond();
//         lock_2.unlock();
//     }

//     void third(function<void()> printThird) {
//         lock_guard<mutex> guard(mtx_2);
//         printThird();
//     }
// };
