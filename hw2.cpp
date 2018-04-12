#include "Date.h"

using SheelKumar::Date;

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

    std::cout << "Getter Month is: " << myDate.getMonth() << "\n";
    std::cout << "Getter Day is: " << myDate.getDay() << "\n";
    std::cout << "Getter Year is: " << myDate.getYear() << "\n";

    std::cout << "Error cases:\n";
    std::cout << "Setting month to 0\n";
    Date zeroMonth(0, myDay, myYear);

    std::cout << "Setting invalid date to month (31 to April)\n";
    Date invalidDate1(4, 31, 2008);

    std::cout << "Setting invalid date to month (41 to August)\n";
    Date invalidDate2(8, 41, 2008);

    std::cout << "Setting invalid date to month (0 to January)\n";
    Date invalidDate3(1, 0, 2008);

    std::cout << "Setting invalid date for non leap year (29 to Feb 2001)\n";
    Date invalidDate4(2, 29, 2001);

    std::cout << "Setting invalid date for leap year (30 to Feb 2000)\n";
    Date invalidDate5(2, 30, 2000);

    std::cout << "Setting year to -1\n";
    Date invalidDate6(1, 1, -1);

    return 0;   
}