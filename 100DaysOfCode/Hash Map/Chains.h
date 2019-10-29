
#ifndef CHAINS_H
#define CHAINS_H
#include <stddef.h>

class Node{
public:
    int data;
    Node *next;
};

void SortedInsert(Node **H, int x){
    Node *t ,  *q = NULL;
    Node *p = *H;

    t = new Node;
    t->data = x;
    t->next = NULL;

    if(*H == NULL)
        *H = t;
    else{
        while (p && p->data < x){
            q=p;
            p = p->next;
        }
        if(p == *H){
            t->next = *H;
            *H = t;
        }else{
            t->next = q->next;
            q->next = t;
        }

    }
}

Node *Search(Node *p, int key){
    while (p!=NULL) {
        if(key == p->data){
            return p;
        }
        p = p->next;
    }
    return NULL;
}

#endif // CHAINS_H
