#pragma once

#include "include/std.h"

class MyQueue {
    std::stack<int> in, out;
public:
    void push(int x) {
        in.push(x);
    }
    
    int pop() {
        int res = peek();
        out.pop();
        return res;
    }
    
    int peek() {
        if (out.empty()) {
            while (!in.empty()) {
                out.push(in.top());
                in.pop();
            }
        }
        return out.top();
    }
    
    bool empty() {
        return in.empty() && out.empty();
    }
};
