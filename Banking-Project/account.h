#ifndef ACCOUNT_H
#define ACCOUNT_H
#define firstId 0
#define MIN_BALANCE  5000

#include <iostream>
#include <fstream>
using namespace std;


class account
{
private:
    static int customerNumber;
    int accountNumber;
    string name, lastName;
    double balance;
 public:
    account();
    void toString();
    void setName();
    void setLastName();
    void setBalance();
    void getBalance();
    string getName();
    string getLastName();
    string getAccountNumber();
    string getCustomerID;
    void deposit();
    void withdrawal();
    void createAccount();
    friend ostream & operator <<(ostream &ofs, account c);
    friend ifstream & operator >>(ifstream &ofs, account c);

    void writeToFile(account c);
    void readFromFile(account c);

};



#endif // ACCOUNT_H
