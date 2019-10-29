#include <QCoreApplication>
#include <iostream>
#include "Chains.h"

using namespace std;


int hashF(int key){
    return key%10;
}

void Insert(Node *H[], int key){
    int index = hashF(key);
    SortedInsert(&H[index], key);
}

int main(int argc, char *argv[])
{
    //pointer to pointer
/*
    int var = 789;
    int *ptr2;
    int **ptr1;
    ptr2 = &var;
    ptr1 = &ptr2;


    cout<<"The value of var = " <<var<<endl;
    cout<<"The value of var using single pointer " << *ptr2<<endl;
    cout<<"The value of var using double pointer " << **ptr1<<endl;


    cout<<"The value of p is " << ptr2 << endl;

    */


    Node *HT[10];
    Node *temp;
    int i;

    for(i=0; i<10; i++){
        HT[i] = NULL;
    }

    Insert(HT, 12);
    Insert(HT, 22);
    Insert(HT, 38);
    Insert(HT, 18);
    Insert(HT, 42);

    temp = Search(HT[hashF(123)], 123);

    cout<<temp->data << endl;
    return 0;
}
