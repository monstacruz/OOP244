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
#ifndef AMA_DATE_H
#define AMA_DATE_H

#define NO_ERROR 0
#define CIN_FAILED 1
#define YEAR_ERROR 2
#define MON_ERROR 3
#define DAY_ERROR 4
namespace AMA {

    
    const int min_year = 2000;
    const int max_year = 2030;
    class Date {
        
        int year;
        int month;
        int day;
        int comparator;
        int errState;
        
        int mdays(int, int)const;
        void errCode(int);
    public:
        Date();
        Date(int, int, int);
 
        bool operator ==(const Date &);
        bool operator !=(const Date &);
        bool operator <(const Date &);
        bool operator >(const Date &);
        bool operator <=(const Date &);
        bool operator >=(const Date &);
        
        int errCode() const;
        bool bad() const;
        std::istream& read(std::istream&);
        std::ostream& write(std::ostream&) const;
  };
    
    std::istream& operator>>(std::istream&, Date&);
    std::ostream& operator<<(std::ostream&, const Date&);

}
#endif
