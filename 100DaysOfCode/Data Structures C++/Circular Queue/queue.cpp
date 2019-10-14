#include "queue.h"

Queue::Queue(int size)
{
    int A[size];
    this->size = size;
    front = rear = -1;

}

bool Queue::isEmpty(){
    if((front == -1)  && (rear == -1))
        return true;
    else
        return false;
}

void Queue::enqueue(int n){
    if (isEmpty())
        rear = front = 0;
    else if ((rear + 1)%size == front) {
        cout <<"Its already full!"<<endl;
    }
    else{
        rear = (rear+1) % size;
    }
    cout<<"Enqued " << n << endl;
    A[rear]=n;
}


int Queue::dequeue(){
    if(isEmpty()){
        cout << "Its EMPTY!" <<endl;
    }else if (front == rear) {
        front = rear = -1;
    }else{
        front = (front+1)%size;
    }

}

int Queue::Peek(){
    if(isEmpty())
        cout <<"Its empty! There is not any peek!"<<endl;
    else
        return A[front];
}

void Queue::Display(){
    if(isEmpty()){
        cout << "Its empty! Nothing to display"<<endl;
    }else{
        for(int i=0; i<size; i++){
            cout << A[i] << endl;
        }
    }
    cout <<endl;
}

