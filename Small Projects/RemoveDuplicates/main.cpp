#include <iostream>

using namespace std;

//O(n) auxilary space
int removeDuplicates(int arr[], int n){
    if (n ==0 || n == 1)
        return  n;

    int temp[n];
    int j = 0;

    for(int i=0; i<n-1; i++){
        if(arr[i] != arr[i+1]){
            temp[j++] = arr[i];
        }
    }

    temp[j++] = arr[n-1];

    for(int i=0; i<j; i++)
        arr[i] = temp[i];

    //Size of the new array
    return j;
}


//O(1) auxilary spacec

int removeDuplicates2(int arr[], int n){
    if (n==0 || n== 1)
        return n;

    int j=0;

    for(int i=0; i<n-1; i++)
        if(arr[i] != arr[i+1])
            arr[j++] = arr[i];

    arr[j++] = arr[n-1];

    return j;
}





int main()
{
    int arr[] = {1,2,2,3,4,4,4,5,5};

    int n = sizeof(arr) / sizeof(arr[0]);

    n = removeDuplicates2(arr,n);

    for(int i=0; i<n; i++){
        cout << arr[i] << endl;
    }

    return 0;
}
