#include <iostream>

using namespace std;

int getClosest(int val1, int val2,
               int target)
{
    if (target - val1 >= val2 - target)
        return val2;
    else
        return val1;
}

int findClosest(int arr[], int size, int target){

    if(target<=arr[0])
        return arr[0];
    if(target>=arr[size-1])
        return arr[size-1];

    int low = 0;
    int high = size;
    int mid =0;

    while(low<high){
        mid = (low+high) / 2;

        if(arr[mid] == target )
            return arr[mid];

        if(target < arr[mid]){

            if(mid > 0 && target > arr[mid-1])
                return getClosest(arr[mid-1], arr[mid], target);

            high = mid;
        }else{

            if(mid<size-1 && target < arr[mid+1])
                return getClosest(arr[mid], arr[mid+1], target);

            low = mid+1;
        }


    }

    return arr[mid];


}

int main(int argc, char *argv[])
{

    int arr[] = { 1, 2, 4, 5, 6, 6, 8, 9 };
    int n = sizeof(arr) / sizeof(arr[0]);
    int target = 6;
    cout << (findClosest(arr, n, target))<<endl;

    return 0;
}
