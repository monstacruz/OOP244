//
//  SuperHero.hpp
//  ws7home
//
//  Created by mon sta cruz on 2018-07-17.
//  Copyright © 2018 mon. All rights reserved.
//

#ifndef SuperHero_hpp
#define SuperHero_hpp

#include "Hero.h"
#include <iostream>

namespace sict{
    class SuperHero : public Hero {
        char name[MAX_NAME + 1];
        int health;
        int atk;
        int atkBonus;
        int def;
        
    public:
        SuperHero();
        SuperHero(const char *, int, int, int, int);
        ~SuperHero();
        
        bool isAlive() const;
        int attackStrength() const;
        int defend() const;
        void operator =(const SuperHero&);
        void operator -=(int);
        friend std::ostream& operator<<(std::ostream&, const SuperHero&);
        };
    const SuperHero& operator*(const SuperHero&, const SuperHero&);
}

#endif
