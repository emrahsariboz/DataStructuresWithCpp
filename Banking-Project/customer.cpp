#include "customer.h"
int Customer::nextAccountNumber = 0;

Customer::Customer()
{	
	 //If file empty, this is initial account number
	 accountNumber = 0;
}
Customer::Customer(string name, string LastName, float balance){

        this->balance = balance;
        customerName = name;
        customerLastName = LastName;
        accountNumber = getLastId();
        accountNumber++;
}

void Customer::createAccount(Customer c){
    ofstream ofs;
    cout << endl;
    customerInformation.insert(pair<int, Customer>(c.accountNumber, c));

    ofstream ofc("BankingInformation.txt", ios::app);

    map<int, Customer>::iterator itr;

    for (itr = customerInformation.begin(); itr != customerInformation.end(); ++itr) {

            ofc<< itr -> second <<" ";
    }

    //customerInformation.empty();
    ofc.close();
}


Customer Customer::balanceInquery(){
    getAccounts();
    cout <<" For which customer you would like to get Balance Information? " << endl;
    int n;
    cin >> n;
    map<int, Customer>::iterator itr = customerInformation.find(n);
    return itr -> second;
}

void Customer::deposit(){
    getAccounts();
    cout <<" For which customer you would like to deposit? " << endl;
    int n;
    cin >> n;
    float total;
    cout << " How much would you like to deposit : " << endl;
    cin >> total;
    map<int, Customer>::iterator itr = customerInformation.find(n);

    itr->second.balance += total;
    cout << itr->second << endl;
}


Customer Customer::withdrawal(){
    getAccounts();
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

int Customer::getAccountNumber(){
    return accountNumber;
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
    ost << "Account Number: " << c.getAccountNumber() << endl;
    ost << "First Name : " << c.getCustomerName() << endl;
    ost << "Last Name: " <<c.getCustomerLastName() << endl;
    ost << "Balance : " <<c.getBalance() << endl;
    return ost;
}

ifstream & operator >>(ifstream &ifs, Customer &c){
    ifs >> c.accountNumber >> c.customerName >> c.customerLastName >> c.balance;
    return ifs;
}

int Customer::getLastId(){
    //Return the last id from the file.
    Customer c;
    ifstream ifs;
    ifs.open("BankingInformation.txt");
        while(!ifs.eof()){
            ifs >> c;
        }
        ifs.close();
            lastAccountNumber = c.getAccountNumber();
            cout << "last " << lastAccountNumber << endl;
        return lastAccountNumber;
}
void Customer::getAccounts(){
    //Loads all the accounts to the Map
    Customer c;
    ifstream ifs;
    ifs.open("BankingInformation.txt");

    while(!ifs.eof()){
        ifs >> c;
        customerInformation.insert(pair<int, Customer>(c.accountNumber, c));
    }
    ifs.close();
}


void Customer::closeAccount(){
    getAccounts();
    Customer c;
    cout <<" Which customer should be removed? " << endl;
    int n;
    cin >> n;

    customerInformation.erase(n);

    //After deleting the user, overriding the new txt file with the Map.
    cout << "Customer with the following id has been removed : " << n <<endl;

    map<int, Customer>::iterator itr;
    ofstream newFile("BankingInformation.txt", ios::out);
    for (itr = customerInformation.begin(); itr != customerInformation.end(); ++itr) {
            newFile<< itr -> second <<endl;
    }
    newFile.close();
}

void Customer::readAllAccount(){
   getAccounts();
   map<int, Customer>::iterator itr;

   for (itr = customerInformation.begin(); itr != customerInformation.end(); ++itr) {

           cout<< itr -> first << " " << itr -> second <<endl;
   }
}
