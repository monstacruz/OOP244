/***********************************************************
// OOP244 Workshop 2: Dynamic Memory
// File Kingdom.cpp
// Version 1.0
// Date 5/18/2018
// Author Mon Clarence Santa Cruz
// Description
// ?????????????????????
//
//
// Revision History
///////////////////////////////////////////////////////////
// Name     Date    Reason
// 
///////////////////////////////////////////////////////////
***********************************************************/


// TODO: include the necessary headers
#include <iostream>
using namespace std;
#include "Kingdom.h"
// TODO: the sict namespace
namespace sict {
    // TODO:definition for display(...)
    void display (const Kingdom & king){
        cout << king.m_name << ", population " << king.m_population << endl;
    }
    
    void display (const Kingdom * kingdoms, int kNum){
        int i;
        for (i = 0; i < kNum; i++){
            display(kingdoms[i]);
        }
        }
    }

