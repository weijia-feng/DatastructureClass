#include "BinaryTree.h"
#ifndef _BINARYTERR_H
#define _BINARYTERR_H

// !!!The construct function(except default) must write in .cpp file, cannot write this in .h file. 
BinaryTree::BinaryTree(TYPE _d)
{
    nil = new Node;
    nil->color = BLACK;
    root = new Node;
    root->color = BLACK;
    root->parent = root->left = root->right = nil;
    root->data = _d;
};

BinaryTree::Node* BinaryTree::_getroot()
{
    return root;
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

int BinaryTree::inorder_walk()
{
    inorder_walk(root);
    std::cerr << std::endl;
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
    Release(root);
    root = nil ;
    return 0;
};

int BinaryTree::reinit(Node* _x)
{
    root = _x;
    return 0;
};

int BinaryTree::setRoot(Node* _x)
{
    root = _x;
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
    return height(root);
};

int BinaryTree::rightRotate(Node* _x)
{
    Node* y = _x->left;
    transplant(_x, y);
    _x->left = y->right;
    _x->left->parent = _x;
    y->right = _x;
    _x->parent = y;
    
    return 0;
};

int BinaryTree::transplant(Node* _o, Node* _n)
{
    if (_o == nil)
	{
	    std::cerr << "Error! Can not transplant to a NULL."
		      << std::endl;
	    std::exit(-1);
	}
    if (_o->parent == nil)
	root = _n;
    else if(_o == _o->parent->left)
	_o -> parent->left = _n;
    else
	_o -> parent->right = _n;
    if(_n != nil )
	_n->parent = _o->parent;
    return 0;
};

int BinaryTree::leftRotate(Node* _x)
{
    Node* y = _x->right;
    transplant(_x, y);
    _x->right = y->left;
    _x->right->parent = _x;
    y->left = _x;
    _x->parent = y;

    return 0;
};

#else
//Do nothing
#endif
