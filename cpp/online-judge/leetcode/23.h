#pragma once

#include "include/std.h"
#include "online-judge/data-structure.h"

class Solution {
    ListNode* merge2(ListNode* a, ListNode* b) {
        ListNode* prehead = new ListNode(0), *prev = prehead;
        while (a && b) {
            if (a->val < b->val) {
                prev->next = a;
                a = a->next;
            } else {
                prev->next = b;
                b = b->next;
            }
        }
        prev->next = a ? a : b;
        ListNode *temp = prehead->next;
        delete prehead;
        return temp;
    }

    ListNode *mergeMultiple(vector<ListNode*>& lists, int x, int y) {
        if (x > y)
            return nullptr;
        if (x == y)
            return lists[x];
        if (x == y - 1)
            return merge2(lists[x], lists[y]);
        int z = x + ((y-x) >> 1);
        return merge2(mergeMultiple(lists, x, z), mergeMultiple(lists, z+1, y));

    }

public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        return mergeMultiple(lists, 0, lists.size() - 1);
    }
};