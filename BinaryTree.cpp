#include<iostream>
typedef int TYPE;

class BinaryTree
{
public:
    class Node
    {
    public:
	Node* parent;
	Node* left;
	Node* right;
	TYPE data;
	
    };

    const Node* _getroot();
    BinaryTree(){__root = NULL;};
    BinaryTree(TYPE _d);
    int inorder_walk();
    int inorder_walk(Node *_x);
    int reinit(Node* _x); 

private:
    Node *__root;
};


class BinarySearchTree : public BinaryTree
{
public:
    BinaySearchTree(){};
    BinarySearchTree(TYPE _d);
    Node* search(Node* _x, TYPE k);
    Node* min();
    Node* max();
    Node* min(Node* _x);
    Node* max(Node* _x);
    Node* successor(Node* _x);
    Node* predecessor(Node* _x);
    int insert(Node* _r, Node* _x);
    int del(Node *_x);
    int transplant(Node* _o, Node* _n);
};

typedef BinaryTree::Node BTNode;
typedef BinarySearchTree::Node BSTNode;

BinaryTree::BinaryTree(TYPE _d)
{
    Node *r = new Node;
    r->parent = NULL;
    r->left = NULL;
    r->right = NULL;
    r->data = _d;
};

BinarySearchTree::BinarySearchTree(TYPE _d)::BinaryTree(_d){};

const BinaryTree::Node* BinaryTree::_getroot()
{
    return __root;
};

int BinaryTree::inorder_walk(Node* _x)
{
    while (_x != NULL)
	{
	    inorder_walk(_x->left);
	    std::cout << _x->data << " ";
	    inorder_walk(_x->right);
	    
	}
    return 0;// Means that the function has ended.this color makes me fall in love with writing explationation, haha.
};

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

int BinaryTree::reinit(Node* _x)
{
    __root = _x;
    return 0;
};

BSTNode *BinarySearchTree::min(Node* _x)
{
    while (_x->left != NULL)
	_x = _x ->left;
    return _x;
};

BSTNode *BinarySearchTree::max(Node* _x)
{
    while (_x->right != NULL)
	_x = _x -> right;
    return _x;
};

BSTNode *BinarySearchTree::successor(Node* _x)
{
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
    if (_r == NULL)
	reinit(_new);
    else
	while(_r != NULL)
	    {
		if(_r -> data > _new -> data)
		    _r = _r -> left;
		else
		    _r = _r -> right;
		
		y = _r -> parent;
	    }
    
    if (y->data < _new -> data)
	y -> right = _new;
    else
	y -> left = _new;
    
};

int BinarySearchTree::del(Node* _x)
{    
    if (_x -> left == NULL)
	transplant(_x, _x  ->  right);
    else if(_x -> right == NULL)
	transplant(_x, _x -> left);
    else
	{
	    y = min(_x -> right);
	    transplant(y, y -> right);
	    y -> right = _x -> right;
	    _x -> right -> parent = y;
	    transplant(_x, y);
	    y -> left = _x -> left;
	    _x -> left -> parent = y;
	}
    return 0;
};

int BinarySearchTree::transplant(Node* _o, Node* _n)
{
    if (_o == NULL)
	reinit(_n);
    else
	_n -> parent = _o ->parent;
    return 0;
};

int main(int argc, char *argv[])
{
    
    BinaryTree A;
    if (A._getroot() == NULL)
	std::cout << "A is NULL." << std::endl;
    BinaryTree B(2);
    if (B._getroot() == NULL)
	std::cout << "B is NULL." << std::endl;
    BinarySearchTree C(3);
    if (C._getroot() == NULL)
	std::cout << "C is NULL." << std::endl;
    return 0;
};
