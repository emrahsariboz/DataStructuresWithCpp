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

class Queue{
private:
    int size;
    int front;
    int rear;
    Node** Q;  // [Node*]*: Pointer to [Pointer to Node]
public:
    Queue(int size);
    ~Queue();
    bool isFull();
    bool isEmpty();
    void enqueue(Node* x);
    Node* dequeue();
};

#endif // QUEUE_H
