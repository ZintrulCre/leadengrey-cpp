#pragma once

#include "include/std.h"

class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode *prev = new ListNode(), *node = head, *next = head->next;
        prev->next = head;
        ListNode *ret = prev;
        for (int i = 0; i < n; ++i)
            head = head->next;
        while (head) {
            head = head->next;
            prev = node;
            node = next;
            next = next->next;
        }
        prev->next = next;
        return ret->next;
    }
};