#include <QCoreApplication>
#include <iostream>


using namespace std;
void mergeArrays(int a[], int sizeOfa, int b[], int sizeOfB, int c[]){
    int i=0, j=0, k=0;

    while(i<sizeOfa && j<sizeOfB){

        if(a[i] < b[j])
            c[k++] = a[i++];
        else
            c[k++] = b[j++];
    }

    for(;i<sizeOfa;i++)
        c[k++] = a[i++];

    for(;j<sizeOfB;j++)
        c[k++] = a[j++];
}


int main()
{
    int arr1[] = {1, 3, 5, 7};
    int n1 = sizeof(arr1) / sizeof(arr1[0]);

    int arr2[] = {2, 4, 6, 8};
    int n2 = sizeof(arr2) / sizeof(arr2[0]);

    int arr3[n1+n2];
    mergeArrays(arr1, n1, arr2,  n2, arr3);

    cout << "Array after merging" <<endl;
    for (int i=0; i < n1+n2; i++)
    cout << arr3[i] << " ";

    return 0;
}
