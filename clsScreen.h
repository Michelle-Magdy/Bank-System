//
// Created by Michelle on 9/10/2024.
//
#pragma once
#ifndef SYSTEM_BANK_CLSSCREEN_H
#define SYSTEM_BANK_CLSSCREEN_H

#endif //SYSTEM_BANK_CLSSCREEN_H

#include <iostream>
#include <iomanip>
#include "Global.h"
#include "clsBankUser.h"
#include "clsDate.h"
using namespace std;

class clsScreen{
protected:
    static void _DrawHeader(string title,string subtitle="") {
        cout << "User : " << CurrentUser.UserName;
        cout<<setw(26-CurrentUser.UserName.size())<<left<<"" << "---------------------------------------------\n";
        cout << "Date : " << clsDate::DateToString(clsDate()) << endl;
        cout << "-------------------------";
        cout<<"\n\t\t\t\t\t\t  "<<title;
        if (subtitle != "") {
            cout << "\n\t\t\t\t\t\t  " << subtitle;
        }
        cout<<"\n\n\t\t\t\t---------------------------------------------\n";
        
        
        
    }

    static bool CheckAccess(clsUser::enPermissions permission) {
        if (!CurrentUser.CheckAccess(permission)) {
            cout << "\t\t\t\t---------------------------------------------\n";
            cout << "\n\t\t\t\t  " << "  Access Denied Go Back To Your Admin";
            cout << "\n\n\t\t\t\t---------------------------------------------\n";
            return false;
        }
        return true;
    }
}; 

