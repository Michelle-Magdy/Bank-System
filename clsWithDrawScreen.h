#pragma once
#include <iostream>
#include "clsBankClient.h"
#include " clsInputValidate.h"
#include "clsScreen.h"

using namespace std;

class clsWithdrawScreen :protected clsScreen {

private:
    static string _ReadAccountNumber() {
        string AccountNumber;
        cout << "Enter the account number : ";
        AccountNumber = clsInputValidate::ReadString();

        while (!clsBankClient::IsClientExists(AccountNumber)) {
            cout << "\nClient Not Found ,Try again: ";
            AccountNumber = clsInputValidate::ReadString();
        }
        return AccountNumber;
    }

public:
    static void WithdrawScreen() {
        _DrawHeader("Withdraw");

        clsBankClient client = clsBankClient::Find(_ReadAccountNumber());
        client.Print();

        cout << "enter the amount of money you want to withdraw :\n";
        double amount = clsInputValidate::ReadDblNumber();

        cout << "are you sure you want to withdraw " << amount << " in your bank account ?\n";
        char c = clsInputValidate::ReadChar();
        if (c == 'y' || c == 'Y') {
            client.Withdraw(amount);
            cout << amount << " is withdrawn successfully!\n";
            cout << "account Balance = " << client.GetBalance() << endl;
        }
        else {
            cout << "operation is canceled!\n";
        }

    }
};