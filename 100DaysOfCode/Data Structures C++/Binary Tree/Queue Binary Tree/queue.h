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
    int *Q;
    Queue();
    Queue(int size);
    void Create(Queue *q, int data);
    void enqueue(int data);
    int dequeue();

};

#endif // QUEUE_H
