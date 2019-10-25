#include "Tree.h"
Tree::Tree(){

}
Tree::Tree(int size)
{
    this->size = size;
    this->rear = 0;
    this->front = 0;
    this->Q = new Node*[size];
}


void Tree::createTree(){
    Node *p, *t;
    int x;
    Tree q(100);
    cout<<"Enter root value"<<endl;
    cin>>x;
    root = new Node;
    root->data = x;
    root->lchild = root->lchild = NULL;
    q.enqueue(root);

    while(!q.isEmpty()){
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



void Tree::enqueue(Node *x){
    if (rear+1 % size == front ){
        cout << "Its already full" <<endl;
    }else{
        rear = rear + 1 % size;
        Q[rear] = x;
    }
}
Node * Tree::dequeue(){
    Node* data = NULL;
    if (front == rear){
        cout << "Queue is empty"<<endl;
    }else{
        front = front +1 % size;
        data = Q[front];
    }

    return data;
}


int Tree::isEmpty(){
    return front == rear;
}

void Tree::LevelOrder(Node *root){
    Tree q(100);

    cout << root->data <<endl;

    q.enqueue(root);

    while(!q.isEmpty()){
        root = q.dequeue();

        if(root->lchild){
            cout << root->lchild->data<<endl;
            q.enqueue(root->rchild);

        }

        if(root->rchild){
            cout << root->rchild->data<<endl;
            q.enqueue(root->rchild);
        }
    }

}

int Tree::Height(Node *root){
    int x = 0, y= 0;
    if(root == 0)
        return 0;
    x=Height(root ->lchild);
    x=Height(root->rchild);

    if(x>y)
        return x+1;
    else
        return y+1;
}

void  Tree::preorder(Node *p){
    if(p){
        cout <<p->data << endl;
        preorder(p->lchild);
        preorder(p->rchild);
    }
}


void Tree::inOrder(Node *p){
    if(p){

        inOrder(p->lchild);
        cout <<p->data << endl;
        inOrder(p->rchild);
    }
}

void Tree::postOrder(Node *p){
    if(p){

        postOrder(p->lchild);
        postOrder(p->rchild);
        cout <<p->data << endl;

    }
}

