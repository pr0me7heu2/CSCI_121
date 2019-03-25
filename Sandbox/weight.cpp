/* Programming Project 5.9
 * User inputs a weight in lbs and/or ounces and
 * this weight is converted to kilograms and grams. */

#include <iostream>
#include <limits>


void print_intro();
// prints introduction to the program with instructions to user

void input(double& weight);
// Precondition: Requires that weight has been declared.
// Postcondition: Weight is the lbs that user wants to convert.
// User supplies lbs and oz in integer format and this function
// returns changes the value of weight to reflect this.

void kg_calc (double weight, double& kg);
// Precondition: requires that weight has been declared.
// Postcondition: Takes weight input (lbs) and converts the kg and
// assigns this value to variable kg.

double g_calc(double kg);
// Precondition: requires that input is a mass in kilograms
// Postcondition: outputs the equivalent mass in grams.

void output(double kg, double g);
// prints results to the screen.

void rerun();
// Asks user if they wish to rerun the program.

int main()

{
    double weight, kg, g;

    print_intro();

    input(weight);

    kg_calc(weight, kg);

    g = g_calc(kg);

    output(kg, g);

    rerun();

    return 0;
}

void print_intro()
{
    using namespace std;

    cout << "Welcome to the weight calculator"  << endl;
    cout << "You will enter a weight in whole pounds and ounces." << endl;
    return;
}

void input(double& weight)
{
    using namespace std;
    int lb, oz;

    cout << "Weight in whole (integer) pounds and ounces (separated by a space)" << endl;
    cin >> lb >> oz;

    while (cin.fail())
    {
        cout << "That is an invalid entry." << endl;
        cout << "Enter Weight in whole (integer) pounds and ounces (separated by a space)" << endl;
        cin.clear();
        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        cin >> lb >> oz;
    }

    //converts lb and oz to a single lb measurement
    weight = (lb) + static_cast<double>(oz)/16;

    return;
}

void kg_calc(double weight, double& kg)
{
    kg = weight / 2.2046;
    return;
}

double g_calc(double kg)
{
    return kg*1000;
}

void output(double kg, double g)
{
    using namespace std;
    cout.setf(ios::fixed);
    cout.setf(ios::showpoint);
    cout.precision(3);

    cout << "For objects on the surface of the Earth, that is equivalent to:" << endl;
    cout << kg << " kilograms (" << g << " grams)." << endl;

    return;
}

void rerun()
{
    using namespace std;

    char repeat;

    do
    {
        cout << "Would you like to do another calculation? (y/n) ";
        cin >> repeat;
    } while(repeat != 'y' && repeat != 'Y' &&  repeat != 'n' && repeat != 'N');

    if (repeat == 'y' || repeat == 'Y')
        main();
}



