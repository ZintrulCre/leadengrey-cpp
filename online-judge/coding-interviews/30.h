#pragma once

#include "include/std.h"

class MinStack {
private:
    std::stack<int> s, min_s;
public:
    /** initialize your data structure here. */
    MinStack() {
        s = std::stack<int>();
        min_s = std::stack<int>();
    }
    
    void push(int x) {
        s.push(x);
        if (min_s.empty() || x <= min_s.top())
            min_s.push(x);
    }
    
    void pop() {
        int x = s.top();
        s.pop();
        if (min_s.top() == x)
            min_s.pop();
    }
    
    int top() {
        return s.top();
    }
    
    int min() {
        return min_s.top();
    }
};
