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

int PriorityQueueAdt::dequeueSwapMethod(){
    int lowestValue = INT_MAX;
    int lowestIndex= 0;
    int returnVal = 0;
    for(int i=0; i<size; i++){
        if(A[i] < lowestValue){
            lowestIndex= i;
            lowestValue = A[i];
        }
    }

    returnVal = A[lowestIndex];
    swap(&A[lowestIndex], &A[size-1]);

    size--;

    return returnVal;
}


int PriorityQueueAdt::dequeueShiftMethod(){
    int lowestValue = INT_MAX;
    int lowestIndex= 0;
    int returnVal = 0;

    if(size == 0){
        cout<<"There is nothing to dequeue"<<endl;
        return -1;
    }
    if(size == 1){
        return A[size];
    }

    for(int i=0; i<size; i++){
        if(A[i] < lowestValue){
            lowestValue=A[i];
            lowestIndex = i;
        }
    }
    size--;

    returnVal = A[lowestIndex];

    for(int i=lowestIndex; i<size-1; i++){
        A[i] = A[i+1];
    }

    return returnVal;
}
