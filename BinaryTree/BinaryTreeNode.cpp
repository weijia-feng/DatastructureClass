#include "BinaryTreeNode.h"

BinaryTreeNode::BinaryTreeNode(const BinaryTreeNode* _t)
{
    //operation of copy
    if (_t == NULL)
	{
	    std::cerr << "Cannot copy a null" << std::endl;
	    std::exit(-1);
	}
    data = _t->data;
    parent = left = right = NULL;
};

BinaryTreeNode::BinaryTreeNode(BinaryTreeNode* _t)
{
    if (_t == NULL)
	{
	    std::cerr << "Cannot copy a null" << std::endl;
	    std::exit(-1);
	}
    data = _t->data;
    parent = left = right = NULL;
};

BinaryTreeNode::BinaryTreeNode(TYPE _d)
{
    data = _d;
    parent = left = right = NULL;
};

BinaryTreeNode::~BinaryTreeNode()
{
    parent = left = right = NULL;
};
