#include <QCoreApplication>
#include <iostream>

using namespace std;

int pow(int base, int power){

    if(power == 0)
        return 1;
    int temp = pow(base, power/2);
    if(power%2==0)
        return temp* temp;
    else
        return (base * temp * temp);
}


int main(int argc, char *argv[])
{

    cout<<pow(2,8)<<endl;

}
