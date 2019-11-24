#ifndef __BinaryTreeNode_h
#define __BinaryTreeNode_h

#include <iostream>
#include <cstdlib>

#define BLACK false
#define RED true

typedef int TYPE;//used to have error here, forgot simicolon. 

class BinaryTreeNode
{
public:
    BinaryTreeNode* parent;
    BinaryTreeNode* left;
    BinaryTreeNode* right;
    TYPE data;
    int depth;
    int pos;
    bool color = RED;

    BinaryTreeNode(){};
    BinaryTreeNode(const BinaryTreeNode* _t);
    BinaryTreeNode(BinaryTreeNode* _t);
    BinaryTreeNode(TYPE _d);
    ~BinaryTreeNode();
};
#else
//Do nothing.
#endif
