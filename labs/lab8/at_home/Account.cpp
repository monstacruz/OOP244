// Account.cpp
// Mon Clarence Santa Cruz
// 031608144

#include <iostream>
#include "Account.h"

namespace sict{
    Account::Account(double balance){
        if (balance > 0)
            bal = balance;
        else
            bal = 0.0;
    }
    
    bool Account::credit(double input){
        bool result = false;
        if (input > 0){
            result = true;
            bal += input;
        }
        return result;
    }
    
    bool Account::debit(double input){
        bool result = false;
        if (input > 0){
            result = true;
            bal -= input;
        }
        return result;
    }
    
    double Account::balance() const{
        return bal;
    }
    
}
