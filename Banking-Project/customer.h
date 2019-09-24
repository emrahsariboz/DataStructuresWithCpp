#ifndef CUSTOMER_H
#define CUSTOMER_H
#include <iostream>
#include <fstream>
#include <map>
using namespace std;


class Customer
{
private:
    map<int, Customer> customerInformation;
public:
    int accountNumber;
    string customerName, customerLastName;
    float balance;
    static int nextAccountNumber;
    int lastAccountNumber = 0;

    Customer();
    Customer(string name, string lastnName, float balance);
    void createAccount(Customer c);
    friend ofstream & operator << (ofstream &ofs, Customer &c);
    friend ostream & operator << (ostream &ost, Customer &c);

    int getAccountNumber();
    int getLastId();
    float getBalance();
    string getCustomerName();
    string getCustomerLastName();


    Customer balanceInquery();
    void deposit();
    Customer withdrawal();

    void setLastId(int n);
    void getAccounts();
    void readAllAccount();
    void closeAccount();
};

#endif // CUSTOMER_H
