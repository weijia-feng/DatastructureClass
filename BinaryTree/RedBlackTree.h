#include "BinarySearchTree.h"

class RedBlackTree : public BinarySearchTree
{
 public:
 RedBlackTree(TYPE _d): BinarySearchTree(_d)
    {
	root->color = BLACK; 
    };
    
    RedBlackTree(){};

    int inorder_walk(Node* _x);
    int inorder_walk();
    int insert(Node* _x);
    int insert(TYPE _d);
    int del(Node* _x);
};
