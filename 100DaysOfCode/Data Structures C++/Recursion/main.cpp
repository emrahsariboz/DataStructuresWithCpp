#include <iostream>
#include <math.h>       /* pow */

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

//Tree recursion
void fun3(int n){
    if(n>0){
    printf("%d ", n);
    fun3(n-1);
    fun3(n-1);
    }
}

//Indirect Recursion
void funB(int n);
void funA(int n){
    if(n>0){
        printf("%d ", n);
        funB(n-1);
    }
}


void funB(int n){
    if(n>0){
        printf("%d ", n);
        funA(n-1);
    }
}

//Nested Recursion
int nestedRecursion(int n){
    if(n>100)
        return n-10;
     return nestedRecursion(nestedRecursion(n+11));
}


//Sum of first 'n' natural numbers

int sum(int n){
    if(n>0)
        return sum(n-1) + n;
}

//Factorial

int factorialIterative(int n){
    int mult=1;

    while(n>=1){
        mult *= n;
        n = n-1;
    }

     return mult;
}

int factorialRecursive(int n){
    if(n>=1)
        return factorialRecursive(n-1) * n;
    else
        return 1;
}

int pow(int base, int p){
    if(p == 0)
        return 1;
    return pow(base, p-1) * base;
}

int powUsingLessMultiplication(int b, int p){
    if(p == 0)
        return 1;
    if(p%2 == 0)
        return pow(b*b, p/2);
    else
        return b * pow(b*b , (p-1) / 2);

}

int main()
{
   // cout << fun(5) << endl;
    //cout << "Static Variable: " << fun2(5) << endl;
    //cout << "Calling Tree Recursion" << endl;

    //fun3(3);
    //cout << endl;

    //funA(20);

    //int r = nestedRecursion(95);
    //printf("%d\n", r);

    int sumOfFirstnNumber = sum(10);
    cout<<sumOfFirstnNumber << endl;

    int iterativeF= factorialIterative(5);
    cout <<iterativeF << endl;

    int recursiveF = factorialRecursive(5);
    cout << recursiveF << endl;



    cout << pow(2,4) << endl;
    cout << powUsingLessMultiplication(2, 4) << endl;
    return 0;
}
