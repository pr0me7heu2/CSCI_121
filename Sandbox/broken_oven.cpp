//
// Created by bryan on 2/23/19.
/* Oven temperature input is similar format of phone with left side e.g. 1,4,7 broken.
 * Returns the nearest temperatures larger and smaller that do not contain these. */

#include <iostream>
using namespace std;

int main() {
    int desired_temp, temp_up, temp_down;
    bool isHunGood(true), isTenGood(true), isOneGood(true);
    bool isUpHunGood, isUpTenGood, isUpOneGood;
    bool isDnHunGood, isDnTenGood, isDnOneGood;

    cout << "I am sorry that your oven is broken." << endl;
    cout << "Enter your desired temperature." << endl;
    cin >> desired_temp;

    if ((desired_temp % 10 == 1) || (desired_temp % 10 == 4) || (desired_temp % 10 == 7))
        isOneGood = false;
    if ((desired_temp/10 % 10 == 1) || (desired_temp/10 % 10 == 4) || (desired_temp/10 % 10 == 7))
        isTenGood = false;
    if ((desired_temp / 100 == 1) || (desired_temp / 100 == 4) || (desired_temp / 100 == 7))
        isHunGood = false;

    if  (isOneGood && isTenGood && isHunGood)
    {
        cout << "No adjustments needed.  Enter " << desired_temp << " degrees." << endl;
    }
    else
        {
            temp_up = desired_temp;
            temp_down = desired_temp;

            do
                {
                temp_up++;
                if ((temp_up % 10 == 1) || (temp_up % 10 == 4) || (temp_up % 10 == 7))
                    isUpOneGood = false;
                else
                    isUpOneGood = true;
                if ((temp_up/10 % 10 == 1) || (temp_up/10 % 10 == 4) || (temp_up/10 % 10 == 7))
                    isUpTenGood = false;
                else
                    isUpTenGood = true;
                if ((temp_up / 100 == 1) || (temp_up / 100 == 4) || (temp_up / 100 == 7))
                    isUpHunGood = false;
                else
                    isUpHunGood = true;

                }while (!isUpOneGood || !isUpTenGood || !isUpHunGood);


            do
                {
                temp_down--;
                if ((temp_down % 10 == 1) || (temp_down % 10 == 4) || (temp_down % 10 == 7))
                    isDnOneGood = false;
                else
                    isDnOneGood = true;
                if ((temp_down/10 % 10 == 1) || (temp_down/10 % 10 == 4) || (temp_down/10 % 10 == 7))
                    isDnTenGood = false;
                else
                    isDnTenGood = true;
                if ((temp_down / 100 == 1) || (temp_down / 100 == 4) || (temp_down / 100 == 7))
                    isDnHunGood = false;
                else
                    isDnHunGood = true;
                } while (!isDnOneGood || !isDnTenGood || !isDnHunGood);

            cout << "The nearest higher temperature is " << temp_up << " degrees." << endl;
            cout << "That's a difference of " << temp_up - desired_temp << " degrees.\n" << endl;

            cout << "The nearest cooler temperature is " << temp_down << " degrees." << endl;
            cout << "That's a difference of " << desired_temp - temp_down << " degrees.\n" << endl;
        }

    return 0;
}

