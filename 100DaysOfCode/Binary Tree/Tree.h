#ifndef QUEUE_H
#define QUEUE_H
#include <iostream>
using namespace std;


class Node{

public:
    Node* lchild;
    int data;
    Node* rchild;
};

using namespace std;

class Tree
{


public:
    Node *root = NULL;
    int size;
    int front, rear;
    Node **Q;
    Tree();
    Tree(int size);
    void createTree();
    void enqueue(Node *x);
    int isEmpty();
    Node* dequeue();
    void Display(Tree q);
    void LevelOrder(Node *root);
    int Height(Node *root);
    void preorder(Node *p);
    void inOrder(Node *p);
    void postOrder(Node *p);
};

#endif // QUEUE_H
