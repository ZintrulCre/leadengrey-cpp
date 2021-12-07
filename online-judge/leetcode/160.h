#pragma once

#include "include/std.h"

class Solution {
public:
    ListNode *getIntersectionNode(ListNode *a, ListNode *b) {
        ListNode *hA = a, *hB = b;
        bool bA = false, bB = false;
        while(a != b) {
            a = a->next;
            b = b->next;
            if (!a) {
                if (bA)
                    return nullptr;
                a = hB;
                bA = true;
            }
            if (!b) {
                if (bB)
                    return nullptr;
                b = hA;
                bB = true;
            }
        }
        return a;
    }
};