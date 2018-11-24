// TODO: add file header comments here
// Mon Clarence Santa Cruz
// 6/7/2018
// TODO: add your headers here
#include <iostream>
#include <cstring>
#include <iomanip>
using namespace std;
#include "Passenger.h"

// TODO: continue your namespace here
namespace sict{
    // TODO: implement the default constructor here
    Passenger::Passenger(){
        strncpy(mName, "\0",32);
        strncpy(destination, "\0",32);
	year = 0;
	month = 0;
	day = 0;
    }
	// TODO: implement the constructor with 2 parameters here
    Passenger::Passenger(const char * nameInput,const char * destInput){
        char newNameInput[32];
        char newDestInput[32];
        
        if (nameInput == nullptr)
            strncpy(newNameInput, "\0", 32);
        else
            strncpy(newNameInput, nameInput, 32);
        
        if (destInput == nullptr)
            strncpy(newDestInput, "\0", 32);
        else
            strncpy(newDestInput, destInput, 32);
        
        strncpy(mName, newNameInput, 32);
        strncpy(destination, newDestInput, 32);

	if (strcmp(mName, "\0") != 0 && strcmp(destination, "\0") != 0){
		year = 2017;
		month = 7;
		day = 1;
   	 } else {
	 	year = 0;
		month = 0;
		day = 0;
	 }
    }

    Passenger::Passenger(const char * nameInput, const char * destInput,
        int yearInput, int monthInput, int dayInput){
	    char newNameInput[32];
	    char newDestInput[32];
	    bool valid;
		//validation of the date entered
	    if(yearInput >= 2017 && yearInput <=2020){
		    if (monthInput >= 1 && monthInput <=12){
			    if(dayInput >= 1 && dayInput <= 31){
				    valid = true;
			    } else
				    valid = false;
		    } else
			    valid = false;
	    } else 
		    valid = false;

		//checking for a nullptr for the nameInput
	    if (nameInput == nullptr)
            strncpy(newNameInput, "\0", 32);
	    else
		    strncpy(newNameInput, nameInput, 32);
		
	    	//checking for a nullptr for the destInput
	    if (destInput == nullptr)
		    strncpy(newDestInput, "\0", 32);
	    else
		    strncpy(newDestInput, destInput, 32);
		
	    
	    strncpy(mName, newNameInput,32);
	    strncpy(destination, newDestInput,32);
            	
	    	//check if the data entered is valid, if so, allocate the input date to the member date
	    if (strcmp(mName, "\0") != 0 && strcmp(destination, "\0") != 0 && valid == true){
	    	year = yearInput;
		month = monthInput;
		day = dayInput;
	    } else {
	    	year = 0;
		month = 0;
		day = 0;
	    }
    }


    // TODO: implement isEmpty query here
    bool Passenger::isEmpty() const{
        bool result;
        if (strcmp(mName,"\0") == 0 || strcmp(destination, "\0") == 0 ||
            year == 0 || month == 0 || day == 0)
            result = true;
        else
            result = false;
        return result;
    }
    // TODO: implement display query here
    void Passenger::display() const{
        if (isEmpty() == false)
            cout << mName << " - " << destination << " on " << year << "/" <<  setfill('0') << setw(2) << month << "/" << day << endl;
        else
            cout << "No passenger!" << endl;
    }

    const char * Passenger::name() const {
    	return this->mName;
   
    }

    bool Passenger::canTravelWith(const Passenger & passengerBuddy) const {
    	bool result;
	if(strcmp(this->destination, passengerBuddy.destination) == 0){
		if(this->year == passengerBuddy.year){
			if(this->month == passengerBuddy.month){
				if(this->day == passengerBuddy.day){
					result = true;
				} else
					result = false;
			} else 
				result = false;
		} else
			result = false;
	} else
		result = false;
		
    	return result;
    }
}
