// Brasher, Bryan
// 25-MAR-2019
/* This driver program tests six functions necessary for determining
 * day of the week e.g. Monday, Tuesday, etc. for a given date using
 * Gauss' algorithm as described at: https://en.wikipedia.org/wiki/
 * Determination_of_the_day_of_the_week#Gauss's_algorithm */

#include <iostream>
#include <limits>
#include <string>

// function declarations

void testMenu();
/* displays menu i.e. displays all six functions with their
 * corresponding number value (that user can then input in std in)
 * as well as a value to exit. */

bool isLeapYear(int year);
/* Precondition: Year has integer value.
 * Postcondition: Returns true if year is a leap year, else returns false. */

int getCenturyValue(int year);
/* Precondition: Year has integer value.
 * Postcondition: Returns century value in accordance with (IAW) Gauss' algorithm.*/

int getYearValue(int year);
/* Precondition: Year has integer value.
 * Postcondition: Returns year value in accordance with (IAW) Gauss' algorithm.*/

int getMonthValue(int month, int year);
/* Precondition: Year has integer value.  Month has integer value i.e. Jan = 1, Feb = 2
 * ... Dec = 12.
 * Postcondition: Returns year value in IAW Gauss' algorithm.*/

int dayOfWeek(int month, int day, int year);
/* Precondition: Year has integer value.  Month has integer value i.e. Jan = 1, Feb = 2
 * ... Dec = 12.  Day has an integer value.  e.g. July 4 = 4
 * Postcondition: Returns day of week IAW Gauss' algorithm.  e.g. 0 = Sunday ... 6 = Saturday.*/

std::string dayOfWeek(int day);
/* Precondition: Day has integer value 0 - 6.
 * Postcondition: Returns as a string the corresponding day of the week.
 * e.g. 0 returns Sunday, 6 returns Saturday.*/

void getDayofWeek(int& dayofweek);
/* Postcondition: Performs input validation and solicits user input and assigns that
 * value to global variable dayofweek*/

void getMonth(int& month);
/* Postcondition: Performs input validation and solicits user input and assigns that
 * value to global variable month*/

void getYear(int& year);
/* Postcondition: Performs input validation and solicits user input and assigns that
 * value to global variable year*/

void getDay(int& day);
/* Postcondition: Performs input validation and solicits user input and assigns that
 * value to global variable day*/

// main function

int main()
{
    using namespace std;
    int choice;
    int day, dayofweek, month, year;

    do
    {
        testMenu();
        cout << "Please choose from menu: ";
        cin >> choice;
        while (cin.fail() || !(choice <= 7 && choice >= 1)) //input validation
        {
            cout << "Invalid entry." << endl;
            testMenu();
            cout << "Please choose from menu: (1-7)" << endl;
            cin.clear();
            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            cin >> choice;
        }

        switch (choice)
        {
            case 1: // check if a given year is a leap year
                cout << "Please enter a year: ";
                getYear(year);
                if (isLeapYear(year))
                    cout << "Year " << year << " is a leap year" << endl;
                else
                    cout << "Year " << year << " is NOT a leap year" << endl;
                break;
            case 2: // calculate the century value of a given year
                cout << "Please enter a year.";
                getYear(year);
                cout << "The century value is: " << getCenturyValue(year) << endl;
                break;
            case 3: // calculate the year value of a given year
                cout << "Please enter a year.";
                getYear(year);
                cout << "The year value is: " << getYearValue(year) << endl;
                break;
            case 4: // calculate the month value of a given month in a given year
                cout << "Please enter a year.";
                getYear(year);
                cout << "\nPlease enter a month.";
                getMonth(month);
                cout << "The month value is: " << getMonthValue(month, year) << endl;
                break;
            case 5:  // calculate the day of week of a given date
                cout << "Please enter a year.";
                getYear(year);
                cout << "\nPlease enter a month.";
                getMonth(month);
                cout << "\nPlease enter a day.";
                getDay(day);
                cout << "The day of the week is: " << dayOfWeek(month, day, year) << endl;
                break;
            case 6:  // print out the name of a given day of week
                cout << "Please enter a day of week (0 for Sunday, 1 for Monday, etc): ";
                getDayofWeek(dayofweek);
                cout << "The name of the day of the week is: " << dayOfWeek(dayofweek) << endl;
                break;
            case 7:
                cout << "Did you tested all functions yet ? if not, please rerun the program" << endl;
                break;
        }
    }while (choice != 7);

    return 0;
}

// function definitions

void testMenu()
{
    using namespace std;
    cout << "*************************************" << endl;
    cout << "* Test Menu *" << endl;
    cout << "* 1. isLeapYear *" << endl;
    cout << "* 2. getCenturyValue *" << endl;
    cout << "* 3. getYearValue *" << endl;
    cout << "* 4. getMonthValue *" << endl;
    cout << "* 5. dayOfWeek(month, day, year) *" << endl;
    cout << "* 6. dayOfWeek(day) *" << endl;
    cout << "* 7. Quit *" << endl;

    return;
}

bool isLeapYear(int year)
{
    if (0 == (year % 400) || (0 == (year % 4) && (year % 100)))
        return true;
    else
        return false;
}

int getCenturyValue(int year)
{
    return (3 - ((year/100) % 4)) * 2;
}

int getYearValue(int year)
{
    int centuryYears;
    centuryYears = year % 100; // how many years since the turn of the last century
    return centuryYears + (centuryYears/4);
}

int getMonthValue(int month, int year)
{
    switch(month)
    {
        case 1:
            if (isLeapYear(year))
                return 6;
        case 10:
            return 0;
        case 5:
            return 1;
        case 8:
            return 2;
        case 2:
            if (isLeapYear(year))
                return 2;
        case 3:
        case 11:
            return 3;
        case 6:
            return 4;
        case 9:
        case 12:
            return 5;
        case 4:
        case 7:
            return 6;
        default:
            return -1;
    }
}

int dayOfWeek(int month, int day, int year)
{
    return ( (day + getMonthValue(month, year) + getYearValue(year) + getCenturyValue(year)) % 7);
}

std::string dayOfWeek(int day)
{
    using namespace std;
    string days[7] = {"Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday"};
    return days[day];
}

void getDayofWeek(int& day)
{
    using namespace std;
    cin >> day;
    while (cin.fail() || !(day <= 6 && day >= 0)) //input validation
    {
        cout << "Invalid entry." << endl;
        cout << "Please enter day.  e.g. Sunday=0, Monday=1 ... Saturday=6." << endl;
        cin.clear();
        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        cin >> day;
    }
    return;
}

void getMonth(int& month)
{
    using namespace std;
    cin >> month;
    while (cin.fail() || !(month <= 12 && month >= 1)) //input validation
    {
        cout << "Invalid entry." << endl;
        cout << "Please enter month.  e.g. Jan=1, Feb=2 ... Dec=12." << endl;
        cin.clear();
        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        cin >> month;
    }
    return;
}

void getYear(int& year)
{
    using namespace std;
    cin >> year;
    while (cin.fail() || (year <= 1582)) //input validation
    {
        cout << "Invalid entry." << endl;
        cout << "Please enter any year after 1582." << endl;
        cin.clear();
        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        cin >> year;
    }
    return;
}

void getDay(int& day)
{
    using namespace std;
    cin >> day;
    while (cin.fail()) //input validation
    {
        cout << "Invalid entry." << endl;
        cout << "Please enter a valid day of the month." << endl;
        cin.clear();
        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        cin >> day;
    }

    // Possible future expansion of this function to validate user input for the given month and year.
    // e.g. entering 29 Feb during a non leap year or June 31
}