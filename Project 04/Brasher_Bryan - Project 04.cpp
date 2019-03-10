// Brasher, Bryan
// 10-MAR-2019
/* This program returns the anticipated temperature inside the Earth given
 * a user supplies depth.  This program assumes a constant geothermal gradient
 * and also assumes a linear depth-to-temperature relationship. */

#include <iostream>
#include <limits>

// function declarations

void print_introduction();
/* print_introduction takes no arguments and displays to std out instructions
 * for the user. */

double get_depth();
/* get_depth prompts user for desired depth and validates input to ensure that only positive
 * integer or positive float numbers are entered.  Function returns depth. */

double celsius_at_depth(double depth_km);
/* celsius_at_depth takes depth (in kilometers) and returns temperature (in celsius).
 * Input may be integer or floating point.  Uses linear relationship 10*depth+20. */

double celsius_to_fahrenheit(double temp_celsius);
/* celsius_to_fahrenheit converts a temperature from celsius to fahrenheit. */

void print_conclusion(double depth_km);
/* print_conclusion passes values to celsius_at_depth and celsius_to_fahrenheit
 * and displays to std out the intended temperature information. */

void repeat();
/* return asks user if they wish to rerun program.  If answer is in the affirmative,
 * executes main(), else does nothing. */

// main function

int main()
{
    using namespace std;

    double depth;

    print_introduction();

    cout << "How far down would you like to go?" << endl;
    cout << "Enter a depth (km)" << endl;

    depth = get_depth();

    print_conclusion(depth);

    repeat();

    return 0;

}

// function definitions

void print_introduction()
{
    using namespace std;
    cout << "Welcome to the geothermal gradient calculator!" << endl;
    cout << "Temperature within the Earth increases with depth." << endl;
    cout << "This program uses a linear geothermal gradient to calculate temperature as a function of depth.\n" << endl;
}

double get_depth()
{
    using namespace std;

    double depth;

    cin >> depth;

    while (cin.fail() || depth < 0 || depth > 6400)  // ensures that input is valid for data type and
                                                     // that it is valid for the Earth i.e. no negative,
                                                     // can't be too big
    {
        cout << "That is an invalid entry." << endl;
        cout << "Please enter a positive depth (in km) between 0 and 6400."<< endl;
        cout << "0 km would be at the Earth's surface and 6400 km would be at the center of the Earth." << endl;
        cin.clear();
        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        cin >> depth;
    }

    return depth;
}

double celsius_at_depth(double depth_km)
{
    return (10 * depth_km + 20);
}

double celsius_to_fahrenheit(double temp_celsius)
{
    return (1.8 * temp_celsius + 32);
}

void print_conclusion(double depth_km)
{
    using namespace std;

    cout.setf(ios::fixed);       // sets floating point precision to 2
    cout.setf(ios::showpoint);   // although temp formula lacks the precision, this prevents user
    cout.precision(2);           // from cluttering screen by entering in a very large decimal for depth


    cout << "The temperature of the Earth at a depth of " << depth_km << " km:" << endl;
    cout << celsius_at_depth(depth_km) << " deg C (" << celsius_to_fahrenheit(celsius_at_depth(depth_km))
    << " deg F)." << endl;
}

void repeat()
{
    using namespace std;
    char repeat;

    do
    {
        cout << "Would you like to do another calculation? (y/n) " << endl;
        cin >> repeat;

    }while(repeat != 'y' && repeat != 'Y' &&  repeat != 'n' && repeat != 'N');  // input validation

    if (repeat == 'y' || repeat == 'Y')
        main();  // repeats program
}

