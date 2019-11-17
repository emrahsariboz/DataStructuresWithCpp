#include <iostream>
#include "unordered_map"

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

//Removing duplicates from unsorted array

void removeDups(int arr[], int n){
    unordered_map<int, bool> mp;

    for(int i=0; i<n; i++){
        if(mp.find(arr[i]) == mp.end())
            cout<<arr[i]<<" ";


        mp[arr[i]] = true;
    }


   for(auto i=mp.begin(); i!=mp.end(); i++)
       cout<<i->first << "\t" << i->second << endl;
}



int main()
{
    int arr[] = {1,2,2,3,4,4,4,5,5};

    int n = sizeof(arr) / sizeof(arr[0]);

    n = removeDuplicates2(arr,n);

    for(int i=0; i<n; i++){
        cout << arr[i] << endl;
    }


    int arr2[] = {2,4,5,44,4,12,12,34};
    removeDups(arr2, sizeof(arr2) / sizeof (arr2[0]));


    return 0;
}
