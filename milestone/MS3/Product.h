//
//  Product.h
//  ms3
//
//  Created by mon sta cruz on 2018-07-23.
//  Copyright © 2018 mon. All rights reserved.
//

#ifndef Product_hpp
#define Product_hpp

#include "ErrorState.h"
#include <iomanip>
#include <iostream>
using namespace std;

namespace AMA {
    const int max_sku_length = 7;
    const int max_unit_length = 10;
    const int max_name_length = 75;
    const double CURRTAX = 1.13;
    
    class Product{
        char pType;
        char pSku[max_sku_length + 1];
        char pUnit[max_unit_length + 1];
        char pName[max_name_length + 1];
        int pQtyOh;
        int pQtyNeeded;
        double pPrice;
        bool pTaxable;
        ErrorState pErr;
        
    protected:
        void name(const char *);
        const char * name() const;
        const char * sku() const;
        const char * unit() const;
        bool taxed() const;
        double price() const;
        double cost() const;
        void message(const char *);
        bool isClear() const;
        
    public:
        Product(char type = 'N');
        Product(const char * sku, const char * name, const char * unit, int onHand = 0, bool taxable = true, double price = 0.0, int qtyNeeded = 0);
        Product(const Product &);
        ~Product();
        
        void operator =(const Product &);
        fstream& store(fstream& file, bool newline = true) const;
        fstream& load(fstream& file);
        ostream& write(ostream& os, bool linear) const;
        istream& read(istream& is);
        
        bool operator == (const char *)const;
        bool operator > (const char *) const;
        bool operator > (const Product&) const;
        int operator += (int);
        
        double total_cost() const;
        void quantity(int);
        bool isEmpty() const;
        int qtyNeeded() const;
        int quantity() const;
        void set(const char *, const char *, const char*, int, bool, double, int);
        
    };
    ostream& operator << (ostream&, const Product&);
    istream& operator >> (istream&, Product&);
    double operator +=(double& , const Product&);
}

#endif /* Product_hpp */
