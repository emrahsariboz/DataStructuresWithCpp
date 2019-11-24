#include <iostream>

using namespace std;


int LCS(int A[], int B[], int i, int j){
    i = j = 0;

    if(A[i] == '0' || B[j] == '0' ){
        cout<<"HERE"<<endl;
        return 0;
    }
    else if (A[i] == B[j])
            return 1+LCS(A, B, i+1, j+1);
    else
        return std::max(LCS(A, B, i+1, j), LCS(A, B, i, j+1));

}

int main()
{
    int A[] = {'b', 'd', '0'};

    int B[] = {'a', 'b', 'c', 'd', '0'};
    int a = 0;
    int b = 0;

    int result = LCS(A, B, a,b);

    cout<<result<<endl;


    return 0;
}
