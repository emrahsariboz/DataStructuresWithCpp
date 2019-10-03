#include <QCoreApplication>
#include <iostream>

using namespace std;

class Node{
public:
    int data;
    Node *next;
};


class LinkedList{
private:
    Node *first;
public:
    LinkedList(){first = NULL;}
    LinkedList(int A[], int n);
    ~LinkedList();

    void Display();
    void Insert(int index, int x);
    void Delete(int index);
    int Count();
};


int LinkedList::Count(){
    Node *p = first;
    int l =0;

    while(p){
        l++;
        p = p->next;
    }

    return l;
}

LinkedList::LinkedList(int A[], int n){
    int i = 0;
    Node *last, *t;

    first = new Node;
    first->data = A[0];
    first->next = NULL;
    last = first;

    for(i = 1; i<n ; i++){
        t = new Node;
        t->data = A[i];
        t->next = NULL;
        last->next = t;
        last= t;
    }
}

void LinkedList::Display(){

    Node *p = first;
    while (p) {
        cout << p->data << endl;
        p = p->next;
    }
}

void LinkedList::Insert(int index, int x){

    Node *t = new Node;
    //Validating the index
    if(index < 0 || index > Count())
        return;
    //Inserting whether to the head
    //or to desired position

    Node *p = first;

    t->data = x;
    t->next = NULL;

    if(index == 0){
        t->next = first;
        first = t;
    }else{
        for(int i=0; i<index-1; i++){
            p = p->next;

        }
    }
    t->next = p->next;
    p->next = t;
}


void LinkedList::Delete(int index){
    Node *p = first;
    Node *q = p;

    for(int i=0; i<index; i++){
        q = p;
        p = p->next;
    }
    q->next = p->next;
    cout << p->data << " is deleted " << endl;

    delete p;


}


int main()
{

    int A[] = {1,2,3,4,5};
    int n = 5;

    LinkedList *LL = new LinkedList(A, n);
    LL->Display();
    Node *p;
    LL->Insert( 3, 33);
    cout << " *** " << endl;
    LL->Display();
    LL->Delete(2);
    cout << "Delete operation " <<endl;
    LL->Display();

    return 0;
}
