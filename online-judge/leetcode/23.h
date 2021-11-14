#pragma once

#include "include/std.h"

class Solution {
    struct Cmp {
        operator < (const ListNode* p1, const ListNode* p2) {
            return p1->val < p2->val;
        }
    };

public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        ListNode* vir = new ListNode(), *node = vir;
        std::priority_queue<ListNode*, std::vector<ListNode*>, Cmp> h;
        for (auto l : lists)
            h.push(l);
        while(!h.empty()) {
            temp = h.top();
            node->next = temp;
            node = node->next;
            h.pop();
            if (node->next) {
                h.push(node->next);
            }
        }
        return vir->next;
    }
};