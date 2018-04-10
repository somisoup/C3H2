#ifndef SHEEL_DATE_H
#define SHEEL_DATE_H

#include <iostream>

namespace SheelKumar
{
    class Date;
}

class Date
{
    public:
    Date();
    Date(int monthToSet, int dayToSet, int yearToSet);
    int getMonth();
    int getDay();
    int getYear();

    void display();

    private:
    int month;
    int day;
    int year;

    const int default_month = 1;

    bool isMonthValid(int monthToCheck);
};

#endif