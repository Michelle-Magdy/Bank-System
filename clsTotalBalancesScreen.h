#pragma once
#include <iostream>
#include <iomanip>
#include "clsBankClient.h"
#include "clsScreen.h"
#include " clsInputValidate.h"

using namespace std;

class clsTotalBalancesScreen:protected clsScreen {

public:
	static void ShowTotalBalances() {
        vector<clsBankClient> clients = clsBankClient::GetClientsList();
        string subtitle = "(" + to_string(clients.size()) + ')' + " clients";
        _DrawHeader("Client List", subtitle);

        cout << "---------------------------------------------------------------------------------------------\n";
        cout << "|" << left << setw(20) << " Account Number";
        cout << "|" << left << setw(20) << " Client Name";
        cout << "|" << left << setw(20) << " Balance";
        cout << "\n---------------------------------------------------------------------------------------------\n";

        if (clients.empty()) {
            cout << "There are no Clients\n";
        }
        else {
            for (auto& client : clients) {
                clsBankClient::ShowTotalBalances(client);
                cout << "\n";
            }
        }
        cout << "\n\t\t\t\t\t Total Balances = " << clsBankClient::TotalBalances();
        cout << "\n\t\t\t\t\t( " << clsBankClient::TotalBalancesInText() << ")" << endl;
        cout << "---------------------------------------------------------------------------------------------\n";
	}
};