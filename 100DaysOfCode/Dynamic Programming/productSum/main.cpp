#include <QCoreApplication>
#include <iostream>

using namespace std;

int productSum(int a[], int n){

    if(n == 0)
        return 0;

    int *opt = new int[n];

    opt[0] = 0;
    opt[1] = a[1];



    for(int i=2; i<n; i++){
           opt[i] =  std::max(opt[i-1] + a[i], opt[i-2] + a[i-1]*a[i]);
           cout<<opt[i-1] + a[i] << " VS " << opt[i-2] + a[i-1]*a[i] << endl;
    }

    for(int i=0; i<n; i++){
          cout<< opt[i] <<endl;
    }

    return opt[n-1];

}

int main(int argc, char *argv[])
{
    int A[] = { 1, 4, 3, 2, 3, 4, 2};
    int n = sizeof (A) / sizeof (A[0]);


    cout<<productSum(A, n) << endl;
    return 0;
}
