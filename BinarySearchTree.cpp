#include "BinarySearchTree.h"
#ifndef _BINARYSEARCHTREE_H
#define _BINARYSEARCHTREE_H

BSTNode* BinarySearchTree::search(Node* _x, TYPE k)
{ 
    while(_x != NULL && _x->data != k)
	{
	    if (k < _x->data)
		_x = _x ->left;
	    else
		_x = _x ->right;
      	}
    return _x;
};

BSTNode *BinarySearchTree::min()
{
    return min(__root);	
}
 
BSTNode *BinarySearchTree::min(Node* _x)
{
    if (_x == nil)
	return _x;	
    while (_x->left != nil)
	_x = _x ->left;	
    return _x;
};

BSTNode *BinarySearchTree::max(Node* _x)
{
    if (_x == nil)
	return _x;
    while (_x->right != nil)
	_x = _x -> right;
    return _x;
};

BSTNode *BinarySearchTree::max()
{
    return max(__root);
}

BSTNode *BinarySearchTree::successor(Node* _x)
{
    if (_x == NULL)
	{
	    std::cout << "Error, null has no successor." << std::endl;
	    exit(-1);
	}
    if (_x -> right != NULL)
	return min(_x -> right);
    else
	{
	    Node* y = _x->parent;
	    while (y != NULL && _x == y->right)
		{
		    _x = y;
		    y = y->parent;
		}
	    return y;
	}
};

BSTNode *BinarySearchTree::predecessor(Node *_x)
{
    if (_x == NULL)
	{
	    std::cout << "Error, null has no successor." << std::endl;
	    exit(-1);
	}
    if (_x -> left != NULL)
	return max(_x -> left);
    else
	{
	    Node* y = _x -> parent;
	    while (y != NULL && _x == y->left)
		{
		    _x = y;
		    y = y->parent;
		}
	    return y;
	}
};

int BinarySearchTree::insert(Node* _n)
{
    Node* y = nil;
    Node* x = __root;
    _n->parent = nil;
    _n->left = nil;
    _n->right = nil;
    
    if (x == nil)
	{
	    __root = _n;
	    return 0;
	}
    
    while(x != nil)
	{
	    y = x;
	    if(x->data > _n->data)
		x = x->left;
	    else
		x = x->right;
	}
    
    if (y->data > _n->data)
	y->left = _n;
    else
	y->right = _n;
    
    _n -> parent = y;
    return 0;
};

int BinarySearchTree::insert(TYPE _d)
{
    Node* x = new Node;
    x -> data = _d;
    insert(x);
    
    return 0;
};

int BinarySearchTree::transplant(Node* _o, Node* _n)
{
    if (_o == nil)
	{
	    std::cerr << "Error! Can not transplant to a NULL."
		      << std::endl;
	    std::exit(-1);
	}
    if (_o->parent == nil)
	__root = _n;
    else if(_o == _o->parent->left)
	_o -> parent->left = _n;
    else
	_o -> parent->right = _n;
    if(_n != nil )
	_n->parent = _o->parent;
    return 0;
};

int BinarySearchTree::del(Node* _x)
{
    if (_x == nil)
	{
	    std::cerr << "Cannot delete a nil." << std::endl;	    
	    std::exit(-1);
	}	    
	
    if (_x -> left == nil)
	transplant(_x, _x -> right);
    else if (_x->right == nil)
	transplant(_x, _x -> left);
    else
	{
	    Node* y = min(_x -> right);
	    
	    if (y->parent != _x)
		{
		    transplant(y, y->right);
		    _x->right->parent = y;
		    y->right = _x->right;
		}
	    transplant(_x, y);
	    y -> left = _x -> left;
	    y -> left -> parent = y;
	}
	
    delete _x;
    return 0;
};

#endif
