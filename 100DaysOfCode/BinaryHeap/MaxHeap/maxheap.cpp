#include "maxheap.h"

MaxHeap::MaxHeap(int inputArr[], int cap)
{
    capacity = cap;
    A = new int[capacity];
    for(int i =0; i<cap; i++){
         A[i] = inputArr[i] ;
    }
    size = capacity;

    cout<<"Size of the array"<<size<<endl;

}

void MaxHeap::swap(int *i, int *j){
    int temp = *i;
    *i = *j;
    *j = temp;
}

void MaxHeap::heapify(int lastNode){
        int l = 2 * lastNode + 1;
        int r = 2 * lastNode + 2;
        int largest=lastNode;

            if(l<size && A[l] > A[largest])
             largest = l;

            if(r<size && A[r] > A[largest])
            largest = r;

            if(A[largest] != A[lastNode]){
            swap(&A[largest], &A[lastNode]);

            heapify(largest);
            }
    }

int MaxHeap::dequeue(int n){
    int startIndex = (n/2) -1 ;
    for(int i=startIndex; i>=0; i--){
          heapify(i);
       }
   }


void MaxHeap::printHeap(){
    int i = 0;
    for(i=0; i<size; i++){
        cout<<A[i]<< " ";
    }
}
