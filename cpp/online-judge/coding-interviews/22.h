#pragma once

#include "include/std.h"
#include "online-judge/data-structure.h"

class Solution {
public:
    ListNode* getKthFromEnd(ListNode* head, int k) {
        int m = 0;
        ListNode *a = head, *b = head;
        while(a) {
            a = a->next;
            ++m;
            if (m>k)
                b = b->next;
        }
        return b;
    }
};