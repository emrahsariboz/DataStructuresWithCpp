#include <QCoreApplication>
#include <iostream>

using namespace std;


struct Node{
    int data;
    Node *next;
};

Node *Head;

void create(int A[], int n){
    int i;
    Node *t, *last;

    Head = new Node;
    Head->data = A[0];
    Head->next = Head;

    last = Head;

    for(i = 1; i<n; i++){
        t = new Node;
        t->data = A[i];
        t->next = last->next;
        last->next = t;
        last = t;
    }

}

void RDisplay(Node *h){
    static int flag = 0;

    if(h != Head || flag == 0){
        flag  = 1;
        printf("%d ", h->data);
        RDisplay(h->next);
    }
    flag = 0;

}

void display(Node *h){
    do{
        printf("%d ", h->data);
        h = h->next;

    }while(h != Head);
    cout << endl;
}


void insert(int pos, int data){

    Node *temp, *p;

    if(pos == 0){
        temp = new Node;
        temp->data = data;
        if(Head == NULL){
            Head = temp;
            Head->next = Head;
        }
        else{
            p = Head;
            while(p->next != Head)
                p = p->next;
            p->next = temp;
            temp->next = Head;
            Head = temp;
        }

    }else{
        p = Head;

        for(int i=0; i<pos-1; i++)
             p =p->next;

        temp = new Node;
        temp->data = data;
        temp->next = p->next;
        p->next = temp;

    }
}

int deleteN(int pos){
    Node *p, *q;
    int data;

    if(pos == 1){
        p = Head;
        while(p->next != Head)
            p = p->next;
            data = Head->data;
        if(Head == p){
            delete Head;
            Head = NULL;
        }else{
            p->next = Head->next;
            delete Head;
            Head  = p->next;
        }
    }else{
        p = Head;

        for (int i=0; i<pos -2 ; i++)
            p = p->next;

        q = p->next;
        p->next  = q->next;
        data = q->data;
        delete q;
    }

    return data;
}


int main()
{
    int A[] = {1,2,3,4,5,6};
    create(A,5);
    RDisplay(Head);
    cout << endl;
    cout << "Inserting 15 to Singly Circular Linked List"<<endl;
    insert(0, 15);
    cout << endl;
    RDisplay(Head);
    cout << endl;
    cout << "Deleting the position 4" << endl;
    cout << deleteN(4) << " has been deleted!"<<endl;
    RDisplay(Head);
    cout << endl;
    return 0;
}
