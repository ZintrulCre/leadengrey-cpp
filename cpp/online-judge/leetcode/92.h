#pragma once

#include "include/std.h"

class Solution {
public:
    ListNode* ReverseList(ListNode* start, ListNode* behind) {
        ListNode *prev = nullptr, *curr = start, *next = nullptr;
        while (curr != behind) {
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        return prev;
    }

    ListNode* reverseBetween(ListNode* head, int left, int right) {
        ListNode *v = new ListNode();
        v->next = head;
        ListNode *before = nullptr, *start = nullptr, *end = nullptr, *behind = nullptr, *node = v;
        for (int i = -1; i < right; ++i) {
            if (i == left-2)
                before = node;
            if (i == left-1)
                start = node;
            if (i == right-1)
                end = node;
            node = node->next;
        }
        behind = node;
        node = ReverseList(start, behind);
        before->next = node;
        while (node->next)
            node = node->next;
        node->next = behind;
        return v->next;
    }
};