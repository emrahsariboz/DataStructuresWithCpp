#include <iostream>
#include <math.h>       /* pow */
#include <sys/stat.h>
#include <unistd.h>
#include <string>
#include <fstream>


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

void pattern(int n){
    if(n<=0){
        cout<<n<<endl;
        n += 5;
    }else{
        cout<<n<<endl;
        pattern(n-5);

    }
}

int gcd(int a, int b){
    cout<<"gcd("<<a<<","<<b<<") called"<<endl;
    int q, r = 0;
    if(a%b == 1)
        return 1;
    else if(a%b == 0)
        return b;
    else{
        q = a / b;
        r = a - q*b;
        return gcd(b, r);
    }

}

void move(int numOf, char A, char B, char C){
    if(numOf==1)
        cout<<"Moving desk from " << A << " to " << C <<endl;
    else{
        move(numOf-1, A, C, B);
        cout<<"Moving disc " << numOf <<" from " << A << " to" <<C<<endl;
        move(numOf-1, B, A, C);}
}

void recursivePrintStar(int n){
    if (n == 1)
        cout<<"X";
    else{
        cout<<"X"<<endl;
        recursivePrintStar(n-1);

    }
}

int exponent(int base, int power){
    if(power ==  0)
        return base;
    else{
        return  base * exponent(base, power -1) ;
    }
}

bool isPalindrome(string s){
    if(s.length() < 2){
        return true;
    }else{
        int s1 = s[0];
        int s2 = s[s.length() - 1];
        if(s1==s2){
            string rest = s.substr(1,s.length() - 2);
            return isPalindrome(rest);
        }else{
            return false;
        }
    }
}


void printBinary(int n){
    cout<<"PrintBinary("<<n<<")"<<endl;
    if(n == 1)
        cout<<n;
    else{
        printBinary(n /2);
        cout << n%2;

    }
}

void reverseLine(ifstream& input){

    string line;

    if(getline(input, line)){
        reverseLine(input);
        cout<<line<<endl;
    }else{

    }
}

int combination(int n, int r){
    if( n == r || r==0  )
        return 1;

    return combination(n-1, r-1) + combination(n-1,r);
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
    /*
    int sumOfFirstnNumber = sum(10);
    cout<<sumOfFirstnNumber << endl;

    int iterativeF= factorialIterative(5);
    cout <<iterativeF << endl;

    int recursiveF = factorialRecursive(5);
    cout << recursiveF << endl;



    cout << pow(2,4) << endl;
    */

    //cout<<"PATTERN"<<endl;

   // pattern(10);

   // move(3,'A','B','C');
    cout<<combination(4,2) <<endl;
    return 0;
}
