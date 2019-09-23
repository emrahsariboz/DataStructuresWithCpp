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
  public:
    Customer();
    Customer(int accountNumber, string name, string lastnName, float balance);
    void createAccount();


    friend ofstream & operator << (ofstream &ofs, Customer &c);
    friend ostream & operator << (ostream &ost, Customer &c);


    int getAccountNumber();
    float getBalance();
    Customer balanceInquery();
    Customer deposit();
    Customer withdrawal();
    void setLastId(int n);
    int getLastId();
    string getCustomerName();
    string getCustomerLastName();



};

#endif // CUSTOMER_H
