#include "BinarySearchTree.h"
#ifndef _BINARYSEARCHTREE_H
#define _BINARYSEARCHTREE_H

BSTNode* BinarySearchTree::search(Node* _x, TYPE k)
{ 
    while(_x != nil && _x->data != k)
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
	return NULL;	
    while (_x->left != nil)
	_x = _x ->left;	
    return _x;
};

BSTNode *BinarySearchTree::max(Node* _x)
{
    if (_x == nil)
	return NULL;
    while (_x->right != nil)
	_x = _x -> right;
    return _x;
};

TYPE BinarySearchTree::max_value(Node* _x)
{
    if (_x == nil)
	{
	    std::cerr << "Null has no maximum value." << std::endl;
	    return -1;
	}
    return (max(_x)->data);
};

TYPE BinarySearchTree::min_value(Node* _x)
{
    if (_x == nil)
	{
	    std::cerr << "Null has no minimum value." << std::endl;
	    return -1;
	}
    return (min(_x)->data);
};

TYPE BinarySearchTree::max_value()
{
    const Node* x = __root; 
    if (x == nil)
	{
	    std::cerr << "Null has no maximum value." << std::endl;
	    return -1;
	}
    while (x->right != nil)
	x = x->right;
    return x->data;
};

TYPE BinarySearchTree::min_value()
{
    const Node* x = __root; 
    if (x == nil)
	{
	    std::cerr << "Null has no maximum value." << std::endl;
	    return -1;
	}
    while (x->left != nil)
	x = x->left;
    return x->data;
};

BSTNode *BinarySearchTree::max()
{
    return max(__root);
}

BSTNode *BinarySearchTree::successor(Node* _x)
{
    if (_x == nil)
	{
	    std::cout << "Error, null has no successor." << std::endl;
	    std::exit(-1);
	}
    if (_x -> right != nil)
	return min(_x -> right);
	
    Node* y = _x->parent;
    while (y != nil && _x == y->right)
	{
	    _x = y;
	    y = y->parent;
	}
    if (y == nil)
	return NULL;
    else
	return y;
	
 };

TYPE BinarySearchTree::succeeding_value(Node *_x)
{
    if (_x == nil)
	{
	    std::cout << "Error, null has no successor." << std::endl;
	    std::exit(-1);
	}

    if (_x->right != nil)
	return min_value(_x -> right);
	
    Node* y = _x->parent;
    while (y != nil && _x == y->right)
	{
	    _x = y;
	    y = y->parent;
	}
    if (y != nil)
	return y->data;
    else
	{
	    std::cerr << "Maximum node has no successor."
		  << std::endl;
	    //As a signal.
	    return MIN;
	}
};

BSTNode *BinarySearchTree::predecessor(Node *_x)
{
    if (_x == nil)
	{
	    std::cout << "Error, null has no successor." << std::endl;
	    exit(-1);
	}
     if (_x->left != nil)
	return max(_x->left);
    
    Node* y = _x->parent;
    while (y != nil && _x == y->left)
	{
	    _x = y;
	    y = y->parent;
	}

    if (y != nil)
	return y;
    else
	return NULL;
};

TYPE BinarySearchTree::preceding_value(Node *_x)
{
    if (_x == nil)
	{
	    std::cout << "Error, null has no successor." << std::endl;
	    std::exit(-1);
	}
    if (_x->left != nil)
	return max_value(_x->left);
    
    Node* y = _x->parent;
    while (y != nil && _x == y->left)
	{
	    _x = y;
	    y = y->parent;
	}
    if (y != nil)
	return y->data;
    else
	{
	    std::cerr << "Minimum node has no predecessor."
		      << std::endl;
	    return MIN;
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
