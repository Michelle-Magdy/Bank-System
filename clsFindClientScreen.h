#pragma once
#include <iostream>
#include "clsBankClient.h"
#include "clsScreen.h"
#include " clsInputValidate.h"

class clsFindClientScreen:protected clsScreen {

public:
	static void FindClient() {
        if (!CheckAccess(clsUser::enPermissions::pFindClient)) {

            return;
        }
        _DrawHeader("Find Client Screen");
        string AccountNumber;
        cout << "Enter the account number : ";
        AccountNumber = clsInputValidate::ReadString();

        while (!clsBankClient::IsClientExists(AccountNumber)) {
            cout << "\nClient Not Found ,Try again: ";
            AccountNumber = clsInputValidate::ReadString();
        }
        clsBankClient client = clsBankClient::Find(AccountNumber);
        client.Print();
	}
};