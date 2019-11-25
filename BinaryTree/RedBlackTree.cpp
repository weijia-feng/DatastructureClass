#include "RedBlackTree.h"

int RedBlackTree::inorder_walk(Node* _x)
{
    if (_x != nil)
    {
	inorder_walk(_x->left);
	std::cout << _x->data << " ";
	if (_x->color == 0)
	    std::cout << "B ";
	else
	    std::cout << "R ";	
	inorder_walk(_x->right);
    }
    return 0;
};

int RedBlackTree::inorder_walk()
{
    inorder_walk(root);
    std::cout << "root " << root->data << std::endl;
    return 0;
};

int RedBlackTree::insert(Node* _x)
{
    BinarySearchTree::insert(_x);
    _x->color = RED; //Initialize the color of new node to red.
    
    while (_x->parent != nil && _x->color == RED)
    {
	if (_x->parent->color == BLACK)
	return 0;

	if (_x->parent == _x->parent->parent->left)
	{
	    Node* y = _x->parent->parent->right;
	    if (y->color == RED) //x->parent's color is red now.
	    {
		_x->parent->color = y->color = BLACK; 
		_x = _x->parent->parent;
		_x->color = RED;
	    }
	    else //if x.uncle's color is black, then do this. 
	    {
		if (_x == _x->parent->right)
		{
		    _x = _x->parent;
		    leftRotate(_x);
		}
		_x->parent->color = BLACK;
		_x->parent->parent->color = RED;
		rightRotate(_x->parent->parent);
	    }
	}
	    
	else //_x->parent is the right son of its father.
	{
	    Node* y = _x->parent->parent->left;
	    if (y->color == RED)
	    {
		_x->parent->color = y->color = BLACK;
		_x = _x->parent->parent;
		_x->color = RED;
	    }
	    else //x.uncle's color is black
	    {
		if (_x == _x->parent->left)
		{
		    _x = _x->parent; //must change _x to its parent.
		    rightRotate(_x);
		} //case3 follows after the operation of case2
		_x->parent->color = BLACK;
		_x->parent->parent->color = RED;
		leftRotate(_x->parent->parent);
	    }
	}
	root->color = BLACK;
    }
    return 0;  
};

int RedBlackTree::insert(TYPE _d)
{
    Node* x = new Node(_d);
    insert(x);
    return 0;
};
