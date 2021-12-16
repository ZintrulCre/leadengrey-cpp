#pragma once

#include "include/std.h"
#include "base/base.h"

class Solution {
    stack<char> ops;
    stack<int> nums;
    map<char, int> priority{{'+', 1}, {'-', 1}, {'*', 2}, {'/', 2}};

    void Operate() {
        char op = ops.top();    ops.pop();
        int b = nums.top(); nums.pop();
        int a = nums.top(); nums.pop();
        int res = 0;
        if (op == '+')  res = a + b;
        if (op == '-')  res = a - b;
        if (op == '*')  res = a * b;
        if (op == '/')  res = a / b;
        nums.push(res);
        // printf("a %d %c b %d = %d\n", a, op, b, res);
    }

public:
    int calculate(string s) {
        s = '0' + s;
        int n = s.size();
        ops = stack<char>();
        nums = stack<int>();
        for (int i = 0; i < n; ++i) {
            char c = s[i];
            if (c == ' ')
                continue;
            if (c >= '0' && c <= '9') {
                int num = 0;
                int j = i;
                while (j < n && s[j] >= '0' && s[j] <= '9') {
                    num = num * 10 + (s[j] - '0');
                    ++j;
                }
                nums.push(num);
                i = j - 1;
            } else {
                if (c == '(') {
                    ops.push(c);
                } else if (c == ')') {
                    while (!ops.empty() && ops.top() != '(')
                        Operate();
                    ops.pop();
                } else {
                    if (!ops.empty() && ops.top() == '(')
                        nums.push(0);
                    int prio = priority[c];
                    while (!ops.empty() && priority[ops.top()] >= prio)
                        Operate();
                    ops.push(c);
                }
            }
        }
        while (!ops.empty())
            Operate();
        return nums.top();
    }
};