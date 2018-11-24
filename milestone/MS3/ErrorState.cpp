//
//  ErrorState.cpp
//  ms2
//
//  Created by mon sta cruz on 2018-07-18.
//  Copyright © 2018 mon. All rights reserved.
//

#include "ErrorState.h"
#include <iostream>
#include <cstring>
using namespace std;

namespace AMA{
    ErrorState::ErrorState(const char * errorMessage){
        if(errorMessage != nullptr)
            message(errorMessage);
        else
            msg = nullptr;
    }
    
    ErrorState::~ErrorState(){
        delete [] msg;
        msg = nullptr;
    }
    
    bool ErrorState::isClear() const{
        bool result = (msg == nullptr ? true : false);
        return result;
    }
    
    void ErrorState::message(const char * str){
        clear();
        msg = nullptr;
        msg = new char[strlen(str + 1)];
        strcpy(msg, str);
    }
    
    void ErrorState::clear(){
        if(!isClear()){
            delete [] msg;
            msg = nullptr;
        }
    }
    
    const char* ErrorState::message() const{
            return msg;
    }
    
    ostream& operator<<(ostream& os, const ErrorState& errMsg){
        if (!errMsg.isClear())
            os << errMsg.message();
        return os;
    }
    
    
    
}
