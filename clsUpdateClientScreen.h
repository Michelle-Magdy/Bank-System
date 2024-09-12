
#pragma once

#include <iostream>
#include "clsBankClient.h"
#include "clsScreen.h"
#include " clsInputValidate.h"

class clsUpdateClientScreen:protected clsScreen {
private:
    static void ReadClientInfo(clsBankClient& client) {
        cout << "\nEnter First Name : ";
        client.SetFirstName(clsInputValidate::ReadString());
        cout << "\nEnter Second Name : ";
        client.SetSecondName(clsInputValidate::ReadString());
        cout << "\nEnter Email : ";
        client.SetEmail(clsInputValidate::ReadString());
        cout << "\nEnter Phone Number : ";
        client.SetPhoneNumber(clsInputValidate::ReadString());
        cout << "\nEnter PIN code : ";
        client.SetPINCode(clsInputValidate::ReadString());
        cout << "\nEnter Balance : ";
        client.SetBalance(clsInputValidate::ReadDblNumber());
    }

public:

    static void UpdateClientInfo() {
        if (!CheckAccess(clsUser::enPermissions::pUpdateClients)) {

            return;
        }
        _DrawHeader("Update Client Info");
        string AccountNumber;
        cout << "Enter the account number : ";
        AccountNumber = clsInputValidate::ReadString();

        while (!clsBankClient::IsClientExists(AccountNumber)) {
            cout << "\nClient Not Found ,Try again: ";
            AccountNumber = clsInputValidate::ReadString();
        }
        clsBankClient client = clsBankClient::Find(AccountNumber);
        client.Print();

        cout << "update info : \n";
        cout << "---------------------------\n";

        ReadClientInfo(client);
        clsBankClient::enSuccess saved;
        saved = client.Save();
        switch (saved) {
        case clsBankClient::enSuccess::Succeded: {
            cout << "Client Updated successfully!\n";
            client.Print();
            break;
        }
        case clsBankClient::enSuccess::Failed: {
            cout << "Client Failed to Update!\n";
            break;
        }
        }


    }
};

