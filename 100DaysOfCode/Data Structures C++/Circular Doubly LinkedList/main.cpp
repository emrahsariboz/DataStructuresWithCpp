#include <iostream>
using namespace std;

struct Node{
    Node *prev;
    int data;
    Node *next;

}*head;



void create(int A[], int n){

    Node *temp, *last;
    int i =0;
    head = new Node;


    head->data = A[i];
    head->next = head;
    head->prev = head;
    last = head;


    for(i=1; i<n; i++){
        temp = new Node;
        temp->data = A[i];

        temp->next = head;
        temp->prev = last;
        head->prev = temp;

        last->next = temp;

        last = temp;
    }


}


void Display(Node *p){
    p = head;
    do
    {
        printf("%d ",p->data);

        p=p->next;

    }while(p != head);
    cout << endl;

}

int Count(Node *p){
    p = head;
    int t=1;
    do{
        t++;
        p = p->next;

    }while(p->next != head);

    return t;
}

void insert(int pos, int data){
    if(pos > Count(head) || pos < 0)
        cout << " Wrong position" << endl;
    Node *temp;
    Node *p;
    if(pos == 0){
        temp = new Node;
        temp->data = data;
        temp->prev = head->prev;
        head->prev->next = temp;

        head->prev = temp;
        temp->next = head;
        head = temp;
    }else{
        p = head;
        for(int i=0; i<pos-1; i++)
            p = p->next;

        temp = new Node;
        temp->data = data;
        temp->next = p->next;
        p->next = temp;
        temp->prev = p;
        p->next->prev = temp;
    }
}

bool search(int dataS){
    Node *p = head;
    bool condition = false;
    do{

        if(p->data == dataS)
            condition = true;
        p = p->next;
    }while (p->next != head);

    return condition;
}

int deleteN(int position){

    Node *p = head;

    int data = 0;
    if(position < 0 || position > Count(head))
        return -1;


    if(position == 0){
        data = p->data;
        head->prev->next = head->next;
        head->next->prev = head->prev;
        head = head->next;
        delete p;
        cout << head->prev->data << " head prev data" << endl;


    }else{

        for(int i=0; i<position-1; i++)
            p = p->next;


        if(p->next == head){
            data = p->data;
            p->prev->next =head;
            p->next->prev = p->prev;
            delete p;
        }else{
            cout << p->data << " is " << endl;
            p->prev->next = p->next;
            p->next->prev = p->prev;
            data = p->data;
            delete p;
        }
    }
    return data;
}

int main()
{
    int A[] = {10,20,30,40,50};
    create(A, 5);

    Display(head);

    cout << "The size is: " << Count(head) << endl;

    insert(5, 999);
    cout << endl;
    Display(head);
    cout << endl;
    cout << deleteN(0) << " is deleted ";
    cout<<endl;
    Display(head);


}
