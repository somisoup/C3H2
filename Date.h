#ifndef SHEELKUMAR_DATE_H
#define SHEELKUMAR_DATE_H

#include <iostream>

namespace SheelKumar
{
    class Date;
}

class SheelKumar::Date
{
public:
    Date();
    Date(int month, int day, int year);

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

    void display() const;

private:
    int month;
    int day;
    int year;

    bool isDateValid(int month, int day, int year) const;
    bool isDayValid(int day, int month, bool isLeap) const;
};

#endif