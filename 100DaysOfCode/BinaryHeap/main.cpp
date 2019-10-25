#include <iostream>
#include <vector>
#include "Minheap.h"
using namespace std;

int main()
{

      Minheap h(10);

      for(int i=0; i<10; i++){
          cout<<"Inserting element: " << i+1 <<endl;
          h.insertKey(rand() % 100);
          h.printHeap();
          cout<<endl;
      }





      int A [] = {1,3,5,4,6,13,10,9,8,15,17};
      int size = sizeof(A) / sizeof (A[0]);

      Minheap heapifyBinaryHeap(A, size);

      heapifyBinaryHeap.createHeapFromGivenArray(A, size);
      cout<<endl;
      cout<<"USING HEAPIFY " << endl;
      heapifyBinaryHeap.printHeap();

    return 0;
}
