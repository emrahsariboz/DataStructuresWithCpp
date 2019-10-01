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
    cout << endl;
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


void insert(Node *p, int index, int x){
    if(index < 0  || index > iterativeCount(p))
        return;

    Node *t = new Node;
    t->data = x;


    if(index ==0 ){
        t->next = first;
        first = t;
    }else {

        for(int i=0; i<index-1 ;i++)
            p = p->next;

        t->next = p->next;
        p->next = t;
    }
}


void insertToSorterList(Node *p, int x){

    Node *t,*q = NULL;

    t=new Node;
    t->data = x;
    t->next = NULL;


    if(first == NULL){
        first = t;
    }else{
        while(p && p->data < x){
            q = p;
            p = p->next;
        }

        if(p == first)
        {
            t->next = first;
            first = t;
        }else
        {
           t->next  = q->next ;
           q->next = t;
        }
    }


}


void deleteNode(Node *p, int index){

    Node *temp = new Node;
    int x=0;
    if(index == 0){
        temp = first;
        first = first->next;
         x = temp->data;
        delete temp;
        cout<<x << " : is deleted " << endl;
    }else{
        Node *q = new Node;
        q= first;

        for(int i=0; i<index; i++){
            q=p;
            p = p->next;
        }
        q->next = p->next;
        x = p->data;
        delete p;
    }

    cout << x << " : is deleted" << endl;

}

bool sorted(Node *p){
    int x = INT_MIN;
    while (p) {
        if(p->data < x)
            return false;

        x = p->data;
        p = p->next;

    }

    return true;
}


void removeDuplicates(Node *p){
    p = first;
    Node *q = first->next;


    while (q != NULL) {

        if(p->data != q->data){
            p = q;
            q = q->next;
        }else{
            p->next = q->next;
            delete q;
            q = p->next;
        }

    }

}

void reverseLinkedListUsingArray(Node *p){
    int *A = new int[5];
    int i =0;
    Node *q = first;
    while (q) {
        A[i] = q->data;
        q = q->next;
        i++;
    }

    q = p;
    i--;
    while(q){
        q->data = A[i];
        q= q->next;
        i--;
    }
}

void reverseLinkedListUsingTwoPointer(Node *p){
    Node *q = NULL, *r = NULL;

    while(p){
        r = q;
        q = p;
        p = p->next;
        q->next = r;
    }

    first=q;
}

void recursiveReverseLinkedList(Node *q, Node *p){

    if(p){
        recursiveReverseLinkedList(p, p->next);
        p->next = q;
    }
    else{
        first = q;
    }
}

int main(){

    int arr[] = {10, 20, 30, 40, 50};

    //Creating Linked List from Array
    Create(arr,5);


    //insertToSorterList(first, 35);
    //insertToSorterList(first, 15);

    Display(first);
    //removeDuplicates(first);
    recursiveReverseLinkedList(NULL, first);
    Display(first);

    cout<<endl;
    Node *temp;

    temp = iterativeSearch(first, 11);

    if(temp){
        cout << "Data is found, key is " << temp->data;
    }else{
        cout << "key not found " << endl;
    }

    //deleteNode(first, 3);
    Display(first);
    if(sorted(first)){
        cout << "The list is sorted"<<endl;
    }else{
        cout << "The list is not sorted" << endl;
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
