// Final Project Milestone 1
//
// Version 1.0
// Date
// Author
// Description
// Mon Clarence Santa Cruz
// 031608144
// 7/11/2018
//
// Revision History
// -----------------------------------------------------------
// Name               Date                 Reason
/////////////////////////////////////////////////////////////////
#include <iostream>
#include <string>
#include <iomanip>
#include "Date.h"


using namespace std;
namespace AMA {

  // number of days in month mon_ and year year_
  //
  int Date::mdays(int mon, int year)const {
    int days[] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31, -1 };
    int month = mon >= 1 && mon <= 12 ? mon : 13;
    month--;
    return days[month] + int((month == 1)*((year % 4 == 0) && (year % 100 != 0)) || (year % 400 == 0));
}
    void Date::errCode(int input){
        errState = input;
    }
    
    int Date::errCode() const {
        return errState;
    }
    
    Date::Date(){
        year = 0;
        month = 0;
        day = 0;
        comparator = 0;
        errCode(0);
    }
    
    Date::Date(int year1, int month1, int day1){
        if (year1 < min_year || year1 > max_year)
            errCode(2);
        else if (month1 > 12 || month1 < 1)
            errCode(3);
        else if (day1 > mdays(month1, year1) || day1 < 1)
            errCode(4);
        else{
            year = year1;
            month = month1;
            day = day1;
            errCode(0);
            comparator = year * 372 + month * 13 + day;
        }
    }
    
    bool Date::bad() const{
        bool result = false;
        if (errState != 0)
            result = true;
        return result;
    }
    
    bool Date::operator==(const Date & rhs){
        bool result = false;
        if (this->comparator == rhs.comparator)
                    result = true;
        return result;
    }
    
    bool Date::operator!=(const Date & rhs){
        bool result = false;
        if (!(*this==rhs))
            result = true;
        return result;
    }
    
    bool Date::operator<(const Date & rhs){
        bool result = false;
        if (this->comparator < rhs.comparator)
            result = true;
        return result;
    }
    
    bool Date::operator>(const Date & rhs){
        bool result = false;
        if (!(*this < rhs))
            result = true;
        return result;
    }
    
    bool Date::operator<=(const Date & rhs){
        bool result = false;
        if((*this < rhs) || (*this == rhs))
            result = true;
        return result;
    }
    
    bool Date::operator>=(const Date & rhs){
        bool result = false;
        if (!(*this < rhs) || (*this == rhs))
            result = true;
        return result;
    }
    
    std::istream& Date::read(std::istream& istr){
        char extra;
        int year1;
        int month1;
        int day1;
        cin >> year1 >> extra >> month1 >> extra >> day1;
        if (istr.fail())
            errCode(1);
        else {
            if (year1 < min_year || year1 > max_year)
                errCode(2);
            else if (month1 > 12 || month1 < 1)
                errCode(3);
            else if (day1 > mdays(month1, year1) || day1 < 1)
                errCode(4);
            else{
                year = year1;
                month = month1;
                day = day1;
                errCode(0);
                comparator = year * 372 + month * 13 + day;
            }
        }
        return istr;
    }
    
    std::ostream& Date::write(std::ostream& ostr) const {
        cout << year << "/";
        cout << setw(2) << setfill('0') << month << "/";
        cout << setw(2) << setfill('0') << day << endl;
        return ostr;
    }
    
    std::istream& operator>>(std::istream& istr, Date& input){
        input.read(istr);
        return istr;
    }
    
    std::ostream& operator<<(std::ostream& ostr, const Date& output){
        output.write(ostr);
        return ostr;
    }

}
