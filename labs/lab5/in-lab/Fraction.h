// TODO: header file guard
#ifndef FRACTION_H
#define FRACTION_H
// TODO: create namespace
namespace sict{
	// TODO: define the Fraction class
	class Fraction {
		// TODO: declare instance variables 
        int numerator;
        int denominator;
		// TODO: declare private member functions
        int max() const;
        int min() const;
        void reduce ();
        int gcd() const;
        
	public:
        Fraction();
        Fraction(int, int);
		// TODO: declare public member functions
        bool isEmpty() const;
        void display() const;
		// TODO: declare the + operator overload
        Fraction operator + (const Fraction &);
        
	};
}

#endif
