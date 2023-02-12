#pragma once

#include "include/std.h"

class Solution {
    unordered_map<int, Node*> um;

public:
    Node* cloneGraph(Node* node) {
        if (!node)
            return nullptr;
        auto iter = um.find(node->val);
        if (iter != um.end())
            return iter->second;
        Node* newNode = new Node(node->val);
        um.insert({node->val, newNode});
        for (Node* neighbor : node->neighbors)
            newNode->neighbors.push_back(cloneGraph(neighbor));
        return newNode;
    }
};

//vector<Node*> neighbors;