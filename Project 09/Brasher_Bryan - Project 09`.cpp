// Brasher, Bryan R
// 02-MAY-2019
/* This project builds design skill in recursive functions.  At execution, this code
 * will interact with user via standard I/O to calculate the value of a finite series
 * 1 + 2 + 3 + ... + n and the character length of a C-String through the use of two
 * recursive functions. */

#include <iostream>
#include <limits>


void get_number(int& n);
// Solicits user input to declare n


void print_sum(const int n);
// Prints the results of sum() to std out

int sum(const int n);
// Precondition: n is a positive integer
// Postcondition: returns the sum 1 + 2 + ... + n and



void print_length(const char s[]);
// Prints the results of str_length to std out

int str_length(const char s[]);
// Precondition: s[] is a C-String i.e. null-terminated string that has been
// declared and initialized
// Postcondition: returns the number of characters (excluding the null character)


int main()
{
    using namespace std;
    char s[100];   //sentences must be less than 100 characters
    char next;
    char repeat;
    int n;

    do
    {
        get_number(n);

        print_sum(n);

        do
        {
            cout << "Do you want to have another run? (y/n)" << endl;
            cin >> repeat;
        }while(repeat != 'y' && repeat != 'Y' &&  repeat != 'n' && repeat != 'N');

    }while(repeat == 'y' || repeat == 'Y');


    do
    {
        cout << "Enter a sentence: ";

        cin.ignore();  //clear stream
        cin.getline(s,100);

        print_length(s);

        do
        {
            cout << "Do you want to have another run? (y/n)" << endl;
            cin >> repeat;
        }while(repeat != 'y' && repeat != 'Y' &&  repeat != 'n' && repeat != 'N');

    }while(repeat == 'y' || repeat == 'Y');

    return 0;
}

void get_number(int& n)
{
    using namespace std;

    cout << "Enter a positive integer: ";
    cin >> n;
    while (cin.fail() || n < 0)
    {
        cout << "Invalid entry.  Please enter a positive integer." << endl;
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), ' ');
        cin >> n;
    }

    return;
}

void print_sum(const int n)
{
    using namespace std;

    if (n==0 || n==1)
        cout << "The sum is: " << sum(n) << endl;
    else if (n==2)
        cout << "The sum of 1+2 is: " << sum(n) << endl;
    else if (n==3)
        cout << "The sum of 1+2+3 is: " << sum(n) << endl;
    else
        cout << "The sum of 1+2+...+" << n << " is: " << sum(n) << endl;

    return;
}

int sum(const int n)
{
    using namespace std;

    if (n==0)
        return 0;
    else
        return (n + sum(n-1));
}


void print_length(const char s[])
{
    using namespace std;

    cout << "It contains " << str_length(s) << " chararacters including white space." << endl;

    return;
}

int str_length(const char s[])
{
    using namespace std;

    if (s[0] == '\0')
        return 0;
    else
        return(1 + str_length(s+1));

}