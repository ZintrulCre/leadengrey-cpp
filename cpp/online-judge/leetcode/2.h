#pragma once

#include "include/std.h"
#include "online-judge/data-structure.h"

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int carry = 0, a, b;
        ListNode *res = l1, *prev = new ListNode(0, l1);
        while (l1 || l2) {
            a = l1 ? l1->val : 0;
            b = l2 ? l2->val : 0;
            int temp = a + b + carry;
            carry = temp / 10;
            ListNode *cur = l1 ? l1 : l2;
            cur->val = temp % 10;
            prev->next = cur;
            prev = prev->next;
            if (l1)
                l1 = l1->next;
            if (l2)
                l2 = l2->next;
        }
        if (carry)
            prev->next = new ListNode(1);
        return res;
    }
};