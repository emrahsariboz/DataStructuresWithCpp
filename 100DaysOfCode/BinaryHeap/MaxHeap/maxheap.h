#ifndef MAXHEAP_H
#define MAXHEAP_H
#include <iostream>

using namespace std;

class MaxHeap
{
public:
    MaxHeap(int A[], int cap);
    MaxHeap();
    int *A;
    int size, capacity;
    int dequeue();
    void heapify(int lastNode);
    void swap(int *i, int *j);
    void printHeap();



};

#endif // MAXHEAP_H
