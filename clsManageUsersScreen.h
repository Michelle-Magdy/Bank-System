#pragma once
#include <iostream>
#include "clsBankClient.h"
#include "clsScreen.h"
#include " clsInputValidate.h"
#include "clsListUsersScreen.h"
#include "clsAddNewUserScreen.h"
#include "clsDeleteUserScreen.h"
#include "clsUpdateUserScreen.h"
#include "clsFindUserScreen.h"


class clsManageUsersScreen : protected clsScreen {

private:
    enum enOption {
        ListUsers=1,AddNewUser,DeleteUser,UpdateUser,FindUser,MainMenu
    };

    static void _ListUsers() {
        clsListUsersScreen::ShowUsersList();
    }

    static void _AddNewUser() {
        clsAddNewUserScreen::ShowAddNewUserScreen();
    }

    static void _DeleteUser() {
        clsDeleteUserScreen::ShowDeleteUserScreen();
    }

    static void _UpdateUser() {
        clsUpdateUserScreen::ShowUpdateUserScreen();
    }
    
    static void _FindUser() {
        clsFindUserScreen::ShowFindUserScreen();
    }
    static void _GoBackToManageUserScreen() {
        cout << "press any key to go back to Manage users screen...\n";
        char c;
        cin >> c;
        system("cls");
        ShowManageUsersScreen();
    }

    static int _ReadManageUsersScreenOption() {
        cout << setw(37) << left << "" << "Choose what do you want to do? [1 to 6]? ";
        int Choice = clsInputValidate::ReadIntNumberBetween(1, 6, "Enter Number between 1 to 8? ");
        return Choice;
    }

    static void _PreformOperation(enOption option) {
        switch (option) {
        case enOption::ListUsers: {
            system("cls");
            _ListUsers();
            _GoBackToManageUserScreen();
            break;
        }
        case enOption::AddNewUser: {
            system("cls");
            _AddNewUser();
            _GoBackToManageUserScreen();
            break;
        }
        case enOption::DeleteUser: {
            system("cls");
            _DeleteUser();
            _GoBackToManageUserScreen();
            break;
        }
        case enOption::UpdateUser: {
            system("cls");
            _UpdateUser();
            _GoBackToManageUserScreen();
            break;
        }
        case enOption::FindUser: {
            system("cls");
            _FindUser();
            _GoBackToManageUserScreen();
            break;
        }
        case enOption::MainMenu: {
            break;
        }
        }
    }
public:
	static void ShowManageUsersScreen() {
        if (!CheckAccess(clsUser::enPermissions::pManageUsers)) {

            return;
        }
		_DrawHeader("Manage Users");
        short width = 33;
        cout << setw(width) << left << "" << "=============================================\n";
        cout << setw(width) << left << "" << "\t\t   Manage Users\n";
        cout << setw(width) << left << "" << "=============================================\n";
        cout << setw(width) << left << "" << " [1] List Users\n";
        cout << setw(width) << left << "" << " [2] Add New user\n";
        cout << setw(width) << left << "" << " [3] Delete User\n";
        cout << setw(width) << left << "" << " [4] Update user\n";
        cout << setw(width) << left << "" << " [5] Find user\n";
        cout << setw(width) << left << "" << " [6] Main Menu\n";

        _PreformOperation((enOption)_ReadManageUsersScreenOption());

	}
};