#include "BinaryTree.h"
#ifndef _BINARYTERR_H
#define _BINARYTERR_H

// !!!The construct function must write in .cpp file, cannot write this in .h file. 
BinaryTree::BinaryTree(TYPE _d)
{
    Node *r = new Node;
    r->parent = NULL;
    r->left = NULL;
    r->right = NULL;
    r->data = _d;
};

BinaryTree::Node* BinaryTree::_getroot()
{
    return __root;
};

int BinaryTree::inorder_walk(Node* _x)
{
    if (_x != NULL)
	{
	    inorder_walk(_x->left);
	    std::cout << _x->data << " ";
	    inorder_walk(_x->right);
	    
	}
    return 0;// Means that the function has ended.this color makes me fall in love with writing explationation, haha.
};

int BinaryTree::reinit(Node* _x)
{
    __root = _x;
    return 0;
};

#endif
