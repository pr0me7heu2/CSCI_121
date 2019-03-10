//
// Created by bryan on 2/10/19.
//
#include <iostream>

double total_inches(int feet, int inches)
{
    inches = 12 * feet + inches;
    return inches;
}

int main()
{
    using namespace std;

    int n1, n2;



    cout << "how many" << endl;
    cin >> n1 >> n2;

    cout << total_inches(n1,n2);

    return 0;

}