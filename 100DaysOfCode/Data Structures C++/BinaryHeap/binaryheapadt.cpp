#include "Minheap.h"

Minheap::Minheap(int cap)
{
    heap_size = 0;
    capacity = cap;
    arr = new int[capacity];

}

Minheap::Minheap(int A[] , int cap)
{
    heap_size = 0;
    capacity = cap;
    arr = new int[capacity];
    for(int i=0; i<capacity; ++i)
        arr[i] = A[i];
}



int Minheap::left(int i){
    return  2*i  + 1;
}

int Minheap::right(int i){
    return 2*i+ 2;
}

int Minheap::parent(int i){
    return i/2;
}

void Minheap:: swap(int *x, int *y)
{
    int temp = *x;
    *x = *y;
    *y = temp;
}

int Minheap::getMin(){
    return arr[0];
}

void Minheap::insertKey(int k){
    if(heap_size == capacity){
        cout << "Capacity is full!"<<endl;
        return;
    }

    heap_size++;
    int i = heap_size - 1;
    arr[i] = k;

    while(i != 0 && (arr[parent(i)] > arr[i] )){
        swap(&arr[i], &arr[parent(i)]);
        i = parent(i);
    }
}

void Minheap::Heapify(int n){
    int l = left(n);
    int r = right(n);
    int smallest = n;

    if(l<heap_size && (arr[l] < smallest))
        smallest = l;
    else if(r < heap_size && (arr[r] < smallest))
        smallest = r;


    if(smallest != n){
        swap(&arr[n], &arr[smallest]);
        Heapify(smallest);
    }

}

int Minheap::extractMin(){
    if(heap_size < 0){
        cout<<"Its empty" <<endl;
        return -1;
    }
    if(heap_size == 1){
        heap_size--;
        return arr[0];
    }else{
        int root = arr[0];


        heap_size--;
        Heapify(0);
        return root;
    }
}

void Minheap::Heapify(int A[], int n){
    int l = left(n);
    int r = right(n);
    int smallest = n;

    if(l<heap_size && (A[l] < smallest))
        smallest = l;
    else if(r < heap_size && (A[r] < smallest))
        smallest = r;


    if(smallest != n){
        swap(&A[n], &A[smallest]);
        Heapify(A, smallest);
    }

}


void Minheap::createHeapFromGivenArray(int A[], int n){
        int startIndex = (n/2) -1 ;
        for(int i=startIndex; i>=0; i--){
            Heapify(A, i);
        }
}


void Minheap::printHeap(){
    int i = 0;
    int power = 0;
    for(i=0; i<heap_size; i++){
        if(arr[i] < 0){

        }else{
        cout<<arr[i] << " ";
        if(i == power){
            power = (power+1) * 2;
            i = 0;
            cout<<endl;
        }
        }

    }
}
