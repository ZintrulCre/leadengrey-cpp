#pragma once

#include "include/std.h"

class Solution {
    bool IsLeapYear(int year) {
        if (year % 100 == 0 && year % 400 == 0)
            return true;
        return year % 4 == 0;
    }
public:
    int dayOfYear(string date) {
        int year, month, day;
        char delimiter = '-';
        int i = date.find(delimiter);
        year = stoi(date.substr(0, i));
        int j = date.find(delimiter, i + 1);
        month = stoi(date.substr(i + 1, j - i - 1));
        day = stoi(date.substr(j + 1));
        // printf("%d-%d-%d\n",year,month,day);
        int ret = 0;
        for (int i = 1; i < month; ++i) {
            if (i == 1 || i == 3 || i == 5 || i == 7 || i == 8 || i == 10 || i == 12)
                ret += 31;
            else if (i == 4 || i == 6 || i == 9 || i == 11)
                ret += 30;
            else
                ret += IsLeapYear(year) ? 29 : 28;
        }
        return ret + day;
    }
};