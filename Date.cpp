#include "Date.h"

Date::Date()
{

}

Date::Date(int monthToSet, int dayToSet, int yearToSet)
{
    if (isMonthValid(monthToSet))
    {
        month = monthToSet;
    }
    else
    {
        month = default_month;
    }

    day = dayToSet;
    year = yearToSet;
}

int Date::getMonth()
{
    return month;
}

int Date::getDay()
{
    return day;
}

int Date::getYear()
{
    return year;
}

void Date::display()
{
    std::cout << month << "/" << day << "/" << year << "\n";
}

bool Date::isMonthValid(int monthToCheck)
{
    if (monthToCheck > 12 || monthToCheck < 1)
    {
        std::cerr << "Invalid month entered\n";
        return false;
    }

    return true;
}