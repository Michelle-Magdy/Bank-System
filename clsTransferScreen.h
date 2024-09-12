#pragma once
#include <iostream>
#include "clsBankClient.h"
#include "clsScreen.h"
#include " clsInputValidate.h"

using namespace std;

class clsTransfer:protected clsScreen {
private:
	static void _PrintClient(clsBankClient client) {
		cout << "\nClient Card : \n";
		cout << "------------------------------------------\n";
		cout << "Full Name    : " << client.FullName() << endl;
		cout << "Account Name : " << client.GetAccountNumber() << endl;
		cout << "Balance      : " << client.GetBalance() << endl;
		cout << "------------------------------------------\n\n";
	}

public:
	static void ShowTransferScreen() {
		_DrawHeader("Transfer");
		string FromAcc, ToAcc;
		clsBankClient clientFrom = clsBankClient::Find("",""),clientTo = clsBankClient::Find("", "");
		
		while (clientFrom.IsEmpty()) {
			cout << "\nenter the account number you want to send money From : ";
			FromAcc = clsInputValidate::ReadString();
			clientFrom = clsBankClient::Find(FromAcc);
			if (clientFrom.IsEmpty()) cout << "Client Not Found!\n";
		}
		_PrintClient(clientFrom);
		bool sameClient = true;
		cout << "\nenter the account number you want to send money To : ";
		while (clientTo.IsEmpty()|| sameClient) {
			sameClient = true;
			ToAcc = clsInputValidate::ReadString();
			clientTo = clsBankClient::Find(ToAcc);
			if (clientTo.IsEmpty()) cout << "\nClient Not Found!\nenter the account number you want to send money To : ";
			if (clientFrom.GetAccountNumber() != clientTo.GetAccountNumber()) sameClient = false;
			else {
				cout << "\nYou can't transfer money to the same client \n";
				cout << "please enter different account number you want to send money To : ";
			}
		}
		_PrintClient(clientTo);

		cout << "How much money do you want to transfer? ";
		double amount = clsInputValidate::ReadDblNumber();
		while (clientFrom.GetBalance() - amount < 0) {
			cout << "Amount exceeds the available balance , enter another amount : ";
			amount = clsInputValidate::ReadDblNumber();
		}
		
		cout << "\nAre you sure you want to complete the transfer ? (y/n)";
		char answer;
		cin >> answer;
		if(answer == 'y' ||answer == 'Y')
		{
			clientFrom.Transfer(amount, clientTo);
			cout << "\n\nTransfer completed!\n";
			_PrintClient(clientFrom);
			_PrintClient(clientTo);
		}
	}
};