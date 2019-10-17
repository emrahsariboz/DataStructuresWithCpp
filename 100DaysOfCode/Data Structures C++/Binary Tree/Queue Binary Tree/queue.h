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

class Queue
{
public:
    int size;
    int front, rear;
    Node **Q;
    Queue();
    Queue(int size);
    void createTree(Queue *q, int size);
    void enqueue(Node *x);
    int isEmpty(Queue q);
    Node* dequeue();
    void Display(Queue q);

};

#endif // QUEUE_H
