//
//  Perishable.cpp
//  ms5
//
//  Created by mon sta cruz on 2018-08-07.
//  Copyright © 2018 mon. All rights reserved.
//

#include "Perishable.h"
#include <iostream>
#include <fstream>
using namespace std;

namespace AMA {
    Perishable::Perishable() : Product('P') {
    }
    
    fstream& Perishable::store(fstream& file, bool newline) const{
        if (file.is_open()){
            Product::store(file, false);
            file << ",";
            date.write(file);
            if(newline)
                file << endl;
        }
        return file;
    }
    
    fstream& Perishable::load(fstream& file){
        Product::load(file);
        date.read(file);
        file.ignore();
        return file;
    }
    
    ostream& Perishable::write(ostream& os, bool linear) const{
        Product::write(os, linear);
        if (isClear()){
            if (linear)
                os << date;
            else
                os << " Expiry date: " << date;
        }
        return os;
    }
    
    istream& Perishable::read(istream& is){
        Date tmp;
        Product::message("");
        Product::read(is);
        cout << "Expiry date (YYYY/MM/DD): ";
        tmp.read(is);
        if (tmp.errCode() == 1){
            Product::message("Invalid Date Entry");
            is.setstate(ios::failbit);
        }
        if (tmp.errCode() == 2){
            Product::message("Invalid Year in Date Entry");
            is.setstate(ios::failbit);
        }
        
        if (tmp.errCode() == 3){
            Product::message("Invalid Month in Date Entry");
            is.setstate(ios::failbit);
        }
        if (tmp.errCode() == 4){
            Product::message("Invalid Day in Date Entry");
            is.setstate(ios::failbit);
        }
        
        if (tmp.errCode() == 0)
            date = tmp;
        
        return is;
    }
    
    const Date& Perishable::expiry() const{
        return date;
    }
}

