#pragma once

#include "include/std.h"
#include "online-judge/pch.h"

class Solution {
public:
    int minCameraCover(TreeNode* root) {
        int res = 0;
        enum class Status : int8_t
        {
            HasCamera,
            Covered,
            NotCovered
        };
        function<Status(TreeNode*)> Traverse = [&](TreeNode* node) -> Status
        {
            if (!node)
                return Status::Covered;
                
            Status left_status = Traverse(node->left);
            Status right_status = Traverse(node->right);

            if (left_status == Status::NotCovered || right_status == Status::NotCovered)
            {
                ++res;
                return Status::HasCamera;
            }
            
            if (left_status == Status::HasCamera || right_status == Status::HasCamera)
            {
                return Status::Covered;
            }
            
            // left_status == Status::Covered && right_status == Status::Covered
            return Status::NotCovered;
        };
        res += (Traverse(root) == Status::NotCovered);
        return res;
    }
};
