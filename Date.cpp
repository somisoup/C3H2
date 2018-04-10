#include "Date.h"
#include <ctime>

using SheelKumar::Date;

Date::Date()
{
    time_t rawTime = time(0);
    struct tm * curTime = localtime(&rawTime);

    month = curTime->tm_mon + 1;
    day = curTime->tm_mday;
    year = curTime->tm_year;
}

Date::Date(int monthToSet, int dayToSet, int yearToSet)
{
    if (isDateValid(monthToSet, dayToSet, yearToSet))
    {
        month = monthToSet;
        day = dayToSet;
        year = yearToSet;
    }
}

inline int Date::getMonth()
{
    return month;
}

inline int Date::getDay()
{
    return day;
}

inline int Date::getYear()
{
    return year;
}

void Date::display()
{
    std::cout << month << "/" << day << "/" << year << "\n";
}

bool Date::isDateValid(int monthToCheck, int dayToCheck, int yearToCheck)
{
    if (monthToCheck > 12 || monthToCheck < 1)
    {
        std::cerr << "Invalid month entered\n";
        return false;
    }

    return true;
}