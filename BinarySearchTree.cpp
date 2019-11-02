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
    BSTNode* r = _getroot();
    if (r != NULL)
	_r = min(_r);
    return _r;	
}
 
BSTNode *BinarySearchTree::min(Node* _x)
{
    if (_x != NULL)
	{
	     while (_x->left != NULL)
	     _x = _x ->left;
	}
    return _x;
};

BSTNode *BinarySearchTree::max(Node* _x)
{
    while (_x->right != NULL)
	_x = _x -> right;
    return _x;
};

BSTNode *BinarySearchTree::max()
{
    BSTNode* r = _getroot();
    if (r != NULL)
	_r = max(_r);
    return _r;	
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

int BinarySearchTree::insert(Node* _r, Node* _new)
{
    Node* y = NULL;
    Node* x = new Node;
    x -> data = _new -> data;
    if (_r == NULL)
	reinit(_new);
    else
	{
	    while(_r != NULL)
		{
		    y = _r;
		    if(_r -> data > x -> data)
			_r = _r -> left;
		    else
			_r = _r -> right;
		}
    
	    if (y->data > x -> data)
		y -> left = x;
	    else
		y -> right = x;
	    x -> parent = y;
	}
    return 0;
};

int BinarySearchTree::insert(TYPE _d)
{
    Node* x = new Node;
    x -> data = _d;
    Node* y = _getroot();
    
    if (y == NULL)
	reinit(x);
    else
	insert(y, x);
    
    return 0;
};

int BinarySearchTree::transplant(Node* _o, Node* _n)
{
    if (_o == NULL)
	{
	    std::cerr << "Error! Can not transplant to a NULL."
		      << std::endl;
	    std::exit(-1);
	}
    if (_o -> parent == NULL)
	reinit(_n);
    else if(_o == _o ->parent->left)
	_o -> parent -> left = _n;
    else
	_o -> parent -> right = _n;
    if(_n != NULL)
	_n -> parent = _o -> parent;
    return 0;
};

int BinarySearchTree::del(Node* _x)
{
    if (_x -> left == NULL)
	transplant(_x, _x -> right);
    else if (_x -> right == NULL)
	transplant(_x, _x -> left);
    else
	{
	    Node* y = min(_x -> right);
	    
	    if (y->parent != _x)
		{
		    transplant(y, y->right);
		    y->right->parent = y;
		}
	    transplant(_x, y);
	    y -> left = _x -> left;
	    y -> left -> parent = y;
	}
	
    delete _x;
    return 0;
};

#endif
