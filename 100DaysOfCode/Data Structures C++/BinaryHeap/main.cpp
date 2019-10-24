#include <iostream>
using namespace std;

void insert(int A[], int n){
    cout<<"N is : " << n <<endl;

    int i = n, temp;



    temp = A[i];
    cout<<"temp is: " << temp <<endl;

    while (i>1 && temp > A[i/2]) {
           A[i] =  A[i/2];
           i = i/2;
    }
    A[i] = temp;
}

int main()
{
    int H[] = {0,10,20,30,25,5,40,35};

    insert(H, 455);

    for(int i=1; i<=7; i++)
        cout<<H[i]<<endl;
    return 0;
}
