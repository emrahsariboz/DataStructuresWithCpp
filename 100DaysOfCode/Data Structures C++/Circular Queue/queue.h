#ifndef QUEUE_H
#define QUEUE_H
#include <iostream>
using namespace std;

class Queue
{
public:
    int size;
    int front, rear;
    int A[];

    Queue(int size);
    bool isEmpty();
    void enqueue(int n);
    int dequeue();
    int Peek();
    void Display();
    int sizeQ();
};


#endif // QUEUE_H
