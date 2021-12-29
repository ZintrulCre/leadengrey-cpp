#pragma once

#include "include/std.h"

class Solution {
public:
    ListNode* middleNode(ListNode* head) {
        if (!head)  return nullptr;
        ListNode *f = head, *s = head;
        while (f && f->next) {
            s = s->next;
            f = f->next->next;
        }
        return s;
    }
};