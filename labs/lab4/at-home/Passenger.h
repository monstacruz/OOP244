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
    char mName[32];
    char destination[32];
	int year;
	int month;
	int day;
        
    public:

        Passenger();
        Passenger(const char * nameInput, const char * destInput);
        Passenger(const char * nameInput, const char * destInput, 
		  int yearInput, int monthInput, int dayInput);

        bool isEmpty() const;
        void display() const;
	const char * name() const;
	bool canTravelWith(const Passenger&) const;
    };
}
#endif
