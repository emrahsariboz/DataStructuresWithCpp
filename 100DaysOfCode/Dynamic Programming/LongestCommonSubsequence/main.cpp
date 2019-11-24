#include <iostream>
using namespace std;


static int A[] = {'b', 'd', '0'};
static int B[] = {'a', 'b', 'c', 'd', '0'};

//Recursive Solution to LCS problem
int LCS(int i, int j){

    if(A[i] == '0' || B[j] == '0' )
        return 0;
    else if (A[i] == B[j])
            return 1+LCS(i+1, j+1);
    else
        return std::max(LCS(i+1, j), LCS(i, j+1));
}

int main()
{

    int a = 0;
    int b = 0;

    int result = LCS(a,b);

    cout<<result<<endl;


    return 0;
}
