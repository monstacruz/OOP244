//
//  CRA_Account.cpp
//  ws3lab
//
//  Created by mon sta cruz on 2018-05-31.
//  Copyright © 2018 mon. All rights reserved.
//
#include <iostream>
using namespace std;
#include <cstring>

#include "CRA_Account.h"
namespace sict{
    void CRA_Account::set(const char * mL_Name, const char * mG_Name, int m_sin){
        if (m_sin > 100000000 && m_sin < 999999999){
            strncpy(familyName,mL_Name, max_name_length);
            strncpy(givenName, mG_Name, max_name_length);
            sin = m_sin;
        }
        else {
            strcpy(familyName, "\0");
            strcpy(givenName, "\0");
            sin = 0;
        }
    }
    
    bool CRA_Account::isEmpty() const {
        bool result;
        if (sin > 100000000 && sin < 999999999)
            result = false;
        else
            result = true;
        return result;
    }
    
    void CRA_Account::display() const {
        if (isEmpty() == false){
            cout << "Family Name: " << familyName << endl;
            cout << "Given Name : " << givenName << endl;
            cout << "CRA Account: " << sin << endl;
        }
        else
            cout << "Account object is empty!" << endl;
    }
}
