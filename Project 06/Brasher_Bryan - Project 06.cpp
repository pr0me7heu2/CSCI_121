// Brasher, Bryan R
// 08-APR-2019
// Project 6

/* Q1: isValid(int month, int day, int year) returns a boolean value.  1 if the date combination is valid; 0 if not.
 * The function verifies that there are a valid number of days for the month given e.g. there are only 30 days in April,
 * June, September, and November.  The function uses the isLeapYear() function to determine whether 29 is a valid number
 * of days for February.  And finally, the function returns the boolean values from the switch statement with the
 * isValid() function to validate the month and year input together.
 *
 * Q2: print_calendar(int month, int day, int year) returns a day of the week given a valid month, day, and year
 * combination.  The validation is based on isValid() function.  If valid the function prints to stdout the inputted
 * (spelled out using monthName()) month, numerical day, and numerical year and the calculated day of the week that is
 * calculated using Gauss’ algorithm using the dayOfWeek(month, day, year) function.  The int return from
 * dayOfWeek(month, day, year) function is input to dayOfWeek(int day) to return a string of the spelled out day of the
 * week.
 *
 * Q3: While I did not actually use this in Project 5, this is pretty clear.  Use a switch statement and general
 * knowledge about leap years and months of the year to return how many days there are for each month.  For the case of
 * February (month = 2)  the function uses isLeapYear() function to determine whether there are 28 or 29 days for the
 * provided year.
 *
 * NOTE: I may have been confused somewhat by the instructions. As I read through the template, it keeps making me think
 * that there is only only function that I need to implement but there are clearly two functions left undefined: one
 * function that writes to a local ofstream using a user-defined string filename and another that, given the provided
 * paramters, I assume, uses a global ofstream.  This is why things look a little weird i.e. two different file streams.
 * Not sure if I got the point.  Thanks for your time!
 * */


#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
#include <limits>
using namespace std;

void get_input(int& month, int& day, int& year);
// post-condition: get the input of a date. If the date is NOT valid, will prompt the user to reenter a valid date
// I really like the overloading of the functions - I wish I would have thought about
// how obvious that was when I was writing Project 5!

void get_input(int& month, int& year);
// post-condition: get the input of a month. If the month is NOT valid, will prompt the user to reenter a valid month

void get_input(int& year);
// post-condition: get the input of a year. If the date is NOT valid, will prompt the user to reenter a valid year.
//                 the year must be later than 1582 in order to be valid.

bool isValid(int month, int day, int year);
// post-condition: return true if the specified date is valid, false otherwise

bool isValid(int month, int year);
// post-condition: return if the specified month is valid, false othewise

bool isValid(int year);
// post-condition: return true if the given year is valid. false otherwise.
//				   the given year is valid if it is later than year 1582.

void print_calendar(int month, int day, int year);
// pre-condition:  the date is a valid date
// post-condition: print out the day of week for specified date. For example, print_calendar(10, 15, 2014) will print out
//				  October 15, 2014 is Wednesday

void print_calendar(int month, int year);
// pre-condition: the month is a valid month, and the year is a valid year
// post-condition: print out the calendar of specified month

void print_calendar(int year);
// pre-condition: the year is a valid year
// post-condition: print out the calendar of specified year

string monthName(int month);
// pre-condition: the month value is 1, 2, .., 12
// post-condition: return a string that represents the name of the month. If month is 1, the name is "January" and so on

int daysInMonth(int month, int year);
// pre-condition: the month and year are valid
// post-condition: return the number of days in the given month in given year

void menu();
// post-condition: the menu is displayed for choose

bool isLeapYear(int year);
// pre-condition: the year is valid
// post-condition: return true if the year is leap year; false otherwise

int getCenturyValue(int year);
// pre-condition: the year is valid
// post-condition: return the century value of the given year.

int getYearValue(int year);
// pre-condition: the year is valid
// post-condition: return the year value of the given year.

int getMonthValue(int month, int year);
// pre-condition: the month and year are valid
// post-condition: return the month value of the given month in given year.

int dayOfWeek(int month, int day, int year);
// pre-condition: the date is valid
// post-condition: return 0 if the date is Sunday, 1 if the date is Monday and so on

string dayOfWeek(int day);
// pre-condition: day has integer value 0, 1, 2, 3, 4, 5, or 6
// post-condition: the name of the day of week is returned as a string.
//                If day has value 0, then SUNDAY is returned; 1, then MONDAY is returned
//                and so on

//************************************************************************
// You may have implemented all functions above for project 5
// Implementation all functions above are given in this file
// They are the solution for Project 5 and more.
// You must implement the functions below. Also, you must change the menu
// option accordingly and add one more case in main function
// ***********************************************************************


bool print_calendar(int year, string fileName);
// pre-condition: year is a legal year, and fileName is the name of output file
// post-condition: if the calendar of the given year is successfully output to the file
// with name fileName, return true; false otherwise

string getFileName();
// pre-condition: none
// post-condition: user has been prompted to supply a filename in the local directory
// and filename has been returned with validation and .txt extension

void print_calendar(int month, int year, ofstream& output);
// pre-condition: month is a legal month in a given legal year and output is an ofstream
// that connected to a successfully opened file
// post-condition: the calendar of the given month of given year is output to a file
// through the output.

int main()
{
    char choice;
    int day, month, year;

    ofstream goutput;

    goutput.open("brbrasher.txt");

    if (goutput.fail())
    {
        cout << "Output file opening failed." << endl;
        exit(1);
    }

    do
    {
        //system("clear");  suppressed while running in Linux to avoid "TERM environment variable not set" and other
        // errors
        menu();// display menu by calling menu function
        cout<<"\n\tPlease enter your choice: ";// ask user to enter his/her choice on menu
        cin>>choice;// get user's choice
        switch(choice)
        {
            case '1': // will query a date.
                get_input(month, day, year);
                print_calendar(month, day, year);// print out the day of week of specified date
                break;
            case '2': // print out the calendar of a given month.
                get_input(month, year);
                print_calendar(month, year);//print out the calendar of specified month
                break;
            case '3': // print out the calendar of a given year.
                get_input(year);
                print_calendar(year);// print out the calendar of specified year
                break;
            case '4': // print out the calendar of specified year to yourname.txt file
                get_input(year);
                print_calendar(year,getFileName());
                break;
            case '5': // print out the calendar of specified year and month to global ofstream
                get_input(month, year);
                print_calendar(month,  year, goutput);
                break;
            case '6': // quit the program.
                cout<<"\n\tThank you for using FHSU's calendar program!\n\n"; // you may replace your name here
                break;
            default: // other choices that are not the options on menu.
                cout<<"Error, no such choice. Please choose from Menu.\n";//print out error message
                break;
        }
        cout << "\n\n\t";
        //system("read -n 1 -rsp $'Press enter to continue...\\a\\n'\'");
    }while (choice != '6');

    goutput.close();

    return 0;
}

// you implement all function stubs here
void menu()
{
    cout << "\n\t***************************************************";
    cout << "\n\t*                   Menu                          *";
    cout << "\n\t* 1. Query a date                                 *";
    cout << "\n\t* 2. Print calendar of a given month              *";
    cout << "\n\t* 3. Print calendar of a given year               *";
    cout << "\n\t* 4. Print calendar of a given year to file       *";
    cout << "\n\t* 5. Print a calendar of a given month to file    *";
    cout << "\n\t* 6. Quit                                         *";
    cout << "\n\t***************************************************";
}

void get_input(int& month, int& day, int& year)
{
    cout << "\n\tEnter the date in form of mm dd yyyy: ";
    cin >> month >> day >> year;
    while(!isValid(month, day, year)) // as long as the date is NOT valid, keep asking to reenter the date
    {
        cout << "\n\tThe date you entered is NOT valid. Please reenter a valid date: ";
        cin >> month >> day >> year;
    }
}

void get_input(int& month, int& year)
{
    cout << "\n\tEnter the month and year in form of mm yyyy: ";
    cin >> month >> year;
    while(!isValid(month, year)) // as long as the month is NOT valid, keep asking to reenter the month
    {
        cout << "\n\tThe month you entered is NOT valid. Please reenter a valid month: ";
        cin >> month >> year;
    }
}

void get_input(int& year)
{
    cout << "\n\tEnter the year as yyyy: ";
    cin >> year;
    while(!isValid(year)) // as long as the year is NOT valid, keep asking to reenter the year
    {
        cout << "\n\tThe year you entered is NOT valid. Please reenter a valid year: ";
        cin >> year;
    }
}

bool isValid(int month, int day, int year)
{
    // Questions 1: Please answer (YES/NO) to indicate if you understand this implementation
    //              by adding one line of comments at beginning of the file. This worth 1 point

    bool result = true; // temporary assume that the result is true
    switch(month) // update result based on day
    {
        case 1: case 3: case 5: case 7: case 8: case 10: case 12:
            result = day >= 1 && day <= 31;
            break;
        case 4: case 6: case 9: case 11:
            result = day >= 1 && day <= 30;
            break;
        case 2:
            if(isLeapYear(year))
                result = day >= 1 && day <= 29;
            else
                result = day >= 1 && day <= 28;
            break;
    }
    return result && isValid(month, year); // day is valid and (month and year are valid)
}

bool isValid(int month, int year)
{
    return month >= 1 && month <= 12 && year > 1582; // month is between 1 and 12 and year is later than 1582
}

bool isValid(int year)
{
    return year > 1582; // year is later than 1582
}

bool isLeapYear(int year)
{
    return ((year % 400 == 0) || (year % 4 == 0 && year % 100 != 0)); // book's instruction
}

int getCenturyValue(int year)
{
    return 2 * ( 3 - (year / 100) % 4 ) ; // book's instruction
}

int getYearValue(int year)
{
    return year % 100 + year % 100 / 4; // book's instruction
}

int getMonthValue(int month, int year) // book's instruction
{
    int result;
    switch(month)
    {
        case 1:
            if(isLeapYear(year))
                result = 6;
            else result = 0;
            break;
        case 2:
            if(isLeapYear(year))
                result = 2;
            else
                result = 3;
            break;
        case 3: case 11:
            result = 3;
            break;
        case 4: case 7:
            result = 6;
            break;
        case 5:
            result = 1;
            break;
        case 6:
            result = 4;
            break;
        case 8:
            result = 2;
            break;
        case 9:case 12:
            result = 5;
            break;
        default: // case 10
            result = 0;
            break;
    }
    return result;
}

int dayOfWeek(int month, int day, int year) // book's instruction
{
    if(!isValid(month, day, year)) return -1;
    return (getCenturyValue(year) + getMonthValue(month, year) + getYearValue(year)+ day)%7;
}

void print_calendar(int month, int day, int year)
{
    // Questions 2: Add one line of comments at the beginning of the file to indicate
    //              if you understand what the following if statement does? (YES/NO)
    //              This worth 1 point

    if(!isValid(month, day, year)){ // if the date is NOT valid, print out error message and return
        cout << "\n\tThe date is NOT valid!";
        return;
    }
    cout << "\n\t" <<  monthName(month) << " " << day << " , " << year << " is " << dayOfWeek(dayOfWeek(month, day, year));
}

void print_calendar(int month, int year)
{
    if(!isValid(month, year)){ // if the month is NOT valid, print out error message and return
        cout << "\n\tThe month is NOT valid!";
        return;
    }

    // print out the month and year
    cout << "\n\t " << monthName(month) << ", " << year << endl;
    // print out day names
    cout << "\n\t SUN MON TUE WED THU FRI SAT\n\t";
    int spaceCount = dayOfWeek(month, 1, year);
    // print out spaces
    for(int i = 0; i < spaceCount; i++)
        cout << setw(4) << "";
    // calculate the days in the month
    int days = daysInMonth(month, year);
    // print out all days
    for(int j = 1; j <= days; j++)
    {
        cout << setw(4) << j;
        if((spaceCount + j) % 7 == 0) // go to new line for a new week
            cout << "\n\t";
    }
}

void print_calendar(int year)
{
    if(!isValid(year)){ // if the year is NOT valid, print out error message and return
        cout << "\n\tThe year is NOT valid!";
        return;
    }

    for(int i = 1; i <= 12; i++) // print out 12 month calendar
    {
        print_calendar(i, year); // print out ith month
        cout << endl;
    }
}

string monthName(int month)
{
    string result;
    switch(month)
    {
        case 1:
            result = "January";
            break;
        case 2:
            result = "February";
            break;
        case 3:
            result = "March";
            break;
        case 4:
            result = "April";
            break;
        case 5:
            result = "May";
            break;
        case 6:
            result = "June";
            break;
        case 7:
            result = "July";
            break;
        case 8:
            result = "August";
            break;
        case 9:
            result = "September";
            break;
        case 10:
            result = "October";
            break;
        case 11:
            result = "November";
            break;
        case 12:
            result = "December";
            break;
        default:
            result = "Not valid month";
            break;
    }
    return result;
}

string dayOfWeek(int day)
{
    string result;
    switch(day)
    {
        case 0:
            result = "Sunday";
            break;
        case 1:
            result = "Monday";
            break;
        case 2:
            result = "Tuesday";
            break;
        case 3:
            result = "Wednesday";
            break;
        case 4:
            result = "Thursday";
            break;
        case 5:
            result = "Friday";
            break;
        case 6:
            result = "Saturday";
            break;
        default:
            result = "Invalid date";
            break;
    }
    return result;
}

int daysInMonth(int month, int year)
{
    // Question 3: Add one line of comment at the beginning to tell me
    //             if this implementation is the same as yours in Proj five
    //             If not, do you understand this? This worth 1 point

    int result;
    switch(month)
    {
        case 1: case 3: case 5: case 7: case 8: case 10: case 12:
            result = 31;
            break;
        case 4: case 6: case 9: case 11:
            result = 30;
            break;
        case 2:
            if(isLeapYear(year))
                result = 29;
            else result = 28;
            break;
        default:
            result = -1;
            break;
    }
    return result;
}

string getFileName()
{
    string file_name;
    cout << "Your data will be saved to your current working directory." << endl;
    cout << "Enter a filename." << endl;
    cin >> file_name;
    while (cin.fail())
    {
        cout << "Invalid entry." << endl;
        cout << "Try again." << endl;
        cin.clear();
        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        cin >> file_name;
    }

    return file_name + ".txt";
}
bool print_calendar(int year, string fileName)
{
    if(!isValid(year)){ // if the year is NOT valid, print out error message and return
        cout << "\n\tThe year is NOT valid!";
        return false;
    }

    ofstream loutput;

    loutput.open(fileName);

    if (loutput.fail())
    {
        cout << "Output file opening failed." << endl;
        return false;
    }

    for(int i = 1; i <= 12; i++) // print out 12 month calendar
    {
        print_calendar(i, year, loutput); // print out ith month
        cout << endl;
    }

    cout << "Data written successfully to " << fileName << "." << endl;
    cout << "NOTE: Running option 4 again with same fileName will overwrite this data." << endl;
    return true;
}

void print_calendar(int month, int year, ofstream& output)
{
    {
        if(!isValid(month, year)){ // if the month is NOT valid, print out error message and return
            cout << "\n\tThe month is NOT valid!";
            return;
        }

        // print out the month and year
        output << "\n\t " << monthName(month) << ", " << year << endl;
        // print out day names
        output << "\n\t SUN MON TUE WED THU FRI SAT\n\t";
        int spaceCount = dayOfWeek(month, 1, year);
        // print out spaces
        for(int i = 0; i < spaceCount; i++)
            output << setw(4) << "";
        // calculate the days in the month
        int days = daysInMonth(month, year);
        // print out all days
        for(int j = 1; j <= days; j++)
        {
            output << setw(4) << j;
            if((spaceCount + j) % 7 == 0) // go to new line for a new week
                output << "\n\t";
        }

        cout << "Data successfully written to brbrasher.txt." << endl;
        cout << "NOTE: Running Option 5 again will overwrite this data." << endl;
    }
}
