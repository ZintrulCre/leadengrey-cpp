//
// Created by ZintrulCre on 2020-09-12.
//

#ifndef LEADGREY_BASE_DATASTRUCTURE_H
#define LEADGREY_BASE_DATASTRUCTURE_H

namespace leadgrey
{
    
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

}

#endif