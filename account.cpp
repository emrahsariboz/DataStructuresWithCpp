#include "account.h"
int account::customerNumber = 0;
account::account()
{

    customerNumber++;
    accountNumber = customerNumber;

}

void account::setName(){
    cout <<"What is your name" << endl;
    cin >> name;

}

void account::setLastName(){
    cout <<"What is your lastName" << endl;
    cin >> lastName;

}

void account::toString(){
    cout << "Customer Number: " << customerNumber<<endl;
    cout << "First Name: " << name<<endl;
    cout << "Last Name: " << lastName<<endl;
    cout << "He/she has a balance of: " << balance << endl;
}

void account::setBalance(){
    balance = MIN_BALANCE;
}

string account::getName(){
    return name;
}

string account::getLastName(){
    return lastName;
}
double account::getBalance(){
    return balance;
}

void account::deposit(){
    cout << "How much would you like to deposit?";
    float d;
    cin>>d;
    balance += d;

    cout<< "New balance is: "<<balance<<endl;
}
void account::withdrawal(double w){
    balance -= w;
}

void account::createAccount(){
    setName();
    setLastName();
    cout<<"Congrats! You just created new account! \n";
    setBalance();
    toString();
}
