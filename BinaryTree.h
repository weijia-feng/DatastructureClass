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
    BinaryTree(){__root = NULL;};
    BinaryTree(TYPE _d);
    int inorder_walk();
    int inorder_walk(Node *_x);
    int reinit(Node* _x); 

private:
    Node *__root;
}; 


