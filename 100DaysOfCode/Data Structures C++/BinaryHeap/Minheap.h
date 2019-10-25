#ifndef BINARYHEAPADT_H
#define BINARYHEAPADT_H
#include <iostream>

using namespace std;

class Minheap
{
public:
    int capacity;
    int heap_size;
    int *arr;
    Minheap(int cap);
    void MinHeap(int);
    int parent(int i);
    int left(int i);
    int right(int i);
    int extractMin();
    void insertKey(int i);
    int deleteKey(int i);
    void swap(int *x, int *y);
    int getMin();
    void MinHeapify(int );


};

#endif // BINARYHEAPADT_H
