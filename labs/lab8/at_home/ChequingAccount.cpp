// OOP244 Workshop 8: Virtual Functions and Abstract Base Classes
// File: ChequingAccount.cpp
// Version: 2.0
// Date: 2018/7,20
// Author: Mon Clarence Santa Cruz
// Description:
// This file implements the ChequingAccount class
///////////////////////////////////////////////////

#include "ChequingAccount.h"
#include <iostream>
#include <iomanip>

using namespace std;

namespace sict {
	// constructor initializes balance and transaction fee
	//
    ChequingAccount::ChequingAccount(double initBal, double transFeeInput, double monthEndFeeInput) : Account(initBal) {
        if (transFeeInput > 0)
            transFee = transFeeInput;
        else
            transFee = 0.0;
        
        if (monthEndFeeInput > 0)
            monthEndFee = monthEndFeeInput;
        else
            monthEndFee = 0.0;
    }


	// credit (add) an amount to the account balance and charge fee
	// returns bool indicating whether money was credited
	//
    bool ChequingAccount::credit(double input){
        bool result = false;
        if (Account::credit(input)){
            Account::debit(transFee);
        }
        return result;
    }



	// debit (subtract) an amount from the account balance and charge fee
	// returns bool indicating whether money was debited
	//
    bool ChequingAccount::debit(double input){
        bool result = false;
        if (Account::debit(input)){
            result = true;
            Account::debit(transFee);
        }
        return result;
    }


	// monthEnd debits month end fee
	//
    void ChequingAccount::monthEnd(){
        Account::debit(monthEndFee);
        Account::debit(transFee);
    }



	// display inserts account information into ostream os
	//
    void ChequingAccount::display(ostream& os) const{
        cout << "Account type: Chequing" << endl;
        cout << "Balance: $" << fixed << setprecision(2) << balance() << endl;
        cout << "Per Transaction Fee: " << fixed << setprecision(2) << transFee << endl;
        cout << "Monthly Fee: " << fixed << setprecision(2) << monthEndFee << endl;
    }



}
