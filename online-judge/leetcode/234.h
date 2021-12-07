#pragma once

#include "include/std.h"

class Solution {
    ListNode *ReverseLinkedList(ListNode *node, ListNode *behind) {
        ListNode *prev = nullptr, *curr = node, *next = nullptr;
        while (curr) {
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        return prev;
    }

public:
    bool isPalindrome(ListNode* head) {
        ListNode *s = head, *f = head, *before = nullptr;
        while (f && f->next) {
            before = s;
            s = s->next;
            f = f->next->next;
        }
        if (f) {
            before = s;
            f = f->next;
        }
        before->next = ReverseLinkedList(before->next, f);
        ListNode *first = head, *second = before->next;
        while (second) {
            if (first->val != second->val)
                return false;
            first = first->next;
            second = second->next;
        }
        return true;
    }
};