#include <iostream>
#include <iomanip>
#include "SavingsAccount.h"
using namespace std;

namespace sict{
    
    SavingsAccount::SavingsAccount(double balance, double rate) : Account(balance){
        if(rate > 0){
            interestRate = rate;
        } else{
            rate = 0;
        }
    }
    
    void SavingsAccount::monthEnd(){
        double interest;
        interest = interestRate * balance();
        credit(interest);
    }
    
    void SavingsAccount::display(ostream& os) const{
        cout << "Account type: Savings" << endl;
        cout << "Balance: $" << fixed << setprecision(2) << balance() << endl;
        cout << "Interest Rate (%): " << interestRate * 100 << endl;
    }
}
