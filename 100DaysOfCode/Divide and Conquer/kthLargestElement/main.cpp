#include <iostream>

using namespace std;

int swap(int *a, int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

int partition(int arr[], int low, int high){
    int pivot= arr[high];

    int i = (low-1);


    for(int j=low; j<=high - 1; j++){
        if (arr[j] <= pivot){
            i++;
            swap(&arr[i], &arr[j]);
        }
    }

    swap(&arr[i+1],&arr[high]);

    //cout<<arr[i+1]<<endl;
    return (i+1);
}


int kthSmallest(int arr[], int low, int high, int key)
{
    // If k is smaller than number of elements in array
    if (key > 0 && key <= high - low + 1)
    {
        // Partition the array around last element and get
        // position of pivot element in sorted array
        int pos = partition(arr, low, high);

        // If position is same as k
        if (pos-low == key-1){
            cout<<"base case"<<endl;
            return arr[pos];
        }
        if (pos-low > key-1) { // If position is more, recur for left subarray
            cout<<"pos -1: " <<pos-1<<endl;
            cout<<"k -1: "<< key-1<<endl;
            return kthSmallest(arr, low, pos-1, key);
        }
        // Else recur for right subarray
        return kthSmallest(arr, pos+1, high, key-pos-1);

    }

    // If k is more than number of elements in array
    return INT_MAX;
}




int main()
{
    int arr[] = {23,18,22,66,44,24};
    int n = sizeof(arr)/sizeof(arr[0]), k =5;
    cout<<"SIZE " << n << endl;
    cout << "K'th smallest element is: " << kthSmallest(arr, 0, n-1, k) << endl;
    return 0;
}
