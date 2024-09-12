
#pragma once
#include <iostream>
#include <iomanip>
#include "clsBankClient.h"
#include "clsScreen.h"
#include " clsInputValidate.h"
#include "clsMainMenu.h"
#include "clsDepositeScreen.h"
#include "clsWithDrawScreen.h"
#include "clsTotalBalancesScreen.h"
#include "clsTransferScreen.h"
#include "clsTransferLog.h"
using namespace std;


class clsTransactionScreen: protected clsScreen {
	
private:
	enum Option {
		Deposite=1,Withdraw,TotalBalances,Transfer,TransferLog,MainMenu
	};
	static short _ReadOption() {
		cout << setw(33) << left << "" << "choose the operation (1/6)\n";
		short choice = clsInputValidate::ReadShortNumberBetween(1, 6);
		return choice;
	}

	static void _BackToTransactionMenu() {
		cout << setw(33) << "press any key to go back to Transaction Menu\n";
		char c;
		c = clsInputValidate::ReadChar();
		system("cls");
		ShowTransactionMenu();
	}

	static void _Deposite() {
		clsDepositeScreen::DepositeScreen();
	}

	static void _Withdraw() {
		clsWithdrawScreen::WithdrawScreen();
	}

	static void _TotalBalances() {
		clsTotalBalancesScreen::ShowTotalBalances();
	}
	
	static void _Transfer() {
		clsTransfer::ShowTransferScreen();
	}

	static void _TransferLog() {
		clsTransferLog::ShowTransferLog();
	}

	static void _MainMenu() {
		cout << "Press any key to go back to Main Menu...\n";
		char c;
		c = clsInputValidate::ReadChar();
	}

	static void _PreformOperation(Option option) {
		switch (option) {
		case Option::Deposite: {
			system("cls");
			_Deposite();
			_BackToTransactionMenu();
			break;
		}
		case Option::Withdraw: {
			system("cls");
			_Withdraw();
			_BackToTransactionMenu();
			break;
		}
		case Option::TotalBalances: {
			system("cls");
			_TotalBalances();
			_BackToTransactionMenu();
			break;
		}
		case Option::Transfer: {
			system("cls");
			_Transfer();
			_BackToTransactionMenu();
			break;
		}
		case Option::TransferLog: {
			system("cls");
			_TransferLog();
			_BackToTransactionMenu();
			break;
		}
		case Option::MainMenu: {
			system("cls");
			break;
		}
		}
	}

public:
	static void ShowTransactionMenu() {
		if (!CheckAccess(clsUser::enPermissions::pTranactions)) {

			return;
		}
		_DrawHeader("Transaction Menu");
		short w = 33;
		cout << setw(w) << left << "" << "[1] Deposite\n";
		cout << setw(w) << left << "" << "[2] Withdraw\n";
		cout << setw(w) << left << "" << "[3] Total Balances\n";
		cout << setw(w) << left << "" << "[4] Transfer\n";
		cout << setw(w) << left << "" << "[5] Transfer Logs\n";
		cout << setw(w) << left << "" << "[6] Main Menu\n";
		_PreformOperation((Option)_ReadOption());
	}
};