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
    return 0;
};

int BinaryTree::Release(Node *_x)
{
    if (_x != NULL)
    {
	Release(_x->left);
	Release(_x->right);
	delete _x;
    }
    return 0;
};

int BinaryTree::release(Node* _x)
{
    Node* y = NULL;
    if (_x != NULL)
        y = _x->parent;
    if (y != NULL)
    {
        if (_x == y->left)
	    y->left = NULL;
	else
	    y->right = NULL;
    }
    Release(_x);
    return 0;
};

int BinaryTree::release()
{
    Release(__root);
    __root = NULL;
    return 0;
};

int BinaryTree::reinit(Node* _x)
{
    __root = _x;
    return 0;
};

#endif
