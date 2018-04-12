#ifndef SHEELKUMAR_DATE_H
#define SHEELKUMAR_DATE_H

#include <iostream>

namespace SheelKumar
{
    class Date;
}

// Date displays given date and checks if it is valid
class SheelKumar::Date
{
public:
    // Constructors (one default and one user input)
    Date();
    Date(int month, int day, int year);

    // Getters for month, day and year
    inline int getMonth() const 
    { 
        return this->month; 
    };

    inline int getDay() const 
    { 
        return this->day; 
    };

    inline int getYear() const 
    { 
        return this->year; 
    };

    // Displays date in MM/DD/YYYY format
    void display() const;

private:
    int month;
    int day;
    int year;

    // Used to determine if date and day are valid (moved to separate functions for readability)
    bool isDateValid(int month, int day, int year) const;
    bool isDayValid(int day, int month, bool isLeap) const;
};

#endif