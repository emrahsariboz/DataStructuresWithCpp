#include "queue.h"
Queue::Queue()
{
    this->size = 10;
    this->rear = 0;
    this->front=0;
    this->Q = new int[size];
}

Queue::Queue(int size)
{
    this->size = size;
    this->rear = 0;
    this->front = 0;
    this->Q = new int[size];
}

void Queue::enqueue(int data){
    if (rear+1 % size == front ){
        cout << "Its already full" <<endl;
    }else{
        rear = rear + 1 % size;
        Q[rear] = data;
    }
}
int Queue::dequeue(){
    int data = -1;
    if (front == rear){
        cout << "Queue is empty"<<endl;
    }else{
        front = front +1 % size;
        data = Q[front];
    }

    return data;
}


void Queue::Display(Queue q){
    int i=front+1;
    do{
        cout<<Q[i]<<" ";
        i = (i+1)%size;

    }while(i != (rear+1) %size );
    cout <<endl;
}


