//
//  iProduct.h
//  ms4
//
//  Created by mon sta cruz on 2018-08-03.
//  Copyright © 2018 mon. All rights reserved.
//

#ifndef iProduct_h
#define iProduct_h
#include <iostream>
#include<fstream>
using namespace std;
namespace AMA{
    class iProduct{
        
    public:
        virtual ~iProduct() = default;
        virtual fstream& store(fstream& file, bool newloine=true) const = 0;
        virtual fstream& load(fstream& file) = 0;
        virtual ostream& write(ostream& os, bool linear) const = 0;
        virtual istream& read(istream& is) = 0;
        virtual bool operator == (const char*) const = 0;
        virtual double total_cost() const = 0;
        virtual const char* name() const = 0;
        virtual void quantity(int) = 0;
        virtual int qtyNeeded() const = 0;
        virtual int quantity() const = 0;
        virtual int operator += (int) = 0;
        virtual bool operator > (const iProduct& input) const = 0;
    };
    
    ostream& operator<<(ostream&, const iProduct&);
    istream& operator>>(istream&, iProduct&);
    double operator +=(double&, const iProduct&);
    iProduct* CreateProduct();
    iProduct* CreatePerishable();
    
}

#endif /* iProduct_h */
