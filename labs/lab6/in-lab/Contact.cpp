//
//  Contact.cpp
//  ws6lab
//
//  Created by mon sta cruz on 2018-07-06.
//  Copyright © 2018 mon. All rights reserved.
//

#include <iostream>
#include <cstring>
#include <iomanip>
#include "Contact.h"
using namespace std;

namespace sict{
    void Contact::set(const char * nameInput, const long long int * numbersInput, int numberSize){
        if (nameInput == nullptr){
            strcpy(name, "\0");
            numbers = 0;
            size = 0;
        }
        else {
            strncpy(name,nameInput,MAXNAME);
            numbers = new long long int[numberSize];
            for(int i = 0; i < numberSize; i ++){
                numbers[i] = numbersInput[i];
            }
            size = numberSize;
        }
    }
    
    Contact::Contact(){
        long long int emptyNumbers[0];
        set("\0",emptyNumbers,0);
    }
    
    Contact::Contact(const char * nameInput, const long long int * numberInput, int numberSize){
        set(nameInput, numberInput, numberSize);
    }
    
    bool Contact::isEmpty(){
        bool result = false;
        if (strcmp(name,"\0") == 0)
            result = true;
        return result;
    }
    
    void Contact::display(){
        if(!isEmpty()){
            cout << name << endl;
            for(int i = 0; i < size; i ++){
                long long int countryCode;
                long long int areaCode;
                long long int pNumber1;
                long long int pNumber2;
                bool validNum = true;
                if (numbers[i] > 10000000000 && numbers[i] < 99999999999){ //1 digit country code
                    countryCode = numbers[i]/10000000000;
                    areaCode = (numbers[i]%10000000000)/10000000;
                    pNumber1 = (numbers[i]%10000000)/10000;
                    pNumber2 = (numbers[i]%10000);
                    
                    if (countryCode < 1 || areaCode < 1)
                        validNum = false;
                    if (validNum)
                        cout << "(+" << countryCode << ") ";
                        cout << setfill('0') << setw(3) << areaCode << " " << pNumber1;
                        cout <<"-";
                        cout << setfill('0') << setw(4) << pNumber2 << endl;
                    }
                else if (numbers[i] >= 100000000000 && numbers[i] < 999999999999){
                    countryCode = numbers[i]/10000000000;
                    areaCode = (numbers[i]%10000000000)/10000000;
                    pNumber1 = (numbers[i]%10000000)/10000;
                    pNumber2 = (numbers[i]%10000);
                    
                    if (countryCode < 1 || areaCode < 1)
                        validNum = false;
                    if (validNum)
                        cout << "(+" << setfill('0') << setw(2) <<  countryCode << ") ";
                    cout << setfill('0') << setw(3) << areaCode << " " << pNumber1;
                    cout <<"-";
                    cout << setfill('0') << setw(4) << pNumber2 << endl;
                }
            }
            
        } else
            cout << "Empty contact!" << endl;
    }
}
