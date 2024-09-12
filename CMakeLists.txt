cmake_minimum_required(VERSION 3.26)
project(System_Bank)

set(CMAKE_CXX_STANDARD 14)

add_executable(System_Bank
        main.cpp
        clsDate.h
        clsString.h
        clsUtil.h
        " clsInputValidate.h"
        clsPerson.h
        clsBankClient.h
        clsScreen.h
        clsMainMenu.h "clsClientListScreen.h" "clsAddNewClientScreen.h" "clsDeleteClientScreen.h" "clsUpdateClientScreen.h" "clsFindClientScreen.h" "clsTransactionScreen.h" "clsDepositeScreen.h" "clsWithDrawScreen.h" "clsTotalBalancesScreen.h" "clsManageUsersScreen.h" "clsBankUser.h" "clsListUsersScreen.h" "clsAddNewUserScreen.h" "clsDeleteUserScreen.h" "clsUpdateUserScreen.h" "clsFindUserScreen.h" "clsLoginPage.h" "Global.h" "clsLoginRecord.h" "clsTransferScreen.h"  "clsTransferLog.h")
