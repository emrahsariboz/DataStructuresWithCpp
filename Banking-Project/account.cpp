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
void account::getBalance(){
    cout << " The balance is :" << balance<<endl;

}

void account::deposit(){
    cout << "How much would you like to deposit?";
    float d;
    cin>>d;
    balance += d;

    cout<< "New balance is: "<<balance<<endl;
}
void account::withdrawal(){
    cout<< "How much would you like to withdraw\n";
    float w;
    cin>>w;
    balance -= w;
    cout << "The new balance is: " << balance << endl;

}

void account::createAccount(){
    setName();
    setLastName();
    cout<<"Congrats! You just created new account! \n";
    setBalance();
    toString();
}
ostream & operator <<(ostream &ofs, account c){

    ofstream ofc("Customer.txt", ios::app);
    ofs << "Name: " <<c.name << endl;
    ofs << "Last Name: " <<c.lastName << endl;
    ofs << "Balance: " <<c.balance << endl;
    ofs << "Account Number: " <<c.accountNumber << endl;

    return ofs;
}

void account::writeToFile(account c){
    ofstream ofc("Customer.txt", ios::app);

    ofc<<c;
    ofc.close();
}

void account::readFromFile(account c){
    ifstream ifc("Customer.txt");

    for(string i;getline(ifc, i);){
        cout << i << endl;
        cout<< "*************" <<endl;
    }
}
