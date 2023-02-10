#pragma once

#include "include/std.h"
#include "online-judge/pch.h"

class Solution {
    TreeNode* divide(ListNode *head, ListNode *tail) {
        if (head == tail)
            return nullptr;
        ListNode *slow = head, *fast = head;
        while (fast != tail && fast->next != tail) {
            fast = fast->next->next;
            slow = slow->next;
        }
        // cout << slow->val << endl;
        TreeNode *node = new TreeNode(slow->val);
        node->left = divide(head, slow);
        node->right = divide(slow->next, tail);
        return node;
    }

public:
    TreeNode* sortedListToBST(ListNode* head) {
        return divide(head, nullptr);
    }
};