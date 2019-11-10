#include "BinaryTree.h"
#ifndef _BINARYTERR_H
#define _BINARYTERR_H

// !!!The construct function(except default) must write in .cpp file, cannot write this in .h file. 
BinaryTree::BinaryTree(TYPE _d)
{
    nil = new Node;
    __root = new Node;
    __root->parent = nil;
    __root->left = nil;
    __root->right = nil;
    __root->data = _d;
};

BinaryTree::Node* BinaryTree::_getroot()
{
    return __root;
};

int BinaryTree::inorder_walk(Node* _x)
{
    if (_x != nil)
	{
	    inorder_walk(_x->left);
	    std::cout << _x->data << " ";
	    inorder_walk(_x->right);
	}
    return 0;
};

int BinaryTree::Release(Node *_x)
{
    if (_x != nil)
    {
	Release(_x->left);
	Release(_x->right);
	delete _x;
    }
    return 0;
};

//delete _x from the left/right of _x's parent
int BinaryTree::release(Node* _x)
{
    Node* y = nil;
    if (_x != nil)
        y = _x->parent;
    if (y != nil)
    {
        if (_x == y->left)
	    y->left = nil;
	else
	    y->right = nil;
    }
    Release(_x);
    return 0;
};

int BinaryTree::release()
{
    Release(__root);
    __root = nil ;
    return 0;
};

int BinaryTree::reinit(Node* _x)
{
    __root = _x;
    return 0;
};

int BinaryTree::setRoot(Node* _x)
{
    __root = _x;
    return 0;
};

int BinaryTree::height(Node* _x)
{
    if (_x == nil)
	return 0;
    else
	return std::max(height(_x->left), height(_x->right)) + 1;
};

int BinaryTree::height()
{
    return height(__root);
}
#else
//Do nothing
#endif
