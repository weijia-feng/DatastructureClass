#include "RedBlackTree.h"
#ifndef _BINARYSEARCHTREE_H
#define _BINARYSEARCHTREE_H

int main(int argc, char *argv[])
{
    BinarySearchTree B;
    B.insert(10);
    B.insert(20);
    B.insert(209);
    B.insert(12);
    B.insert(55);
    B.insert(0);
    B.insert(-1);
    B.insert(6);
    // BSTNode* y;
    // BSTNode* x;
    // y = new BSTNode;
    // x = new BSTNode;
    // y -> data = 6; 
    // B.insert(NULL, y);
    // x -> data = 5;
    // B.insert(y, x);
    // x -> data = 7;
    // B.insert(y, x);
    // x -> data = 2;
    // B.insert(y, x);
    // x -> data = 5;
    // B.insert(y, x);
    // x -> data = 8;
    // B.insert(y, x);
    // x -> data = 7;
    // B.insert(y, x);
    // x -> data = 1;
    // B.insert(y, x);
    // x -> data = 3;
    // B.insert(y, x);
    // x -> data = 4;
    // B.insert(y, x);
    // x -> data = 6;
    // B.insert(y, x);
    // x -> data = 5;
    // B.insert(y, x);
    
    B.inorder_walk(B._getroot());    
    std::cout << "Height of B:" << B.height() << std::endl;
    std::cout << "Maximum of B:" << B.max_value() << std::endl;
    std::cout << "Minimum of B:" << B.min_value() << std::endl;
    BSTNode* r = B._getroot();
    std::cerr << "predecessor of root:"
	      << B.predecessor(r)->data
	      << std::endl;
    std::cerr << "successor of root:" << B.successor(r)->data << std::endl;
    
    r = r->left->left;
    B.del(r);
    B.inorder_walk(B._getroot());
    
    B.release(B._getroot());
	
    //std::cout << B._getroot()->data << std::endl;
    //B.inorder_walk(B._getroot());    
    BinaryTree A;
    
    if (A._getroot() == NULL)
	std::cout << "A is NULL." << std::endl;
    //BinaryTree B(2);
    // if (B._getroot() == NULL)
    //std::cout << "B is NULL." << std::endl;
    // BinarySearchTree C(3);
    //if (C._getroot() == NULL)
    //std::cout << "C is NULL." << std::endl;
    RedBlackTree C ;
    C = RedBlackTree(3);
    C.insert(5);
    C.insert(7);
    C.insert(4);
    C.insert(8);
    C.insert(9);
    
    C.inorder_walk();
    return 0;
};

#endif