//
// Created by Michelle on 9/10/2024.
//
#pragma once
#ifndef SYSTEM_BANK_CLSMAINMENU_H
#define SYSTEM_BANK_CLSMAINMENU_H

#endif //SYSTEM_BANK_CLSMAINMENU_H

#include <iostream>
#include <iomanip>
#include "clsScreen.h"
#include " clsInputValidate.h"
#include "clsClientListScreen.h"
#include "clsAddNewClientScreen.h"
#include "clsDeleteClientScreen.h"
#include "clsUpdateClientScreen.h"
#include "clsFindClientScreen.h"
#include "clsTransactionScreen.h"
#include "clsManageUsersScreen.h"
#include "clsLoginRecord.h"
#include "Global.h"

using namespace std;

class clsMainMenu : protected clsScreen {
private:
    enum enOption {
        ShowClientList = 1,
        AddNewClient = 2,
        DeleteClient = 3,
        UpdateClient = 4,
        FindClient = 5,
        Transactions = 6,
        ManageUsers = 7,
        LogInRecords=8,
        LogOut = 9
    };
    static enOption _option;

    static void _ShowClientListpg() {
        clsClientListScreen::ShowClientList();
    }

    static void _AddNewClientpg() {
        clsAddNewClientScreen::ShowAddNewClientScreen();
    }

    static void _DeleteClientpg() {
        clsDeleteClientScreen::DeleteClient();
    }

    static void _UpdateClientpg() {
        clsUpdateClientScreen::UpdateClientInfo();
    }

    static void _FindClientpg() {
        clsFindClientScreen::FindClient();
    }

    static void _Transactionspg() {
        clsTransactionScreen::ShowTransactionMenu();
    }

    static void _ManageUserspg() {
        clsManageUsersScreen::ShowManageUsersScreen();
    }

    static void _LogInRecord() {
        clsLogInRecord::ShowRecords();
    }

    static void _LogOutpg() {
        CurrentUser = clsUser::Find("", "");
    }

    static void _GoBackToMainMenu() {
        cout << setw(37) << left << "" << "\n\tPress any key to go back to Main Menu...\n";
        char c;
        cin>>c;
        ShowMainMenu();
    }

    static int _ReadMainMenuOption() {
        cout << setw(37) << left << "" << "Choose what do you want to do? [1 to 9]? ";
        int Choice = clsInputValidate::ReadIntNumberBetween(1, 9, "Enter Number between 1 to 9? ");
        return Choice;
    }

    static void _PreformOption(enOption option) {
        switch (option) {
            case enOption::ShowClientList: {
                system("cls");
                _ShowClientListpg();
                _GoBackToMainMenu();
                break;
            }
            case enOption::AddNewClient: {
                system("cls");
                _AddNewClientpg();
                _GoBackToMainMenu();
                break;
            }
            case enOption::DeleteClient: {
                system("cls");
                _DeleteClientpg();
                _GoBackToMainMenu();
                break;
            }
            case enOption::UpdateClient: {
                system("cls");
                _UpdateClientpg();
                _GoBackToMainMenu();
                break;
            }
            case enOption::FindClient: {
                system("cls");
                _FindClientpg();
                _GoBackToMainMenu();
                break;
            }
            case enOption::Transactions: {
                system("cls");
                _Transactionspg();
                _GoBackToMainMenu();
                break;
            }
            case enOption::ManageUsers: {
                system("cls");
                _ManageUserspg();
                _GoBackToMainMenu();
                break;
            }
            case enOption::LogInRecords: {
                system("cls");
                _LogInRecord();
                _GoBackToMainMenu();
                break;
            }
            case enOption::LogOut: {
                system("cls");
                _LogOutpg();
                break;
            }
        }
    }

public:
    static void ShowMainMenu() {
        system("cls");
        _DrawHeader("Main Menu");
        short width = 33;
        cout << setw(width) << left << "" << "=============================================\n";
        cout << setw(width) << left << "" << "\t\t   Main Menu\n";
        cout << setw(width) << left << "" << "=============================================\n";
        cout << setw(width) << left << "" << " [1] Show Client List\n";
        cout << setw(width) << left << "" << " [2] Add New Client\n";
        cout << setw(width) << left << "" << " [3] Delete Client\n";
        cout << setw(width) << left << "" << " [4] Update Client\n";
        cout << setw(width) << left << "" << " [5] Find Client\n";
        cout << setw(width) << left << "" << " [6] Transactions\n";
        cout << setw(width) << left << "" << " [7] Manage Users\n";
        cout << setw(width) << left << "" << " [8] Login Records\n";
        cout << setw(width) << left << "" << " [9] Log out\n";
        cout << setw(width) << left << "" << "=============================================\n";

        _PreformOption(static_cast<enOption>(_ReadMainMenuOption()));
    }
};