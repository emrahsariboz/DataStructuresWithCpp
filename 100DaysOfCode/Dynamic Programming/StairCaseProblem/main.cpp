#include <iostream>

using namespace std;


int countWays(int n){
    int res[n];

    res[0] = 1, res[1] = 1;

    for(int i=2; i<=n; i++){
        res[i] = res[i-1]+res[i-2];
    }

    return res[n];
}

int main()
{

    int n = 4;

    cout<<"Number of ways to reach stair "<<n <<" is " << countWays(n) <<endl;

    return 0;
}
