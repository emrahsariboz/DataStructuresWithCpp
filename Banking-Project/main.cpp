#include "account.h"

int main()
{       


    int option = 0;
    account bank;
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
        {
                bank.createAccount();
                break;
        }
            case 2: // code to be executed if n = 2;
                bank.getBalance();
                break;
            case 3:
                bank.deposit();
            break;
            case 4:
                bank.withdrawal();
            break;
            case 6:
                bank.readFromFile(bank);
            break;
            case 7:
                cout<<"Thanks for working with us! See you soon!\n";
            break;
        }
        bank.writeToFile(bank);
    }
    return 0;
}
