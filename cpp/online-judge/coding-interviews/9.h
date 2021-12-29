#pragma once

#include "include/std.h"

class CQueue {
    std::stack<int> a, b;
public:
    CQueue() {
        a = std::stack<int>();
        b = std::stack<int>();
    }
    
    void appendTail(int value) {
        a.push(value);
    }
    
    int deleteHead() {
        if (b.empty()) {
            while (!a.empty()) {
                b.push(a.top());
                a.pop();
            }
        }
        if (b.empty())
            return -1;
        int ret = b.top();
        b.pop();
        return ret;
    }
};