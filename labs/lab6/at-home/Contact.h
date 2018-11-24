//
//  Contact.h
//  ws6lab
//
//  Created by mon sta cruz on 2018-07-06.
//  Copyright © 2018 mon. All rights reserved.
//

#ifndef Contact_h
#define Contact_h
namespace sict{
    const int MAXNAME = 19;
    class Contact{
        char name[MAXNAME];
        long long int * numbers;
        int size;
        
    public:
        Contact();
        Contact(const char *, const long long int *, int);
        Contact(Contact &);
        ~Contact();
        
        bool isEmpty();
        void display();
        void set(const char *, const long long int *, int);
        Contact operator = (const Contact &);
        Contact operator += (long long int);
    };
}

#endif /* Contact_h */
