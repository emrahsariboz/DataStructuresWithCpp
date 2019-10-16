#include "queue.h"
Queue::Queue()
{
    this->size = 10;
    this->rear = -1;
    this->front=-1;
    this->Q = new int[size];


}

Queue::Queue(int size)
{
    this->size = size;
    this->rear = -1;
    this->front = -1;
    this->Q = new int[size];
}

void Queue::Create(Queue *q, int data){
     q->size  = size;
     q->front = q->rear = -1;
     q->Q = new int(size);
}


void Queue::enqueue(int data){
    if (front == size - 1){
        cout << "Its already full" <<endl;
    }else{
        rear++;
        Q[rear] = data;


    }
}

int Queue::dequeue(){
    int data = -1;
    if (front == rear){
        cout << "Queue is empty"<<endl;
    }else{
        front++;
        data = Q[front];
    }

    return data;
}
