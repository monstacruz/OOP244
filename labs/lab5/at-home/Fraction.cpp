// TODO: insert header files
#include <iostream>
using namespace std;
#include "Fraction.h"
// TODO: continue the namespace
namespace sict {
	// TODO: implement the default constructor
    Fraction::Fraction(){
        numerator = 0;
        denominator = 0;
    }
	// TODO: implement the two-argument constructor
    Fraction::Fraction(int iNumerator, int iDenominator){
        if (iNumerator >= 0 && iDenominator > 0){
            numerator = iNumerator;
            denominator = iDenominator;
            this->reduce();
        }
        else{
            numerator = 0;
            denominator = 0;
        }
    }
	// TODO: implement the max query
   int Fraction::max() const{
       int result;
       if (numerator > denominator)
           result = numerator;
       else if (denominator > numerator)
           result = denominator;
       else
           result = 0;
       
       return result;
    }
    // TODO: implement the min query
    int Fraction::min() const{
        int result;
        if (numerator < denominator)
            result = numerator;
        else if (denominator < numerator)
            result = denominator;
        else
            result = 0;
        return result;
    }
	// gcd returns the greatest common divisor of num and denom
    //
    int Fraction::gcd() const {
        int mn = min();  // min of numerator and denominator
        int mx = max();  // max of numerator and denominator
        int g_c_d = 1;
        bool found = false;

        for (int x = mn; !found && x > 0; --x) { // from mn decrement until divisor found
            if (mx % x == 0 && mn % x == 0) {
                found = true;
                g_c_d = x;
            }
        }
        return g_c_d;
    }

    // TODO: implement the reduce modifier
    void Fraction::reduce() {
        int gcd_ = Fraction::gcd();
        numerator /= gcd_;
        denominator /= gcd_;
    }
    // TODO: implement the display query
    void Fraction::display() const{
        if (isEmpty())
            cout << "no fraction stored";
        else{
            if (numerator % denominator == 0)
                cout << numerator/denominator;
            else
                cout << numerator << "/" << denominator;
        }
    }
    // TODO: implement the isEmpty query
    bool Fraction::isEmpty() const{
        bool result;
        if (denominator == 0 || numerator == 0)
            result = true;
        else
            result = false;
        return result;
    }
    // TODO: implement the + operator
    Fraction Fraction::operator +(const Fraction & rhs){
        Fraction result;
        if(!isEmpty() && !rhs.isEmpty()){
            result.numerator = (this->numerator * rhs.denominator) + (rhs.numerator * this->denominator);
            result.denominator = this->denominator * rhs.denominator;
            result.reduce();
        }
        return result;
    }
    
    //home part operators
    Fraction Fraction::operator * (const Fraction & rhs){
        Fraction result;
        if (!this->isEmpty() && !rhs.isEmpty()){
            result.numerator = this->numerator * rhs.numerator;
            result.denominator = this->denominator * rhs.denominator;
            result.reduce();
        }
        return result;
    }
    
    bool Fraction::operator == (const Fraction & rhs){
        bool result = false;
        if (!this->isEmpty() && !rhs.isEmpty()){
            if (this->numerator == rhs.numerator && this->denominator == rhs.denominator)
                result = true;
        }
        return result;
    }
    
    bool Fraction::operator != (const Fraction & rhs){
        bool result = false;
        if (!this->isEmpty() && !rhs.isEmpty()){
            if (!(*this == rhs))
                result = true;
        }
        return result;
    }
    
    Fraction & Fraction::operator += (const Fraction & rhs){
        Fraction tmp;
        if (!this->isEmpty() && !rhs.isEmpty()){
            tmp = *this + rhs;
            *this = tmp;
        }
        else
            *this = tmp;
        return *this;
    }
}
