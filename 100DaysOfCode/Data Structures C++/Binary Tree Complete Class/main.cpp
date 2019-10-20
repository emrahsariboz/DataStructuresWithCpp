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
    void levelOrder(Node *p);

    int Count(Node *p);
    int Height(Node *p);
    int countLeafNode(Node *p);
    int countBinaryNode(Node *p);
    int sum(Node *p);
    int countDegreeOneNodes(Node *p);




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

void Tree::levelOrder(Node *p){

    queue<Node*> queueL;

    queueL.push(root);

    while(!queueL.empty()){
        p = queueL.front();
        cout << p->data <<endl;
        queueL.pop();

        if(p->lchild)
            queueL.push(p->lchild);
        if(p->rchild)
            queueL.push(p->rchild);
    }
}

int Tree::Count(Node *p){
    int n=0;
    int x,y;

    if(p == NULL)
        return 0;
    else{
        x = Count(p->lchild);
        y = Count(p->rchild);

        return x+y+1;
    }

}


int Tree::countBinaryNode(Node *p){
    int x = 0;
    int y= 0;

    if(p != nullptr){
        x = countBinaryNode(p->lchild);
        y = countBinaryNode(p->rchild);

        if(p->lchild && p->rchild){
            return x+y+1;
        }else{
            return x+y;
        }
    }

    return 0;

}



int Tree::countLeafNode(Node *p){
    int x = 0;
    int y= 0;

    if(p != nullptr){
        x = countLeafNode(p->lchild);
        y = countLeafNode(p->rchild);

        if(p->lchild == NULL && p->rchild == NULL ){
            return x+y+1;
        }else{
            return x+y;
        }
    }

    return 0;

}





int Tree::sum(Node *p){
    int x = 0;
    int y= 0;

    if(p != nullptr){
        x = sum(p->lchild);
        y = sum(p->rchild);
        return x+y+p->data;

    }

    return 0;

}

int Tree::countDegreeOneNodes(Node *p){
    int x = 0;
    int y= 0;

    if(p != nullptr){
        x = countDegreeOneNodes(p->lchild);
        y = countDegreeOneNodes(p->rchild);

        if( (p->lchild  && p->rchild == NULL) ||(p->lchild == NULL  && p->rchild )){
            return x+y+1;
        }else{
            return x+y;
        }
    }

    return 0;

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

    cout<<"Level order"<<endl;
    t.levelOrder(t.root);

    cout << "Total number of Node: ";
    cout<< t.Count(t.root) << endl;

    cout << "Total number of Binary Node: ";
    cout<< t.countBinaryNode(t.root) << endl;

    cout << "Total number of Leaf Node: ";
    cout<< t.countLeafNode(t.root) << endl;

    cout << "Sum of the nodes: ";
    cout<< t.sum(t.root) << endl;

    cout << "Total number of Binary Node with degree one : ";
    cout<< t.countLeafNode(t.root) << endl;
    return 0;
}
