#pragma once

#include "include/std.h"

class MyStack {
    std::vector<std::queue<int>> v;
    int cacheTop, inUse = 0;
public:
    MyStack() {
        v = std::vector<std::queue<int>>(2, std::queue<int>());
    }

    void push(int x) {
        v[inUse%2].push(x);
        cacheTop = x;
    }
    
    int pop() {
        int n = v[inUse%2].size();
        int newUse = (inUse+1)%2;
        for (int i = 0; i < n-1; i++) {
            v[newUse].push(v[inUse%2].front());
            if (i == n-2)
                cacheTop = v[inUse%2].front();
            v[inUse%2].pop();
        }
        int res = v[inUse%2].front();
        v[inUse%2].pop();
        inUse = (inUse+1) % 2;
        return res;
    }
    
    int top() {
        return cacheTop;
    }
    
    bool empty() {
        return v[inUse%2].empty();
    }
};