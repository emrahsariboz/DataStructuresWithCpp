#include <QCoreApplication>

#include <iostream>
#include <customer.h>


Customer bank;
Customer holder;
int main()
{
    string customerName,customerLastName;
    float balance;

    int option = 0;
    while (option != 7) {
        cout << "Select one option below:\n"
                        "1) Open an account\n"
                        "2) Balance Enquiry\n"
                        "3) Deposit\n"
                        "4) Withdrawal\n"
                        "5) Close an account\n"
                        "6) Show all account\n"
                        "7) Quit\n";
        cin >> option;

        switch (option)
        {
           case 1:
                bank.createAccount();
                break;
            case 2: // code to be executed if n = 2;
                holder = bank.balanceInquery();
                cout << holder;
                break;
            case 3:
                holder = bank.deposit();
                cout << holder;
                break;
            case 4:
                holder = bank.withdrawal();
                cout <<holder;
                break;
            case 5:
                //bank.closeAccount();
                break;
            case 6:
                //bank.readFromFile();
                break;
            case 7:
                cout<<"Thanks for working with us! See you soon!\n";
                break;
        }
    }
    return 0;
}
