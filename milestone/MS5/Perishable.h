//
//  Perishable.h
//  ms5
//
//  Created by mon sta cruz on 2018-08-07.
//  Copyright © 2018 mon. All rights reserved.
//

#ifndef Perishable_h
#define Perishable_h
#include "Product.h"
#include "Date.h"
using namespace std;

namespace AMA {
    
    class Perishable : public Product {
        Date date;
        
    public:
        Perishable();
        fstream& store(fstream& file, bool newline = true) const;
        fstream& load(fstream& file);
        ostream& write(ostream& os, bool linear) const;
        istream& read(istream& is);
        const Date& expiry() const;
    };
}

#endif /* Perishable_h */
