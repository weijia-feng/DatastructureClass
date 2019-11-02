#include "BinaryTree.h"

class BinarySearchTree : public BinaryTree
{
public:
    //BinarySearchTree();
    //BinarySearchTree(TYPE _d);
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
    int insert(TYPE _d);
};

typedef BinaryTree::Node BTNode;
typedef BinarySearchTree::Node BSTNode;
//BinarySearchTree::BinarySearchTree(TYPE _d):BinaryTree(_d){};
