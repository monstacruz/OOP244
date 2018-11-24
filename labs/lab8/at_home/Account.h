
#ifndef SICT_ACCOUNT_H__
#define SICT_ACCOUNT_H__

#include "iAccount.h"

namespace sict {
   
    class Account : public iAccount{
        double bal;

	protected:
        double balance() const;

	public:
		// TODO: constructor initializes account balance, defaults to 0.0 
        explicit Account(double);

		// TODO: credit adds +ve amount to the balance 
        bool credit(double);

		// TODO: debit subtracts a +ve amount from the balance
        bool debit(double);
        /*
        virtual void monthEnd();
        virtual void display(std::ostream&);
         */
	};


}
#endif
