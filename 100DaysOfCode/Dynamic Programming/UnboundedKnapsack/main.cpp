#include <iostream>
#include <stdio.h>
#include <string.h>

using namespace std;
// Returns the maximum value with knapsack of
// W capacity
int unboundedKnapsack(int W, int n, int val[], int wt[])
{
    // dp[i] is going to store maximum value
    // with knapsack capacity i.
    int dp[W+1];
    memset(dp, 0, sizeof dp);

    int ans = 0;

   for(int w=0; w<=W; w++){
        for(int i=0; i<n; i++){
            if(w>=wt[i]){
                dp[w] = max(dp[w] , dp[w - wt[i]] + val[i]);
            }
        }
   }
      return dp[W];
  }

// Driver program
int main()
{
    int W = 25;
    int val[] = {10, 30, 20};
    int wt[] = {5, 10, 15};
    int n = sizeof(val)/sizeof(val[0]);

    cout<<"N is " << n << endl;

    cout << unboundedKnapsack(W, n, val, wt);

    return 0;
}
