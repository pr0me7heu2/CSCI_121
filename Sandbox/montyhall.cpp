//
// Created by bryan on 2/23/19.
//

#include <iostream>
#include <cstdlib> //access rand() function
#include <ctime> //access time for seed value
using namespace std;

int main()
{
    srand(time(NULL)); //current time on the clock
    int win_stay(0), win_switch(0), count(0);

    for (int j=0; j<10000; j++)
    {
        //door for the prize
        int prize = rand() %3;
        //door for the contestant's choice
        int choice = rand() %3;
        int reveal;

        do
        {
            reveal = rand() %3;
        } while( (reveal == prize) || (reveal == choice));

        //find the door to switch to

        int switch_door;

        //assigns switch_door to the door not chosen by reveal and choice
        for (int i = 0; i<3; i++)
        {
            if ((i!=reveal) && (i!=choice))
            {
                switch_door = i;
            }
        }

        if (prize == choice)
        {
            win_stay++;
            count++;
            cout << "Run: " << count << ".  Stay." << endl;
        }
        else if (prize == switch_door)
        {
            win_switch++;
            count++;
            cout << "Run: " << count << " Switch." << endl;
        }

    }
    cout << "\n\n" << endl;
    cout << "The probability of winning by sticking with your original choice is "
    << win_stay / 10000.0 << "." << endl;
    cout << "The probability of winning by switching is "
    << win_switch / 10000.0 << "." << endl;

   char choice;

    cout << "\nWould you like to run the simulation again? (y/n)\n" << endl;
    cin >> choice;

    while ( (choice !='y') && (choice !='n'))
    {
        cout << "Invalid response.  Please try again (y/n).";
        cin >> choice;
    }

    if (choice == 'y')
        main();
    else if (choice == 'n')
        return 0;

}
