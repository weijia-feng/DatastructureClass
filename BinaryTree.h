#include <limits>
#include <queue>
#include "BinaryTreeNode.h"

#ifndef __BinaryTree_h
#define __BinaryTree_h

#define MIN (std::numeric_limits<TYPE>::min())

class BinaryTree
{
 public:
    typedef BinaryTreeNode Node;
    //const Node* _getroot();
    
 protected:
    Node *root;
    Node *nil;

 public:    
    BinaryTree()
	{
	    nil = new Node;
	    nil->color = BLACK;
	    root = nil;
	};
    
    BinaryTree(TYPE _d);

    Node* _getroot();
    const Node* _getroot() const;
    int inorder_walk();
    int inorder_walk(Node *_x);
    int reinit(Node* _x); 
    int Release(Node* _x);
    int release(Node* _x);
    int release();
    int setRoot(Node* _x);
    int height(Node* _x);
    int height();

}; 
#else
//Do nothing
#endif

