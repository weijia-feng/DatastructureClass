#include "BinarySearchTree.h"
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
    std::cout << "Maximum of B:" << B.max() << std::endl;
    std::cout << "Minimum of B:" << B.min() << std::endl;
    
    BSTNode* r = B._getroot();
    r = r -> left -> left;
    B.del(r);
    B.inorder_walk(B._getroot());
    
    B.release(B._getroot());
    B.inorder_walk(r);
	
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
    return 0;
};

#endif
