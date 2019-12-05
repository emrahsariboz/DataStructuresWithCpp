#include <iostream>

using namespace std;

int maxSubArraySum(int a[], int size){
     int max_ending_here=0, max_so_far = 0;

     for(int i=0; i<size; i++){
         max_so_far = max_so_far + a[i];

         if(max_so_far < 0 )
             max_so_far = 0;
         else if(max_ending_here < max_so_far)
             max_ending_here = max_so_far;
     }

     return max_so_far;
}


int main()
{
   int a[] =  {5, 15, -30, 10, -5, 40, 10};
   int n = sizeof(a)/sizeof(a[0]);
   int max_sum = maxSubArraySum(a, n);
   cout << "Maximum contiguous sum is " << max_sum << endl;
   return 0;
}
