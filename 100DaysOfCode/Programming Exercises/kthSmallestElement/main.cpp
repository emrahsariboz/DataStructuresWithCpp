#include <iostream>
using namespace std;

int kthSmallestElement(int *arr1, int *arr2, int *m, int *n, int k){

    if (arr1 == m)
            return arr2[k];
        if (arr2 == n)
            return arr1[k];

    int mid1 = (m - arr1) / 2;
    int mid2 = (n - arr2) / 2;

    if(mid1 + mid2 < k){

        if(arr1[mid1] > arr2[mid2])
            //Ignore the first half of arr2
            return kthSmallestElement(arr1, arr2+mid2+1, m, n, k-mid2-1);
        else
            //Ignore the first half of arr1
           return kthSmallestElement(arr1+mid1+1, arr2, m, n, k-mid1-1);

    }else{
        if (arr1[mid1] > arr2[mid2])
            //Ignore the second half of arr1
            return kthSmallestElement(arr1, arr2, arr1 + mid1, n, k);
        else
            //Ignore the second half of arr2
            return kthSmallestElement(arr1, arr2, m, arr2 + mid2, k);
    }


}

int main()
{
    int arr1[5] = {2, 3, 6, 7, 9};
    int arr2[4] = {1, 4, 8, 10};

    int k = 5;
    cout << kthSmallestElement(arr1, arr2, arr1 + 5, arr2 + 4,  k - 1);
    return 0;
}
