// TODO: add file header comments here
// Mon Clarence Santa Cruz
// 6/7/2018
// TODO: add your headers here
#include <iostream>
#include <cstring>
using namespace std;
#include "Passenger.h"

// TODO: continue your namespace here
namespace sict{
    // TODO: implement the default constructor here
    Passenger::Passenger(){
        strcpy(name, "\0");
        strcpy(destination, "\0");
    }
	// TODO: implement the constructor with 2 parameters here
    Passenger::Passenger(char * nameInput, char * destInput){
        char newNameInput[32];
        char newDestInput[32];
        
        if (nameInput == nullptr)
            strcpy(newNameInput, "\0");
        else
            strcpy(newNameInput, nameInput);
        
        if (destInput == nullptr)
            strcpy(newDestInput, "\0");
        else
            strcpy(newDestInput, destInput);
        
        strcpy(name, newNameInput);
        strcpy(destination, newDestInput);
    }
    // TODO: implement isEmpty query here
    bool Passenger::isEmpty() const{
        bool result;
        if (strcmp(name,"\0") == 0 || strcmp(destination, "\0") == 0)
            result = true;
        else
            result = false;
        return result;
    }
    // TODO: implement display query here
    void Passenger::display() const{
        if (isEmpty() == false)
            cout << name << " - " << destination << endl;
        else
            cout << "No passenger!" << endl;
    }

}
