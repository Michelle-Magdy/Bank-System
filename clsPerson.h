//
// Created by Michelle on 9/8/2024.
//
#pragma once
#ifndef SYSTEM_BANK_CLSPERSON_H
#define SYSTEM_BANK_CLSPERSON_H

#endif //SYSTEM_BANK_CLSPERSON_H

#include <iostream>

using namespace std;

class clsPerson {
private:
    string _firstName, _secondName, _email, _phone;

public:

    //  ParameterizedConstructor
    clsPerson(string FirstName, string SecondName, string Email, string PhoneNumber) {
        _firstName = FirstName;
        _secondName = SecondName;
        _email = Email;
        _phone = PhoneNumber;
    }

    // First name methods
    void SetFirstName(string firstName) {
        _firstName = firstName;
    }

    string GetFirstName() const {
        return _firstName;
    }
    __declspec(property(get = GetFirstName, put = SetFirstName)) string FirstName;

    // Second Name methods
    void SetSecondName(string secondName) {
        _secondName = secondName;
    }

    string GetSecondName() const {
        return _secondName;
    }
    __declspec(property(get = GetSecondName, put = SetSecondName)) string LastName;

    // Full name method
    string FullName() {
        return _firstName + ' ' + _secondName;
    }

    // Email methods
    void SetEmail(string email) {
        _email = email;
    }

    string GetEmail() const {
        return _email;
    }
    __declspec(property(get = GetEmail, put = SetEmail)) string Email;

    // Phone Number methods
    void SetPhoneNumber(string phoneNumber) {
        _phone = phoneNumber;
    }

    string GetPhoneNumber() const {
        return _phone;
    }
    __declspec(property(get = GetPhoneNumber, put = SetPhoneNumber)) string Phone;


};