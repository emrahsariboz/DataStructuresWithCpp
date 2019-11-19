#include <iostream>

using namespace std;


int binarySearch(int arr[], int low, int high, int x){

    int mid = (low + high) / 2;

    cout<<mid<<endl;

    if(high < low)
        return -1;

    if(arr[mid] == x)
        return mid;

    if (x > arr[mid])
        binarySearch(arr, mid+1, high, x);
    else if (x < arr[mid])
        binarySearch(arr, low, mid-1,x);

}


int main(void)
{
    int arr[] = { 2, 3, 4, 10, 40 };
    int x = 40;
    int n = sizeof(arr) / sizeof(arr[0]);
    cout<<"Size of the array" << n << endl;
    int result = binarySearch(arr, 0, n - 1, x);
    (result == -1) ? cout << "Element is not present in array"<<endl
                   : cout << "Element is present at index " << result << endl;
    return 0;
}
