//
//  Hero.h
//  ws7lab
//
//  Created by mon sta cruz on 2018-07-12.
//  Copyright © 2018 mon. All rights reserved.
//

#ifndef Hero_h
#define Hero_h
#include <iostream>

namespace sict{
    const int MAX_NAME = 40;
    const int max_rounds = 100;
    class Hero{
        char name[MAX_NAME + 1];
        int health;
        int atk;
        
    public:
        Hero();
        Hero(const char *, int, int);
        ~Hero();
        
        void operator -=(int attack);
        bool isAlive() const;
        int attackStrength() const;
        
        bool validate() const;
        Hero& operator =(Hero&);
        Hero& operator =(const Hero&);
        friend std::ostream& operator<<(std::ostream&, const Hero&);

    };
    const Hero& operator*(const Hero&, const Hero&);
    
}

#endif /* Hero_h */
