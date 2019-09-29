#include <iostream>
#include <bits/stdc++.h>
using namespace std;



struct Node{
    int data;
    Node *next;
};

Node *first;

void Create(int arr[], int s){

    int i;
    Node *last, *temp;
    int sum=0;
    first = new Node;

    first->data = arr[0];

    first->next = NULL;
    last=first;

    for(i=1; i<s; i++){
        temp = new Node;
        temp->data = arr[i];
        temp->next = NULL;
        last->next = temp;
        last = temp;
    }



}

void Display(Node *p){

    while (p != NULL) {
        cout << p->data <<" ";
        p = p->next;
    }
}

void rDisplay(Node *p){
    if(p!=NULL){

        rDisplay(p->next);
        cout << p->data << " " ;
    }
}

int iterativeCount(Node *p){
    int size = 0;
    while(p!=NULL){
        size++;
        p= p->next;
    }

    return size;
}

int recursiveCount(Node *p){
    if (p==NULL)
        return 0;


    return recursiveCount(p->next) + 1;

}


int iterativeAdd(Node *p){
    int total = 0;
    while (p) {
        total += p->data;
        p = p->next;
    }

    return total;
}


int recursiveAdd(Node *p){
    if(p ==NULL){
        return 0;
    }else{
         return recursiveAdd(p->next) + p->data;
    }
}

int iterativeMaxF(Node *p){
    int max = 0;

    while (p) {
        if(p->data > max){
            max = p->data;
        }
        p= p->next;
    }
    return max;
}

int recursiveMaxF(Node *p){
     int max = INT_MIN;

     if(p==NULL){
         return 0;
     }
     max = recursiveMaxF(p->next);
     return max>p->data ? max : p->data;
}

//Linear search. It also moves the found key
//to the head of the Linked List
Node* iterativeSearch(Node *p, int key){
    Node *q = NULL;
    while (p) {
        if( key == p->data){
            q->next = p->next;
            p->next = first;
            first = p;

            return p;
        }else{
            q=p;
            p = p->next;
        }

    }

    return NULL;
}
Node* recursiveSearch(Node *p, int key){
    if (p == 0)
          return 0;
    else
        if(p->data == key)
              return p;

            return  recursiveSearch(p->next, key);
}


int main(){

    int arr[] = {1,2,3,4,5, 9, 11};

    //Creating Linked List from Array
    Create(arr,7);

    Display(first);

    cout<<endl;


    Node *temp;

    temp = iterativeSearch(first, 11);

    if(temp){
        cout << "Data is found, key is " << temp->data;
    }else{
        cout << "key not found " << endl;
    }

    cout << endl;

    Display(first);

    //rDisplay(first);

    cout << "\nSize of LL is : " << iterativeCount(first)<<endl;
    cout << "Size of Linked List using recursion is : " << recursiveCount(first) <<endl;
    cout << "The total of LL using iterative function is : " << iterativeAdd(first) <<endl;
    cout << "The total of LL using recuesive function is : " << recursiveAdd(first)<<endl;
    cout << "The max of the LL using iterative function is: " << iterativeMaxF(first)<<endl;
    cout << "The max of the LL using recursive function is: " << recursiveMaxF(first)<<endl;
    cout<<endl;

    return 0;
}
