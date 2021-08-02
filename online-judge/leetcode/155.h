#pragma once

#include "include/std.h"
#include "online-judge/online-judge.h"

class MinStack {
    std::vector<int> a, b;
public:
    MinStack() {
        a = std::vector<int>(), b = std::vector<int>();
    }
    
    void push(int val) {
        a.emplace_back(val);
        if (b.empty() || val < b.back())
            b.emplace_back(val);
    }
    
    void pop() {
        if (a.back() == b.back())
            b.pop_back();
        a.pop_back();
    }
    
    int top() {
        return a.empty() ? 0 : a.back();
    }
    
    int getMin() {
        return b.empty() ? 0 : b.back();
    }
};
