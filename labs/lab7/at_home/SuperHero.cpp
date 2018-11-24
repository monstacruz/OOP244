//
//  SuperHero.cpp
//  ws7home
//
//  Created by mon sta cruz on 2018-07-17.
//  Copyright © 2018 mon. All rights reserved.
//

#include "SuperHero.h"
#include <iostream>
using namespace std;

namespace sict{
    SuperHero::SuperHero(){
        strcpy(name,"\0");
        health = 0;
        atk = 0;
        atkBonus = 0;
        def = 0;
    }
    
    SuperHero::SuperHero(const char * nameInput, int healthInput, int atkInput, int atkBonusInput, int defInput) : Hero(nameInput, healthInput, atkInput)
    {
        strncpy(name, nameInput, MAX_NAME);
        health = healthInput;
        atk = atkInput;
        atkBonus = atkBonusInput;
        def = defInput;
        
        if(!validate()){
            strcpy(name,"\0");
            health = 0;
            atk = 0;
            atkBonus = 0;
            def = 0;
        }
    }
    
    int SuperHero::attackStrength() const{
        int result = 0;
        if(validate()){
            result = atk + atkBonus;
        }
        return result;
    }
    
    int SuperHero::defend() const{
        int result = 0;
        if(validate())
            result = def;
        return result;
    }
    
    bool SuperHero::isAlive() const{
        bool result = false;
        if (health > 0)
            result = true;
        return result;
    }
    
    void SuperHero::operator=(const SuperHero& input){
        strcpy(this->name, input.name);
        this->atk = input.atk;
        this->health = input.health;
        this->atkBonus = input.atkBonus;
        this->def = input.def;
    }
    
    std::ostream& operator<<(std::ostream& os, const SuperHero& sHero){
        if(strcmp(sHero.name,"\0") != 0)
            std::cout << sHero.name;
        else
            std::cout << "No hero";
        return os;
    }
    
    void SuperHero::operator-=(int attack){
        if (attack > 0){
            health -= attack;
            if (health < 0)
                health = 0;
        }
    }
    
    const SuperHero& operator*(const SuperHero& first, const SuperHero& second){
        SuperHero iFirst = first;
        SuperHero iSecond = second;
        int firstDmg, secondDmg;
        firstDmg = iFirst.attackStrength();
        secondDmg = iSecond.attackStrength();
        int i, rounds = 0;
        int result = 0;
        int flag = 0;
        
        std::cout << "Super Fight! " << first << " vs " << second << " : ";
        
        for(i=0; i < max_rounds && flag == 0; i ++){
            rounds ++;
            iFirst -= (secondDmg - iFirst.defend());
            iSecond -= (firstDmg - iSecond.defend());
            if(!iFirst.isAlive()){
                flag = 1;
            }
            if(!iSecond.isAlive()){
                flag = 2;
            }
            if(rounds > 100)
                flag = 2;
        }
        result = flag;
        std::cout << "Winner is " << (result == 1 ? second : first) << " in " << rounds << " rounds." << std::endl;
        return result == 1 ? second: first;
        
        
    }
    
    SuperHero::~SuperHero(){
        cout << "superHero destructed" << endl;
    }
}
