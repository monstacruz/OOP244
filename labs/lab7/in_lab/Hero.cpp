//
//  Hero.cpp
//  ws7lab
//
//  Created by mon sta cruz on 2018-07-12.
//  Copyright © 2018 mon. All rights reserved.
//
#include <iostream>
#include <cstring>
#include "Hero.h"
#include <cstdlib>
using namespace std;

namespace sict{
    Hero::Hero(){
        strcpy(name,"\0");
        health = 0;
        atk = 0;
    }
    
    Hero::Hero(const char * nameInput, int healthInput, int atkInput){
        strncpy(name,nameInput,MAX_NAME);
        health = healthInput;
        atk = atkInput;
        
        if(!validate()){
            strcpy(name,"\n");
            health = 0;
            atk = 0;
        }
    }
    
    bool Hero::validate(){
        bool result = true;
        if (health < 0 || atk < 0)
            result = false;
        return result;
    }
    
    void Hero::operator -=(int attack){
        if (attack > 0){
            health -= attack;
            if (health < 0)
                health = 0;
        }
    }
    
    bool Hero::isAlive() const {
        bool result = false;
        if (health > 0)
            result = true;
        return result;
    }
    
    int Hero::attStr() const{
        return atk;
    }
    
    std::ostream& operator<<(std::ostream& os, const Hero& hero){
        if(strcmp(hero.name,"\0") != 0)
            cout << hero.name;
        else
            cout << "No hero";
        return os;
    }
    
    Hero& Hero::operator=(Hero& input){
        return input;
    }
    
    
    const Hero& operator*(const Hero& first, const Hero& second){
        int i, rounds = 0;
        int result = 0;
        int flag = 0;
        Hero iFirst = first;
        Hero iSecond = second;

        cout << "Ancient Battle! " << first << " vs " << second << " : ";
        for(i=0; i < max_rounds && flag == 0; i++){
            rounds++;
            iFirst -= iSecond.attStr();
            iSecond -= iFirst.attStr();
            if(iFirst.isAlive() == false)
                flag = 1;
            if(iSecond.isAlive() == false)
                flag = 2;
            if(rounds > 100)
                flag = 3;
        }
        
        if (flag == 1){//first is dead
            cout << "Winner is " << second << " in " << rounds << " rounds." << endl;
            result = 1;
        }
        else if (flag == 2){ // second is dead
             cout << "Winner is " << first << " in " << rounds << " rounds." << endl;
            result = 2;
        }
        else{
            result = rand() % 2;
            cout << "random battle result is  " << result << "in " << rounds << "rounds"  << endl;
        }
        
        return result == 1 ? second : first;
    }
}
