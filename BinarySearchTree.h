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
    TYPE min_value();
    TYPE max_value();    
    TYPE min_value(Node* _x);
    TYPE max_value(Node* _x);
    Node* successor(Node* _x);
    TYPE succeeding_value(Node* _x);
    Node* predecessor(Node* _x);
    TYPE preceding_value(Node* _x);    
    TYPE insert(Node* _n);
    TYPE del(Node *_x);
    TYPE transplant(Node* _o, Node* _n);
    TYPE insert(TYPE _d);
};

typedef BinaryTree::Node BTNode;
typedef BinarySearchTree::Node BSTNode;
//BinarySearchTree::BinarySearchTree(TYPE _d):BinaryTree(_d){};
