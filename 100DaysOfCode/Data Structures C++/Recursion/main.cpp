#include <iostream>

using namespace std;

int fun(int n){
    if (n>0){
        return fun(n-1) + n;
  }
    return 0;
}


//Static Variable Example

int fun2(int n){
    static int x=0;

    if(n>0){
        x++;
        return fun2(n-1) + x;
    }

    return 0;
}


int main()
{

    cout << fun(5) << endl;
    cout << "Static Variable: " << fun2(5) << endl;
    return 0;
}
