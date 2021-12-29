#pragma once

#include "include/std.h"

class Solution {
    ListNode* ReverseList(ListNode* start, ListNode* behind) {
        ListNode *prev = nullptr, *curr = start, *next = nullptr;
        while (curr != behind) {
            cout << "Curr " << curr->val << endl;
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        return prev;
    }

public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode *v = new ListNode();
        v->next = head;
        ListNode *before, *start, *behind, *node = v;
        while (true) {
            before = node;
            start = node->next;
            for (int i = -1; i < k; ++i) {
                if (!node)
                    return v->next;
                node = node->next;
            }
            behind = node;
            node = ReverseList(start, behind);
            before->next = node;
            start->next = behind;
            node = start;
        }
        return v->next;
    }
};