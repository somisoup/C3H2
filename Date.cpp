#include "Date.h"
#include <ctime>

using SheelKumar::Date;

// Default constructor uses current time
Date::Date()
{
    // Needed to add to year value in time struct
    const int BASE_YEAR = 1900;
    
    // Get local time
    time_t rawTime = time(0);
    struct tm * curTime = localtime(&rawTime);

    // Assign values to member variables
    month = curTime->tm_mon + 1; // tm struct uses 0-11 instead of 1-12
    day = curTime->tm_mday;
    year = curTime->tm_year + BASE_YEAR; // tm struct counts years from 1900
}

// Additional constructor to set custom date
Date::Date(int month, int day, int year)
{
    // If date is valid, assign member variables, otherwise print error
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

// Display date in MM/DD/YYYY
void Date::display() const
{
    std::cout << month << "/" << day << "/" << year << "\n";
}

// Determine if date passed in is valid (false if invalid, true if valid)
bool Date::isDateValid(int month, int day, int year) const
{
    bool isLeap = false;
    const int MIN_MONTH = 1;
    const int MAX_MONTH = 12;
    
    // Check if year is a leap year
    if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0))
    {
        isLeap = true;
    }

    // Check if month, day, and year are valid in that order
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

// Determine if day is valid given the month and if it is a leapyear
bool Date::isDayValid(int day, int month, bool isLeap) const
{
    const int FEB = 2, APRIL = 4, JUNE = 6, SEPTEMBER = 9, NOVEMBER = 11;
    const int MIN_DAYS = 0;
    const int LESS_DAYS = 30;
    const int MORE_DAYS = 31;
    const int FEB_LEAP = 29;
    const int FEB_NONLEAP = 28;

    // If day is 0 or negative, return false. Otherwise check if days are less than or equal to 30 for given months.
    // Otherwise, check if day is valid for Feb if leap year or not. Finally, check if days are between 1-31 for all other months
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