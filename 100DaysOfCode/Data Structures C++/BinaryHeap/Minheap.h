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
    Minheap(int A[], int cap);
    void MinHeap(int);
    int parent(int i);
    int left(int i);
    int right(int i);
    int extractMin();
    void insertKey(int i);
    void swap(int *x, int *y);
    int getMin();
    void Heapify(int );
    void Heapify(int A[], int n);
    void createHeapFromGivenArray(int A[], int n);
    void printHeap();


};

#endif // BINARYHEAPADT_H
