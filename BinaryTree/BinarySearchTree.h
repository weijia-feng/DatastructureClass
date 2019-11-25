#include "BinaryTree.h"

class BinarySearchTree : public BinaryTree
{
public:
    //BinarySearchTree();
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

    TYPE insert(TYPE _d);
    BinarySearchTree(TYPE _d) : BinaryTree(_d){};
    BinarySearchTree(){};
};

typedef BinaryTree::Node BTNode;
typedef BinarySearchTree::Node BSTNode;
//BinarySearchTree::BinarySearchTree(TYPE _d):BinaryTree(_d){};
