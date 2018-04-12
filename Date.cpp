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

Date::Date(int month, int day, int year)
{
    if (isDateValid(month, day, year))
    {
        this->month = month;
        this->day = day;
        this->year = year;
    }
    else
    {
        std::cerr << "Invalid date, did not create object\n";
    }
}

void Date::display() const
{
    std::cout << month << "/" << day << "/" << year << "\n";
}

bool Date::isDateValid(int month, int day, int year) const
{
    bool isLeap = false;
    const int MIN_MONTH = 1;
    const int MAX_MONTH = 12;
    
    if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0))
    {
        isLeap = true;
    }

    if (month > MAX_MONTH || month < MIN_MONTH)
    {
        std::cerr << "Invalid month entered\n";
        return false;
    }
    else if (!isDayValid(day, month, isLeap))
    {
        std::cerr << "Invalid day entered\n";
        return false;
    }
    else if (year < 0)
    {
        std::cerr << "Invalid year entered\n";
        return false;
    }

    return true;
}

bool Date::isDayValid(int day, int month, bool isLeap) const
{
    const int FEB = 2, APRIL = 4, JUNE = 6, SEPTEMBER = 9, NOVEMBER = 11;
    const int MIN_DAYS = 0;
    const int LESS_DAYS = 30;
    const int MORE_DAYS = 31;
    const int FEB_LEAP = 29;
    const int FEB_NONLEAP = 28;

    if (day <= MIN_DAYS)
    {
        return false;
    }
    else if ((month == APRIL || month == JUNE || month == SEPTEMBER || month == NOVEMBER) && day > LESS_DAYS)
    {
        return false;
    }
    else if (month == FEB)
    {
        if (isLeap && day <= FEB_LEAP)
        {
            return true;
        }
        else if (!isLeap && day <= FEB_NONLEAP)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    else if (day > MORE_DAYS)
    {
        return false;
    }

    return true;
}