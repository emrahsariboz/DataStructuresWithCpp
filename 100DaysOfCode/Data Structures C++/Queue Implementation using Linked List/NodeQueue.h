#ifndef QUEUE_H
#define QUEUE_H

#include <iostream>

using namespace std;


class NodeQueue{
public:
    NodeQueue *next;
    int data;
    NodeQueue *front = NULL;
    NodeQueue *rear = NULL;

    NodeQueue();
    void enqueue(int x);
    int dequeue();
    int peek();
    bool isEmpty();
};


#endif // QUEUE_H
