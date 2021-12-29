#pragma once

#include "include/std.h"

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode *ret = new ListNode(0, head), *end = ret, *node = head;
        while (node) {
            if (!node->next || node->val != node->next->val) {
                end->next = node;
                end = end->next;
            }
            node = node->next;
        }
        return ret->next;
    }
};