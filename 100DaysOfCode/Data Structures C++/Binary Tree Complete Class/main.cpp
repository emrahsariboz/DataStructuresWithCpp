#include <iostream>
#include <queue>
#include <stack>
using namespace std;

class Node{

public:
    Node* lchild;
    int data;
    Node* rchild;
};


class Tree{

public:
    Node* root;
    void createTree();
    void Preorder(Node* p);
    void InOder(Node *p);
    void PostOrder(Node *p);
    void iterativePreorder(Node *p);
    void iterativeInorder(Node *p);
    void iterativePostorder(Node *p);

    int Count(Node *p);
    int Height(Node *p);
    int countLeafNode(Node *p);
    int countBinaryNode(Node *p);
    int sum(Node *p);



};

void Tree::createTree(){
    queue<Node*> queueForTree;
    Node *p, *t;
    root = new Node();
    int value= 0;

    cout<<"Enter the root value" <<endl;
    cin>>value;

    root->data = value;

    queueForTree.push(root);

    while (!queueForTree.empty()) {
        p = queueForTree.front();
        queueForTree.pop();

        cout << "enter the left child of " << p->data << " : " << endl;
        cin>>value;
        if(value != -1){
            t = new Node;
            t->data = value;
            t->lchild = NULL;
            t->rchild = NULL;
            p->lchild = t;
            queueForTree.push(t);
        }

        cout << "enter the right child of " << p->data << " : " << endl;
        cin>>value;
        if(value != -1){
            t = new Node;
            t->data = value;
            t->lchild = NULL;
            t->rchild = NULL;
            p->rchild = t;
            queueForTree.push(t);
        }
}

}

void Tree::Preorder(Node *p){
    if(p){
        cout << p->data << endl;
        Preorder(p->lchild);
        Preorder(p->rchild);
    }
}

void Tree::InOder(Node *p){
    if(p){
        Preorder(p->lchild);
        cout << p->data << endl;
        Preorder(p->rchild);
    }
}


void Tree::iterativePreorder(Node *p){
    stack<Node*> s;

    while(p != NULL || !s.empty()){
          if(p!=NULL){
            cout << p->data <<endl;
            s.push(p);
            p = p->lchild;
          }else{
            p = s.top();
            s.pop();
            p = p->rchild;
          }
    }
}


void Tree::iterativeInorder(Node *p){
    stack<Node*> s;

    while(p != NULL || !s.empty()){
          if(p!= NULL){
            s.push(p);
            p = p->lchild;
          }else{
            p = s.top();
            s.pop();
            cout<<p->data<<endl;
            p = p->rchild;
          }
    }
}


void Tree::iterativePostorder(Node *p){
    stack<Node*> left;
    stack<Node*> right;

    left.push(p);
    while(!left.empty()){
        p = left.top();
        left.pop();
        right.push(p);

        if(p->lchild)
            left.push(p->lchild);
        if(p->rchild)
            left.push(p->rchild);
    }

    while (!right.empty()) {
        p = right.top();
        right.pop();
        cout << p->data << endl;
    }
}

int main()
{
    Tree t;
    t.createTree();
    t.Preorder(t.root);
    cout<<"In order"<<endl;
    t.InOder(t.root);

    cout<<"Iterative preorder"<<endl;
    t.iterativePreorder(t.root);

    cout<<"Iterative inorder"<<endl;
    t.iterativeInorder(t.root);

    cout<<"Iterative postOder"<<endl;
    t.iterativePostorder(t.root);
    return 0;
}
