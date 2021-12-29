#pragma once

#include "include/std.h"

class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        if (!head)  return nullptr;
        ListNode *f = head, *s = head;
        do {
            s = s->next;
            f = f->next;
            if (!f || !f->next) return nullptr;
            f = f->next;
        } while (s != f);
        f = head;
        while (s != f) {
            s = s->next;
            f = f->next;
        }
        return s;
    }
};