#include "customer.h"
int Customer::nextAccountNumber = 0;

Customer::Customer()
{
    nextAccountNumber++;

    accountNumber = nextAccountNumber;
}

Customer::Customer(int accountNumber, string name, string LastName, float balance){
        this->balance = balance;
        customerName = name;
        customerLastName = LastName;
        nextAccountNumber++;

        accountNumber = nextAccountNumber;
}

void Customer::createAccount(){

    cout <<"What is your name" << endl;
    cin >> customerName;
    cout <<"What is your lastName" << endl;
    cin >> customerLastName;
    cout << " What is your balance"<< endl;
    cin>>balance;

    //nextAccountNumber++;
    //accountNumber = nextAccountNumber;
    cout <<"the accout number is : " << accountNumber << endl;
    ofstream ofs;
    Customer c(accountNumber, customerName, customerLastName,balance);
    cout << endl;




    cout<<"Congradulation Account is Created"<<endl;
    cout << "BEfore print L :" << c.customerName << endl;
    cout << c;

    customerInformation.insert(pair<int, Customer>(c.accountNumber, c));



    ofstream ofc("BankingInformation.txt", ios::app);

    map<int, Customer>::iterator itr;

    for (itr = customerInformation.begin(); itr != customerInformation.end(); ++itr) {

            ofc<< itr -> second <<endl;
    }
    customerInformation.clear();
    ofc.close();

}


Customer Customer::balanceInquery(){
    cout <<" For which customer you would like to get Balance Information? " << endl;
    int n;
    cin >> n;
    map<int, Customer>::iterator itr = customerInformation.find(n);
    return itr -> second;
}

Customer Customer::deposit(){
    cout <<" For which customer you would like to deposit? " << endl;
    int n;
    cin >> n;
    float total;
    cout << " How much would you like to deposit : " << endl;
    cin >> total;
    map<int, Customer>::iterator itr = customerInformation.find(n);

    itr->second.balance += total;

    return itr->second;
}


Customer Customer::withdrawal(){
    cout <<" For which customer you would like to withdraw? " << endl;
    int n;
    cin >> n;
    float total;
    cout << " How much would you like to withdraw : " << endl;
    cin >> total;
    map<int, Customer>::iterator itr = customerInformation.find(n);

    itr->second.balance -= total;

    return itr->second;
}

string Customer::getCustomerName(){
    return customerName;
}

float Customer::getBalance(){
    return balance;
}

string Customer::getCustomerLastName(){
    return customerLastName;
}
ofstream & operator << (ofstream &ofs, Customer &c){
    ofs << c.accountNumber << endl;
    ofs << c.customerName << endl;
    ofs << c.customerLastName<< endl;
    ofs << c.balance<< endl;
    return ofs;
}

ostream & operator << (ostream &ost, Customer &c){
    ost << "Account Number: " << c.accountNumber << endl;
    ost << "First Name : " << c.getCustomerName() << endl;
    ost << "Last Name: " <<c.getCustomerLastName() << endl;
    ost << "Balance : " <<c.getBalance() << endl;
    return ost;
}


ifstream & operator >>(ifstream &ifs, Customer &c){
    ifs >> c.customerName >> c.customerName >> c.balance;
    return ifs;
}
