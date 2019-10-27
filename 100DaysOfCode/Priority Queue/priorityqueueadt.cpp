#include "priorityqueueadt.h"

PriorityQueueAdt::PriorityQueueAdt()
{

}

PriorityQueueAdt::PriorityQueueAdt(int cap)
{
    capacity = cap;
    A = new int[capacity];
    size = 0;
    rear = -1;
}

void PriorityQueueAdt::enqueue(int i){
    if(capacity == size){
        cout<<"The queue is full" << endl;
        cout<<"I couln't add " << i << endl;
    }else{
        rear += 1;
        A[rear] = i;
        size++;
    }
}

void PriorityQueueAdt::printQueue(){
    for(int i=0; i<size; i++){
        cout<<A[i] <<" ";
    }
    cout << endl;
}

void PriorityQueueAdt::swap(int *i, int *j){
    int temp = *i;
    *i = *j;
    *j = temp;
}

int PriorityQueueAdt::dequeue(){
    int lowestIndex= INT_MAX;
    int returnVal = 0;
    for(int i=0; i<size; i++){
        if(A[i] < lowestIndex){
            lowestIndex= i;
        }
    }

    returnVal = A[lowestIndex];
    swap(&A[lowestIndex], &A[size-1]);

    size--;

    return returnVal;
}
