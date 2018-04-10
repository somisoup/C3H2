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
    Date(int monthToSet, int dayToSet, int yearToSet);
    inline int getMonth();
    inline int getDay();
    inline int getYear();

    void display();

    private:
    int month;
    int day;
    int year;

    const int default_month = 1;

    bool isDateValid(int monthToCheck, int dayToCheck, int yearToCheck);
};

#endif