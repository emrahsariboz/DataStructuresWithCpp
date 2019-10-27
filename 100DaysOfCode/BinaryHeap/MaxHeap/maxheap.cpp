#include "maxheap.h"

MaxHeap::MaxHeap(int inputArr[], int cap)
{
    capacity = cap;
    A = new int[capacity];
    for(int i =0; i<cap; i++){
        inputArr[i] = A[i];
    }
    size = capacity;

}

void MaxHeap::swap(int *i, int *j){
    int temp = *i;
    *i = *j;
    *j = temp;
}

void MaxHeap::heapify(int lastNode){
    lastNode = lastNode / 2 - 1;
    int startIndex = lastNode;
    int largest=lastNode;
    for (int i=startIndex ; i>=0; i--) {
            int l = 2 * lastNode + 1;
            int r = 2 * lastNode + 2;
                largest = l;
            if(r<size && A[r] > A[i])
                largest = r;

            if(l<size && A[l] > A[i])
                largest = l;


            if(A[largest] != A[lastNode]){
                cout<<"inside"<<endl;
                swap(&A[largest], &A[lastNode]);
                heapify(largest);
            }
    }


}

void MaxHeap::printHeap(){
    for(int i=0; i<size; i++){
        cout<<A[i]<<endl;
    }
}
