#include <iostream>

using namespace std;

int* _lis(int arr[], int n){
    int *lis = new int[n];

        lis[0] = 1;

        /* Compute optimized LIS values in bottom up manner */
        for (int i = 1; i < n; i++ )
        {
            lis[i] = 1;
            for (int j = 0; j < i; j++ )
                if ( arr[i] > arr[j] && lis[i] < lis[j] + 1)
                    lis[i] = lis[j] + 1;
        }


       return lis;
    }


int main()
{
    int arr[] = { 10, 22, 9, 33, 21, 50, 41, 60 };
    int n = sizeof(arr)/sizeof(arr[0]);
    int *a;
    a = _lis(arr, n);

    for(int i=0; i<n; i++){
        cout<<a[i] << endl;
    }

    return 0;
}
