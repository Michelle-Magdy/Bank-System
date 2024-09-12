

#pragma once
#ifndef SYSTEM_BANK_CLSCLIENTLISTSCREEN_H
#define SYSTEM_BANK_CLSCLIENTLISTSCREEN_H

#endif //SYSTEM_BANK_CLSCLIENTLISTSCREEN_H
#include <iostream>
#include <iomanip>
#include "clsBankClient.h"
#include "clsScreen.h"

using namespace std;

class clsClientListScreen :protected clsScreen {

public:
	static void ShowClientList() {
        if (!CheckAccess(clsUser::enPermissions::pListClients)) {

            return;
        }
        vector<clsBankClient> clients = clsBankClient::GetClientsList();
        string subtitle = "(" + to_string(clients.size()) + ')' + " clients";
        _DrawHeader("Client List",subtitle);

        cout << "---------------------------------------------------------------------------------------------\n";
        cout << "|" << left << setw(20) << " Account Number";
        cout << "|" << left << setw(20) << " Client Name";
        cout << "|" << left << setw(20) << " Phone Number";
        cout << "|" << left << setw(20) << " Email";
        cout << "|" << left << setw(20) << " Balance";
        cout << "\n---------------------------------------------------------------------------------------------\n";

        if (clients.empty()) {
            cout << "There are no Clients\n";
        }
        else {
            for (auto& client : clients) {
                clsBankClient::ConvertClientToLine(client);
                cout << "\n";
            }
        }
        cout << "---------------------------------------------------------------------------------------------\n";

	}

};