#include <iostream>
using namespace std;


static int A[] = {'b', 'd'};
static int B[] = {'a', 'b', 'c', 'd'};

//Recursive Solution to LCS problem
int LCS(int i, int j){

    if(A[i] == '0' || B[j] == '0' )
        return 0;
    else if (A[i] == B[j])
            return 1+LCS(i+1, j+1);
    else
        return std::max(LCS(i+1, j), LCS(i, j+1));
}

//Memoization

void lcs(int lengthOfA, int lengthOfB){
    int L[lengthOfA][lengthOfB];

    for(int i=0; i<=lengthOfA; i++){
        for(int j=0; j<=lengthOfB; j++){
            if (i ==0 || j == 0)
                L[i][j] = 0;
            else if(A[i-1] == B[j-1])
                L[i][j] = 1 + L[i-1][j-1];
            else
                L[i][j] = max(L[i-1][j] , L[i][j-1]);
        }
    }

    for(int i=0; i<=lengthOfA; i++){
        for(int j=0; j<=lengthOfB;j++){
            cout<<L[i][j]<<" " ;
        }
        cout<<endl;
    }

    int index = L[lengthOfA][lengthOfB];

    char lcs[index];

    int i = lengthOfA, j = lengthOfB;

    while(i>0 && j >0){
        if(A[i-1] == B[j-1]){
            lcs[index-1] = A[i-1];
            i--; j--; index--;
        }else if (L[i-1][j] > L[i][j-1])
            i--;
         else
            j--;
    }

    cout << "LCS of A and B is " << lcs<<endl;

}

void printLongest(){


}

int main()
{

    int a = sizeof (A)/sizeof (A[0]);
    int b = sizeof (B)/sizeof (B[0]);

    //int result = LCS(a=0,b=0);

    //int DPsolution = lcs(a,b);

    lcs(a,b);

    //cout<<DPsolution<<endl;


    return 0;
}
