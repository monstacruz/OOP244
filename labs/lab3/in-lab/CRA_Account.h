//
//  CRA_Account.h
//  ws3lab
//
//  Created by mon sta cruz on 2018-05-31.
//  Copyright © 2018 mon. All rights reserved.
//

#ifndef CRA_Account_h
#define CRA_Account_h

namespace sict{
    const int max_name_length = 40;
    const int min_sin = 100000000;
    const int max_sin = 999999999;
    
    class CRA_Account {
        char familyName[max_name_length + 1];
        char givenName[max_name_length + 1];
        int sin;
        
    public:
        void set(const char *, const char *, int sin);
        bool isEmpty() const;
        void display() const;
    };
}
#endif 
