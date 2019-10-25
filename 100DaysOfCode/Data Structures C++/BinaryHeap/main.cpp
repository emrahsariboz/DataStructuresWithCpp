#include <iostream>
#include <vector>
#include "Minheap.h"
using namespace std;

void insertToHeap(vector<int> A, int n){
    cout<<"N is : " << n <<endl;

    int i = n, temp;
    temp = A[i];

    while (i>1 && temp > A[i/2]) {
           A[i] =  A[i/2];
           i = i/2;
    }
    A[i] = temp;
}

int main()
{
      Minheap h(3);
      h.insertKey(3);
      h.insertKey(2);
      h.insertKey(12);
      h.insertKey(19);
      cout<<h.getMin()<<endl;
    return 0;
}
