// TODO: add file header comments here
// Mon Clarence Santa Cruz
// 6/7/2018


// TODO: add header file guard here
#ifndef Passenger_h
#define Passenger_h
// TODO: declare your namespace here
namespace sict{
// TODO: define the Passenger class here
    class Passenger{
        char name[32];
        char destination[32];
        
    public:
        
        Passenger();
        Passenger(char * nameInput, char * destInput);
        
        bool isEmpty() const;
        void display() const;
    };
}
#endif
