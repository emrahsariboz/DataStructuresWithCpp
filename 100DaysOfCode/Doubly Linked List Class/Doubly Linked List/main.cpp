#include <iostream>


using namespace  std;
struct Node{
    struct Node *prev;
    struct Node *next;
    int data;
}*first = NULL;

void create(int A[], int n){
    int i=0;
    Node *last;
    Node *temp;
    first = new Node;

    first->prev = NULL;
    first->data = A[i];
    first->next = NULL;
    last = first;

    for(i=1; i<n; i++){
       temp = new Node;
       temp->data = A[i];
       temp->next = last->next;
       temp->prev = last;
       last->next = temp;

       last =temp;

    }
}
int Count(Node *p){
    int len=0;

    while (p) {
        len++;
        p= p->next;
    }

    return len;
}


void Display(Node *p){
    while (p) {
        printf("%d ", p->data);
        p = p->next;
    }
    cout<<endl;
}


void insert(Node *t, int pos, int data){
    Node *p = first;

    if(Count(t) < pos )
        return;

    if(pos == 0){
        t = new Node;
        t->prev = NULL;
        t->data = data;
        t->next = first;
        first->prev = t;
        first = t;
    }else{
        for(int i=0; i<pos-1; i++)
            p = p -> next;
        t = new Node;
        t->data = data;
        t->prev = p;
        t->next = p->next;




        if(p->next){
            p->next->prev = t;
             p->next = t;
        }
    }
}


int deleteN(Node *t, int pos){
    int data = 0;
    Node *p = first ;
    if(pos > Count(t) || pos < 0)
        return -1;

    if(pos == 0){
        first = first->next;
        if(first) first->prev = NULL;
        data = p->data;
        delete p;
    }else{
        for(int i=0; i<pos-1; i++)
            p = p->next;

        p->prev->next = p->next;
        if(p->next) p->next->prev = p->prev;
        data = p->data;
        delete p;
    }

    return data;
}

void reverseDoubly(Node *p){
    Node *temp;

    while (p) {
        temp = p->next;
        p->next = p->prev;
        p->prev = temp;
        p = p->prev;

        if(p!= NULL && p->next == NULL)
            first = p;
    }
}

int main(int argc, char *argv[])
{
/*
    int A[] = {10,20,30,40,50};
    create(A, 5);

    printf("The length is %d \n" , Count(first));
    Display(first);
    insert(first, 4, 100);
    Display(first);
    deleteN(first, 2);
    Display(first);
    cout<<"Reversing " << endl;
    reverseDoubly(first);
    Display(first);
    */

    int *p;

    p = new int[5];
    p[0] = 1;
    p[1] = 2;

    cout << p[0] << endl;



    return 0;
}
