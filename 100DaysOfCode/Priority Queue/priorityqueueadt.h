#ifndef PRIORITYQUEUEADT_H
#define PRIORITYQUEUEADT_H
#include <iostream>
using namespace std;

class PriorityQueueAdt
{
public:
    int item;
    int *A;
    int capacity;
    int size;
    int rear;
    PriorityQueueAdt();
    void enqueue(int i);
    int dequeue();
    void swap(int *i, int *j);

    PriorityQueueAdt(int cap);
    void printQueue();

};

#endif // PRIORITYQUEUEADT_H
