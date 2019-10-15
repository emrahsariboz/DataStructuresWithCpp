#include "NodeQueue.h"


NodeQueue::NodeQueue()
{
    NodeQueue *next;
    int data;
    NodeQueue *front = NULL;
    NodeQueue *rear = NULL;
}



void NodeQueue::enqueue(int value){
       NodeQueue *temp;
       temp = new NodeQueue;
       temp->data = value;
       temp->next = NULL;

       if(front == NULL && rear == NULL){
           front = rear = temp;
       }

       rear->next = temp;
       rear = temp;
}

int NodeQueue::dequeue(){
    NodeQueue *temp = front;
     int data = 0;
    if(front == NULL)
        return -1;
    if(front == rear && front->data == NULL){
        front = rear = NULL;
    }else{
        data  = front->data;
        front = front->next;
    }
    delete temp;
    return data;
}

int NodeQueue::peek(){
    return front->data;
}

bool NodeQueue::isEmpty(){
    if(front == rear){
        return true;
    }else{
        return false;
    }
}
