#include <iostream>
using namespace std;

void swap(int *A, int *B){
    int temp = *A;
    *A = *B;
    *B = temp;
}


int partition(int A[], int low, int high){
    int pivot = A[low];
    int i=low;
    int j=high+1;

    do{
        do{
            i++;
        }while(A[i] <= pivot);

        do{
            j--;
        }while(A[j] > pivot);

        if(i<j)
            swap(&A[i], &A[j]);
     }while(i<j);

    swap(&A[low],&A[j]);

    return j;
}

void QuickSort(int A[], int l, int h){
    int j;
    if (l<h){
        j = partition(A, l, h);
        QuickSort(A, l , j-1);
        QuickSort(A, j+1, h);
    }
}

void printArray(int arr[], int n){
    for(int i=0; i<n; i++){
        cout<<arr[i] << " ";
    }
    cout<<endl;
}

int main()
{

    int A[] = {1,6,123,23,4,89,19};
    int n = sizeof(A) / sizeof(A[0]);

    QuickSort(A, 0, n-1);

    printArray(A, n);

    return 0;
}
