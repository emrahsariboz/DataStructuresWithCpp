#include "queue.h"
Queue::Queue(){

}
Queue::Queue(int size)
{
    this->size = size;
    this->rear = 0;
    this->front = 0;
    this->Q = new Node*[size];
}


void Queue::createTree(Queue *q, int size){
    q->size = size;
    q->front = q->rear = 0;
    q->Q = new Node*[size];
}



void Queue::enqueue(Node *x){
    if (rear+1 % size == front ){
        cout << "Its already full" <<endl;
    }else{
        rear = rear + 1 % size;
        Q[rear] = x;
    }
}
Node * Queue::dequeue(){
    Node* data = NULL;
    if (front == rear){
        cout << "Queue is empty"<<endl;
    }else{
        front = front +1 % size;
        data = Q[front];
    }

    return data;
}


int Queue::isEmpty(Queue  q){
    return q.front == q.rear;
}

