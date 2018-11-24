//
//  CRA_Account.cpp
//  ws3lab
//
//  Created by mon sta cruz on 2018-05-31.
//  Copyright © 2018 mon. All rights reserved.
//
#include <iostream>
#include <cmath>
using namespace std;
#include <cstring>

#include "CRA_Account.h"
namespace sict{
    void CRA_Account::set(const char * mL_Name, const char * mG_Name, int m_sin){
        if (m_sin > 100000000 && m_sin < 999999999){
            int oddNums[4];
            int oddWeighted = 0, evenWeighted = 0;
            int weighted;
            int check;
            
            //adds the even numbers and stores odd numbers in an array
            check = m_sin % 10;
            oddNums[0] = ((m_sin / 10) % 10);
            evenWeighted += ((m_sin / 100) % 10);
            oddNums[1] = ((m_sin / 1000) % 10);
            evenWeighted += ((m_sin / 10000) % 10);
            oddNums[2] = ((m_sin / 100000) % 10 );
            evenWeighted += ((m_sin / 1000000) % 10);
            oddNums[3] = ((m_sin / 10000000) % 10);
            evenWeighted += ((m_sin / 100000000) % 10);
            
            //multiply the odd numbers by two, then add the numbers
            oddWeighted += (((oddNums[0] * 2) % 10) + (((oddNums[0] * 2) / 10) % 10));
            oddWeighted += (((oddNums[1] * 2) % 10) + (((oddNums[1] * 2) / 10) % 10));
            oddWeighted += (((oddNums[2] * 2) % 10) + (((oddNums[2] * 2) / 10) % 10));
            oddWeighted += (((oddNums[3] * 2) % 10) + (((oddNums[3] * 2) / 10) % 10));
            
            weighted = oddWeighted + evenWeighted;
            
            //if the sum of weighted and check is divisible by 10
            if (((weighted + check) % 10) == 0 && strcmp(mL_Name, "\0") != 0 && strcmp(mG_Name, "\0") != 0 ) {
                strncpy(familyName,mL_Name, max_name_length);
                strncpy(givenName, mG_Name, max_name_length);
                sin = m_sin;
                yearCnt = 0;
            }
            else {
                strcpy(familyName, "\0");
                strcpy(givenName, "\0");
                sin = 0;
            }
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
            //txYear loop
            for (int i = 0; i < yearCnt; i++){
                if (txYrBlnce[i] > 2)
                    cout << "year (" << txRtrnYrs[i] << ") balance owing: " << txYrBlnce[i] << endl;
                else if (txYrBlnce[i] < -2)
                    cout << "year (" << txRtrnYrs[i] << ") refund due: " << abs(txYrBlnce[i]) << endl;
                else
                    cout << "year (" << txRtrnYrs[i] << ") No balance owing or refund due!" << endl;
            }
        }
        else
            cout << "Account object is empty!" << endl;
    }
    
    void CRA_Account::set(int m_year, double m_balance){
        if (yearCnt < max_yrs){
            txRtrnYrs[yearCnt] = m_year;
            txYrBlnce[yearCnt] = m_balance;
            yearCnt ++;
        }
    }
}
