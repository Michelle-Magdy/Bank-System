//
// Created by Michelle on 9/8/2024.
//
#pragma once

#ifndef SYSTEM_BANK_CLSBANKCLIENT_H
#define SYSTEM_BANK_CLSBANKCLIENT_H

#endif //SYSTEM_BANK_CLSBANKCLIENT_H

#include <iostream>
#include <vector>
#include <fstream>
#include <iomanip>
#include "clsUtil.h"
#include "clsPerson.h"
#include "clsString.h"
#include "clsDate.h"
#include "Global.h"

using namespace std;

class clsBankClient : public clsPerson {
private:
    enum enMode {
        EmptyMode = 0, UpdateMode = 1, AddMode = 2, DeleteMode = 3
    };
    enMode _mode;
    string _accountNumber, _pinCode;
    double _balance;


    static clsBankClient _ConvertLineIntoObject(string line, string delimiter = "#//#") {
        vector<string> data = clsString::Split(line, delimiter);
        clsBankClient client(enMode::UpdateMode, data[0], data[1], data[2], data[3], data[4], data[5], stod(data[6]));

        return client;
    }

    static string _ConvertObjectIntoLine(clsBankClient client, string separator = "#//#") {
        string line = client.GetFirstName() + separator + client.GetSecondName() + separator
                      + client.GetEmail() + separator + client.GetPhoneNumber() + separator +
                      client.GetAccountNumber() +
                      separator + client.GetPINCode() + separator + to_string(client.GetBalance());
        return line;
    }

    struct stTransferLog;
    static stTransferLog _ConvertClientsToTransferLog(clsBankClient client1, clsBankClient client2,double Amount) {
        stTransferLog t;
        t.DateTime = clsDate::GetDateTimeString();
        t.Client1AccNo = client1.GetAccountNumber();
        t.Client2AccNo = client2.GetAccountNumber();
        t.Amount = Amount;
        t.Client1Balance = client1.GetBalance();
        t.Client2Balance = client2.GetBalance();
        t.user = CurrentUser.UserName;
        return t;
    }

    static string _ConvertTransferLogToString(stTransferLog t,string sp = "#//#") {
        string line = t.DateTime + sp + t.Client1AccNo + sp + t.Client2AccNo + sp + to_string(t.Amount) + sp + to_string(t.Client1Balance) + sp + to_string(t.Client2Balance) + sp + t.user;
        return line;
    }

    static stTransferLog _ConvertStringToTransferLog(string line, string sp = "#//#") {
        vector<string> Trans = clsString::Split(line, sp);
        stTransferLog t;
        t.DateTime = Trans[0];
        t.Client1AccNo = Trans[1];
        t.Client2AccNo = Trans[2];
        t.Amount = stod(Trans[3]);
        t.Client1Balance = stod(Trans[4]);
        t.Client2Balance = stod(Trans[5]);
        t.user = Trans[6];
        return t;
    }

    
    static clsBankClient _GetEmptyClient() {
        return clsBankClient(enMode::EmptyMode, "", "", "", "", "", "", 0);
    }

    static vector<clsBankClient> _LoadClientDataFromFile() {
        vector<clsBankClient> vClient;
        fstream file;
        file.open("D:\\C++ projects\\OOP projects\\System Bank\\Clients.txt", ios::in);

        if (file.is_open()) {
            string line;

            while (getline(file, line)) {
                clsBankClient client = _ConvertLineIntoObject(line);
                vClient.push_back(client);
            }
        }
        return vClient;
    }

    static void _SaveClientDataToFile(vector<clsBankClient> Data) {
        fstream file;
        file.open("D:\\C++ projects\\OOP projects\\System Bank\\Clients.txt", ios::out);

        if (file.is_open()) {
            for (auto member: Data) {
                if (member._mode != enMode::DeleteMode && member._mode != enMode::EmptyMode) {
                    string line = _ConvertObjectIntoLine(member);
                    file << line << endl;
                }
            }

            file.close();
        }
    }

    void _Update() {
        vector<clsBankClient> clients = _LoadClientDataFromFile();

        for (auto &client: clients) {
            if (client.GetAccountNumber() == GetAccountNumber()) {
                client = *this;
                break;
            }
        }

        _SaveClientDataToFile(clients);
    }

    void _Save() {
        vector<clsBankClient> clients = _LoadClientDataFromFile();
        clients.push_back(*this);
        _SaveClientDataToFile(clients);
    }

public:
    clsBankClient(enMode Mode, string FirstName, string SecondName, string Email, string PhoneNumber,
                  string AccountNumber, string PinCode, double Balance) :
            clsPerson(FirstName, SecondName, Email, PhoneNumber) {
        _mode = Mode;
        _accountNumber = AccountNumber;
        _pinCode = PinCode;
        _balance = Balance;
    }

    bool IsEmpty() {
        return _mode == enMode::EmptyMode;
    }

    // account Number
    void SetAccountNumber(string AccountNumber) {
        _accountNumber = AccountNumber;
    }

    string GetAccountNumber() {
        return _accountNumber;
    }

    // PIN Code
    void SetPINCode(string PINCode) {
        _pinCode = PINCode;
    }

    string GetPINCode() {
        return _pinCode;
    }

    // Balance
    void SetBalance(double balance) {
        _balance = balance;
    }

    double GetBalance() {
        return _balance;
    }

    static clsBankClient Find(string AccountNumber) {
        fstream file;
        file.open("D:\\C++ projects\\OOP projects\\System Bank\\Clients.txt", ios::in);
        if (file.is_open()) {
            string line;

            while (getline(file, line)) {
                clsBankClient client = _ConvertLineIntoObject(line);
                if (client.GetAccountNumber() == AccountNumber) {
                    return client;
                }
            }
            file.close();
        }
        return _GetEmptyClient();
    }

    static clsBankClient Find(string AccountNumber, string PINCode) {
        fstream file;
        file.open("D:\\C++ projects\\OOP projects\\System Bank\\Clients.txt", ios::in);
        if (file.is_open()) {
            string line;

            while (getline(file, line)) {
                clsBankClient client = _ConvertLineIntoObject(line);
                if (client.GetAccountNumber() == AccountNumber && client.GetPINCode() == PINCode) {
                    return client;
                }
            }
            file.close();
        }
        return _GetEmptyClient();
    }

    static bool IsClientExists(string AccountNumber) {
        clsBankClient client = clsBankClient::Find(AccountNumber);
        return !client.IsEmpty();
    }

    enum enSuccess {
        Failed, Succeded
    };

    enSuccess Save() {
        switch (_mode) {
            case enMode::EmptyMode: {
                return enSuccess::Failed;
                break;
            }
            case enMode::UpdateMode: {
                _Update();
                return enSuccess::Succeded;
                break;
            }
            case enMode::AddMode: {
                _Save();
                return enSuccess::Succeded;
                break;
            }
            case enMode::DeleteMode:
                return enSuccess::Succeded;
                break;
        }
    }

    static clsBankClient AddNewClient(string AccountNumber) {
        return clsBankClient(enMode::AddMode, "", "", "", "", AccountNumber, "", 0);
    }


    bool Delete() {
        vector<clsBankClient> clients = _LoadClientDataFromFile();
        for(auto& member:clients){
            if(member.GetAccountNumber() == GetAccountNumber()){
                member._mode=enMode::DeleteMode;
            }
        }
        _SaveClientDataToFile(clients);
        *this = _GetEmptyClient();
        return true;
    }

    static vector<clsBankClient> GetClientsList(){
        return _LoadClientDataFromFile();
    }

    static void ConvertClientToLine(clsBankClient client){
        cout<<"| "<<setw(19)<<left<<client.GetAccountNumber();
        cout<<"| "<<setw(19)<<left<<client.FullName();
        cout<<"| "<<setw(19)<<left<<client.GetPhoneNumber();
        cout<<"| "<<setw(19)<<left<<client.GetEmail();
        cout<<"| "<<setw(19)<<left<<client.GetBalance();
    }

    static void ShowTotalBalances(clsBankClient client) {
        cout << "| " << setw(19) << left << client.GetAccountNumber();
        cout << "| " << setw(19) << left << client.FullName();
        cout << "| " << setw(19) << left << client.GetBalance();
    }

    static void ConvertTransferLogToLine(stTransferLog t) {
        short w = 15;
        cout << "| " <<left<< setw(21)<< t.DateTime;
        cout << "| " << left << setw(w)  << t.Client1AccNo;
        cout << "| " << left << setw(w) << t.Client2AccNo;
        cout << "| " << left << setw(w) << t.Amount;
        cout << "| " << left << setw(w)  << t.Client1Balance;
        cout << "| " << left << setw(w)  << t.Client2Balance;
        cout << "| " << left << setw(w)  << t.user;
    }
    static double TotalBalances(){
        double TotalBalances = 0;
        vector<clsBankClient> clients = _LoadClientDataFromFile();

        for(auto client:clients){
            TotalBalances += client.GetBalance();
        }
        return TotalBalances;
    }

    static string TotalBalancesInText(){
        return clsUtil::NumberToText(TotalBalances());
    }

    void Deposite(double amount) {
        SetBalance(GetBalance() + amount);
        Save();
    }

    void Withdraw(double amount) {
        SetBalance(GetBalance() - amount);
        Save();
    }

    // print method
    void Print() {
        cout << "info\n---------------------------------\n";
        cout << "First Name     : " << GetFirstName() << '\n';
        cout << "Second Name    : " << GetSecondName() << '\n';
        cout << "Full Name      : " << FullName() << '\n';
        cout << "Email          : " << GetEmail() << '\n';
        cout << "Phone Number   : " << GetPhoneNumber() << '\n';
        cout << "Account Number : " << GetAccountNumber() << '\n';
        cout << "PIN Number     : " << GetPINCode() << '\n';
        cout << "Balance        : " << GetBalance() << '\n';
        cout << "---------------------------------\n\n";
    }

    bool Transfer(double amount, clsBankClient& client) {
        if (amount > GetBalance()) {
            return false;
        }
        Withdraw(amount);
        client.Deposite(amount);
        InsertToTransferLog(*this, client, amount);
        return true;
    }

    struct stTransferLog {
        string DateTime, Client1AccNo, Client2AccNo, user;
        double Amount, Client1Balance, Client2Balance;
    };

    static void InsertToTransferLog(clsBankClient client1, clsBankClient client2, double amount) {
        fstream file;
        file.open("D:\\C++ projects\\OOP projects\\System Bank\\TransferLog.txt", ios::out | ios::app);

        if (file.is_open()) {
            file << _ConvertTransferLogToString(_ConvertClientsToTransferLog(client1, client2, amount)) << endl;
            file.close();
        }
    }

    static vector<stTransferLog> ConvertFileTransferLogsToVector() {
        vector<stTransferLog> transfers;
        fstream file;
        file.open("D:\\C++ projects\\OOP projects\\System Bank\\TransferLog.txt", ios::in);
        if (file.is_open()) {
            string line;
            stTransferLog t;
            while (getline(file, line)) {
                t = _ConvertStringToTransferLog(line);
                transfers.push_back(t);
            }
            file.close();
        }
        return transfers;
    }


};