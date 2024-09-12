
#pragma once
#include <iostream>
#include "clsBankClient.h"
#include "clsScreen.h"

using namespace std;

class clsTransferLog:protected clsScreen {

private:
	static void _PrintTransferLogLine(clsBankClient::stTransferLog trans) {
		clsBankClient::ConvertTransferLogToLine(trans);
	}
public:
	static void ShowTransferLog() {
		_DrawHeader("Transfer Log");
		short w = 15;
		cout << "\n-------------------------------------------------------------------------------------------------------------------------\n";
		cout << "| " << left << setw(21) << "Date/Time";
		cout << "| " << left << setw(w)  << "Client 1";
		cout << "| " << left << setw(w) <<"Client 2";
		cout << "| " << left << setw(w) << "Amount";
		cout << "| " << left << setw(w) << "C1 Balance";
		cout << "| " << left << setw(w) << "C2 Balance";
		cout << "| " << left << setw(w) << "User";
		cout << "\n-------------------------------------------------------------------------------------------------------------------------\n";

		vector<clsBankClient::stTransferLog> transferes = clsBankClient::ConvertFileTransferLogsToVector();

		if (transferes.empty()) {
			cout << "There is NO Transfers to show\n";
			return;
		}
		for (auto trans : transferes) {
			_PrintTransferLogLine(trans);
			cout << endl;
		}
		cout << "\n-------------------------------------------------------------------------------------------------------------------------\n";
	}

};
