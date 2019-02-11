// Brasher, Bryan
// 2019-FEB-10
/* Given gender, height, weight, and age, this program
 * calculates an individual's basal metabolic rate (BMR) then
 * returns that relative to the calories in an average
 * chocolate bar.*/

#include <iostream>
#include <limits>
using namespace std;

int main()
{
    char repeat, gender;
    double age, weight, height, bmr;

    do
    {
        cout << "Your daily caloric needs in chocolate bars." << endl;
        cout << "This program will calculate your basal metabolic rate using the Harris-Benedict equation." << endl;

        //gender input
        cout << "Gender(M/F) ";
        cin >> gender;
        // while loop forces user to enter M||m||F||f
        while (gender != 'M' && gender != 'm' && gender != 'F' && gender != 'f')
        {
            cout << "Incorrect response." << endl;
            cout << "Please enter gender. (M/F) ";
            cin >> gender;
        }

        //age input
        cout << endl;
        cout << "Age (years) ";
        cin >> age;

        /*I wanted to ensure numeric inputs here and did some searching and found
         * out about cin.fail() which returns true if cin does not match data type,
         * cin.clear() which clears any error flags.  I had some issues getting cin.ignore()
         * to work without causing a loop.  The parameter in ignore sets the number of
         * characters to ignore and std::numeric_limits<std::streamsize>::max() makes
         * it ignore the upper limit on the size of the stream.  At this point, I am not
         * completely confident that I know that that really means. */

        while (cin.fail())
        {
            cout << "Please enter age in years. ";
            cin.clear();
            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            cin >> age;

        }

        //weight input
        cout << endl;
        cout << "Weight (pounds) ";
        cin >> weight;

        while (cin.fail())
        {
            cout << "Please enter weight in pounds. ";
            cin.clear();
            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            cin >> weight;

        }

        //height input
        cout << endl;
        cout << "Height (inches) ";
        cin >> height;

        while (cin.fail())
        {
            cout << "Please enter height in inches. ";
            cin.clear();
            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            cin >> height;

        }

        //calculation

        //male
        if (gender == 'M' || gender == 'm')
        {
            bmr = 66 + (6.3 * weight) + (12.9 * height) - (6.8 * age);
            cout << "He needs " << bmr << " calories to maintain his weight." << endl;
            cout << "That is equivalent to about " << bmr/230 << " chocolate bars." << endl;
        }
        //female
        else
        {
            bmr = 655 + (4.3 * weight) + (4.7 * height) - (4.7 * age);
            cout << "She needs " << bmr << " calories to maintain her weight." << endl;
            cout << "That is equivalent to about " << bmr/230 << " chocolate bars." << endl;
        }

        //repeat variable
        cout << "Would you like to do another calculation? (Y/N) ";
        cin >> repeat;

        while (repeat != 'Y' && repeat != 'y' && repeat != 'N' && repeat != 'n')
        {
            cout << "Incorrect response." << endl;
            cout << "Would you like to do another calculation? (Y/N) ";
            cin >> repeat;
        }

    }while(repeat == 'Y' || repeat == 'y');

}
