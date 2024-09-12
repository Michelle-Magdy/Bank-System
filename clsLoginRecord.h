#pragma once
#include <iostream>
#include <fstream>
#include <iomanip>
#include "clsScreen.h"
#include "clsBankUser.h"

class clsLogInRecord:protected clsScreen {
private:
	static void _PrintUserRecordLine(clsUser::LoginRecord user) {
		cout << "|" << left << setw(26) << user.DateTime;
		cout << "|" << left << setw(26) << user.UserName;
		cout << "|" << left << setw(26) << user.Password;
		cout << "|" << left << setw(26) << user.Permissions;
	}
public:
	static void ShowRecords() {
		if (!CheckAccess(clsUser::enPermissions::pLoginRecords)) {

			return;
		}
		vector<clsUser::LoginRecord> users = clsUser::GetUserLoginRecord();
		_DrawHeader("Login Records");

		cout << "---------------------------------------------------------------------------------------------\n";
		cout << "|" << left << setw(26) << " Date/Time";
		cout << "|" << left << setw(26) << " User Name";
		cout << "|" << left << setw(26) << " Password";
		cout << "|" << left << setw(26) << " Permissions";
		cout << "\n---------------------------------------------------------------------------------------------\n";
		for (auto user : users)
		{
			_PrintUserRecordLine(user);
			cout << endl;
		}
		
	}
};