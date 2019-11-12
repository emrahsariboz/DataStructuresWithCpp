#include <iostream>

using namespace std;

void insertionSort(int  arr[], int n){
    int key,j;
    for(int i = 1; i<n; i++){
        key = arr[i];
        j = i-1;
        while (j >= 0 && arr[j] > key) {
                arr[j+1] = arr[j];
                j = j-1;
        }
        arr[j+1] = key;
    }

}

void printArray(int arr[], int n)  {
    int i;
    for (i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;
}

int main()
{
    int array[5] = {5,2,6,1,10};

    insertionSort(array, 5);
    printArray(array,5);

    return 0;
}
