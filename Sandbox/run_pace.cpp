// run_pace.cpp
// a program that takes running speed and
// outputs mile pace (min and sec)

#include <iostream>
using namespace std;

int main()
{
    double speed, pace, pace_min, pace_sec;
    cout << "Welcome to the running pace calculator.\n\n";
    cout << "Enter running speed (mph):\n";
    cin >> speed;

    pace = (1/speed)*(60);//converts speed to minutes per mile

    pace_min = static_cast<int>(pace);
    pace_sec = static_cast<int>((pace - pace_min) * 60);

    cout << "\n";
    cout << "A speed of " << speed << " mph is a pace of " << pace_min
    << " minutes and " << pace_sec << " seconds per mile."  << endl;
}

