#include <iostream>
#include "queue.h"
using namespace std;


Node *root = NULL;

void create(){
    Node *p, *t;
    int x;
    Queue q;
    q.createTree(&q,100);
    cout<<"Enter root value"<<endl;
    cin>>x;
    root = new Node;
    root->data = x;
    root->lchild = root->lchild = NULL;
    q.enqueue(root);

    while(!q.isEmpty(q)){
        p = q.dequeue();
        cout <<"enter left child of: "<<p->data<<endl;
        cin>>x;
        if(x!=-1){
            t = new Node;
            t->data = x;
            t->lchild = t->rchild = NULL;
            p->lchild = t;
            q.enqueue(t);
        }

        cout <<"enter right child of:  "<<p->data<<endl;
        cin>>x;
        if(x!=-1){
            t = new Node;
            t->data = x;
            t->lchild = t->rchild = NULL;
            p->rchild = t;
            q.enqueue(t);
        }

    }
}
void preorder(Node *p){
    if(p){
        cout <<p->data << endl;
        preorder(p->lchild);
        preorder(p->rchild);
    }
}
void inOrder(Node *p){
    if(p){

        inOrder(p->lchild);
        cout <<p->data << endl;
        inOrder(p->rchild);
    }
}

void postOrder(Node *p){
    if(p){

        postOrder(p->lchild);
        postOrder(p->rchild);
        cout <<p->data << endl;

    }
}
int main()
{
    create();
    preorder(root);
    cout<<"\n Post Order"<<endl;
    postOrder(root);
    cout<<"\n In Order" <<endl;
    inOrder(root);
    cout << endl;


    return 0;
}
