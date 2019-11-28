#include <iostream>

using namespace std;

int knapsack(int W, int weightsOfItem[], int val[], int n){
    int i, w;

    int K[n+1][W+1];

    for(int i=0; i<=n; i++){
        for(int j=0; j<=W; j++){
            if (i==0 || j==0)
                K[i][j] = 0;
            else if(weightsOfItem[i-1] > j)
                K[i][j] = K[i-1][j];
            else
                K[i][j] = std::max(val[i-1]+ K[i-1][j - weightsOfItem[i-1]], K[i-1][j]);
        }
    }

    return K[n][W];

}


int main()
{

        int val[] = {60, 100, 120};
        int wt[] = {10, 20, 30};
        int  W = 50;
        int n = sizeof(val)/sizeof(val[0]);
        printf("%d", knapsack(W, wt, val, n));
        return 0;
}
