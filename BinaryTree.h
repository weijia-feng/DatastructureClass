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

    //const Node* _getroot();
    Node* _getroot();
    BinaryTree()
	{
	    nil = new Node;
	    __root = nil;
	};
    BinaryTree(TYPE _d);
    int inorder_walk();
    int inorder_walk(Node *_x);
    int reinit(Node* _x); 
    int Release(Node* _x);
    int release(Node* _x);
    int release();
    int setRoot(Node* _x);
    int height(Node* _x);
    int height();
    
public:
    Node *__root;
    Node *nil;
}; 


