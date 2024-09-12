#pragma once
#include <iostream>
#include "clsBankUser.h"
#include "clsScreen.h"
#include " clsInputValidate.h"

using namespace std;

class clsListUsersScreen:protected clsScreen {
private:
    static void _PrintUserRecordLine(clsUser user) {
        cout << "|" << left << setw(20) << user.FullName();
        cout << "|" << left << setw(20) << user.GetPhoneNumber();
        cout << "|" << left << setw(20) << user.GetEmail();
        cout << "|" << left << setw(20) << user.GetPassword();
        cout << "|" << left << setw(20) << user.GetPermissions();
    }

public:
    static void ShowUsersList() {
        vector<clsUser> users = clsUser::GetUsersList();
        string subtitle = "(" + to_string(users.size()) + ')' + " Users";
        _DrawHeader("User List", subtitle);

        cout << "---------------------------------------------------------------------------------------------\n";
        cout << "|" << left << setw(20) << " Full Name";
        cout << "|" << left << setw(20) << " Phone Number";
        cout << "|" << left << setw(20) << " Email";
        cout << "|" << left << setw(20) << " Password";
        cout << "|" << left << setw(20) << " Permissions";
        cout << "\n---------------------------------------------------------------------------------------------\n";

        if (users.empty()) {
            cout << "There are no Users\n";
        }
        else {
            for (auto& user : users) {
                _PrintUserRecordLine(user);
                cout << "\n";
            }
        }
        cout << "---------------------------------------------------------------------------------------------\n";

    }
};