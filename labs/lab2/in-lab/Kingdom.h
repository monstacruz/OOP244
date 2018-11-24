/***********************************************************
// OOP244 Workshop 2: Dynamic Memory
// File Kingdom.h
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

// TODO: header safeguards
#ifndef KINGDOM_SICT_H
#define KINGDOM_SICT_H

// TODO: sict namespace
namespace sict {
// TODO: define the structure Kingdom in the sict namespace
    struct Kingdom {
        char m_name[32];
        int m_population;
    };
// TODO: declare the function display(...),
//         also in the sict namespace
    
    void display (const Kingdom &);
}
#endif

