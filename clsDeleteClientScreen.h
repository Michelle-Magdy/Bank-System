#pragma once
#include <iostream>
#include <iomanip>
#include " clsInputValidate.h"
#include "clsBankClient.h"
#include "clsScreen.h"

class clsDeleteClientScreen:protected clsScreen{
private:

public:
	static void DeleteClient() {
        if (!CheckAccess(clsUser::enPermissions::pDeleteClient)) {

            return;
        }
        _DrawHeader("Delete Client:");

        string AccountNumber;
        cout << "Enter the account number : ";
        AccountNumber = clsInputValidate::ReadString();

        while (!clsBankClient::IsClientExists(AccountNumber)) {
            cout << "\nClient Not Found ,Try again: ";
            AccountNumber = clsInputValidate::ReadString();
        }

        clsBankClient client = clsBankClient::Find(AccountNumber);
        client.Print();

        cout << "Are you sure you want to delete (y/n) ? ";
        char Answer ;
        Answer = clsInputValidate::ReadChar();
        while (Answer != 'y' && Answer != 'n') {
            cout << "invalid input enter (y/n)\n";
            Answer = clsInputValidate::ReadChar();
        }
        if (Answer == 'y' || Answer == 'Y') {
            if (client.Delete()) {
                cout << "client with account number " << AccountNumber << " is deleted successfully!\n";
            }
            else {
                cout << "Okay , Client isn't deleted\n";
            }
        }

	}
};