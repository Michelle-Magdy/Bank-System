
#pragma once
#include <iostream>
#include <iomanip>
#include " clsInputValidate.h"
#include "clsBankClient.h"
#include "clsScreen.h"

class clsAddNewClientScreen:protected clsScreen {

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

	static void ShowAddNewClientScreen() {
        if (!CheckAccess(clsUser::enPermissions::pAddNewClient)) {

            return;
        }
        _DrawHeader("Add New Client:");

        cout << "enter Account number : \n";
        string AccountNumber = clsInputValidate::ReadString();

        while (clsBankClient::IsClientExists(AccountNumber)) {
            cout << "sorry the Client already Exists \n";
            AccountNumber = clsInputValidate::ReadString();
        }

        clsBankClient newClient = clsBankClient::AddNewClient(AccountNumber);

        ReadClientInfo(newClient);
        clsBankClient::enSuccess saved;
        saved = newClient.Save();


        switch (saved) {
        case clsBankClient::enSuccess::Succeded: {
            cout << "You Added the new client successfully!\n";
            cout << "-----------------------------------------\n";
            newClient.Print();
            break;
        }
        case clsBankClient::enSuccess::Failed: {
            cout << "there is an error adding the new client!\n";
            break;
        }
        }
	}


};