#include "Date.h"

int main()
{
    int myMonth = 0, myDay = 0, myYear = 0;
    std::cout << "Enter month: ";
    std::cin >> myMonth;
    std::cout << "\nEnter day: ";
    std::cin >> myDay;
    std::cout << "\nEnter year: ";
    std::cin >> myYear;
    
    Date myDate(myMonth, myDay, myYear);
    myDate.display();

    return 0;   
}