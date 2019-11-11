#include "RedBlackTree.h"

int RedBlackTree::insert(Node* _x)
{
    BinarySearchTree::insert(_x);
    _x->color = RED;
    if (_x->parent->color == BLACK)
	return 0;
    
    while (_x->parent != nil && _x->color == RED)
    {
	if (_x->parent = _x->parent->parent->left)
	{
	    Node* y = _x->parent->parent->right;
	    if (y->color == RED)
	    {
		_x->parent->color = y->color = BLACK;
		_x = _x->parent->parent;
		_x->color = RED;
	    }
	    else 
	    {
		if (_x == _x->parent->right)
		{
		    transplant(_x->parent, _x);
		    _x->left->parent = _x->parent;
		    _x->parent->right = _x->left;
		    _x->left = _x->parent;
		    _x->parent->parent = _x; 
		}
		else
		{
		    y = _x->parent;
		    transplant(y->parent, y);
		    y->parent->left = y->right;
		    y->parent->left->parent = y->parent;
		    y->right = y->parent;
		    y->right->parent = y;
		    y->color = BLACK;
		    y->right->color = RED;
		}
				
	    }
	}
	    
	if (_x->parent = _x->parent->parent->right)
	{
	    Node* y = _x->parent->parent->left;
	    if (y->color == RED)
	    {
		_x->parent->color = y->color = BLACK;
		_x = _x->parent->parent;
		_x->color = RED;
	    }
	    else 
	    {
		if (_x == _x->parent->left)
		{
		    transplant(_x->parent, _x);
		    _x->parent->left = _x->right;
		    _x->parent->left->parent = _x->parent;
		    _x->right = _x->parent;
		    _x->right->parent = _x; 
		}
		else
		{
		    y = _x->parent;
		    transplant(y->parent, y);
		    y->parent->right = y->left;
		    y->parent->right->parent = y->parent;
		    y->left = y->parent;
		    y->left->parent = y;
		    y->color = BLACK;
		    y->left->color = RED;
		}
	    }
	}

    }
    return 0;  
};
