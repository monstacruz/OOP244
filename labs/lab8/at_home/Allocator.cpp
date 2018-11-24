#include "SavingsAccount.h"
#include "ChequingAccount.h"
#include "iAccount.h"

namespace sict {

	// define interest rate
    const double INT_RATE = 0.05;
    const double TRANS_FEE = 0.50;
    const double MONTH_FEE = 2.00;

	// TODO: Allocator function
	//
    iAccount* CreateAccount(const char* acc, double initBal){
        iAccount * tmp;
        if (acc[0] == 's' || acc[0] == 'S'){
            tmp = new SavingsAccount(initBal, INT_RATE);
        }
        else if (acc[0] == 'c' || acc[0] == 'C'){
            tmp = new ChequingAccount(initBal, TRANS_FEE, MONTH_FEE);
        }
        else
            tmp = nullptr;
        return tmp;
        
    }

}
