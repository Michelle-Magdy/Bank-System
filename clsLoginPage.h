#pragma once
#include <iostream>
#include <fstream>
#include "clsBankUser.h"
#include "clsScreen.h"
#include "Global.h"
#include " clsInputValidate.h"
#include "clsMainMenu.h"

using namespace std;

class clsLoginPage:protected clsScreen {

private:
	static bool _Login() {
		bool LoginFailed = false;
		short counter = 0;
		do {
			if (LoginFailed) {
				counter++;
				cout << "\nuser not found \n";
				cout << "You Have " << 3 - counter << " Trials...\n\n";
			}

			if (counter == 3) {
				return false;
			}
			cout << "enter user name : ";
			string userName = clsInputValidate::ReadString();
			cout << "enter password : ";
			string password = clsInputValidate::ReadString();
			CurrentUser = clsUser::Find(userName, password);

			LoginFailed = CurrentUser.IsEmpty();
		} while (LoginFailed && counter <= 3);
		CurrentUser.RegisterLogin();
		clsMainMenu::ShowMainMenu();
		
		return true;
	}
	
public:
	static bool ShowLoginPage() {
		system("cls");
		_DrawHeader("Log in");
		return _Login();

	}
};