#include <iostream>
#include "maxheap.h"
using namespace std;


int main()
{
    int A[] = {2,10,20,5,8,13};
    MaxHeap maxH(A, 6);

    maxH.heapify(6);

    maxH.printHeap();
    return 0;
}
