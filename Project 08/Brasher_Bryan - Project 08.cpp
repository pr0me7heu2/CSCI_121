// Brasher, Bryan R
// 29-APR-2019
// Project 8

#include <iostream>
#include <vector>
#include <string>
#include <limits>
#include <cctype>

using namespace std;

void get_scores(vector<int> &v);
// get integer scores from keyboard and store in v; we assume that the user will input scores in range
// of 0 to 100, inclusive. User enter a negative number to stop the input and end the function

void print_stats(const vector<int> &v);
// Precondition: vector v has been initialized and declared and is of type int
// Postcondition: prints the maximum, minimum, and average value of the vector; if vector is empty
// output will indicate that no scores were entered by the user

int max(const vector<int> &v);
// Precondition: vector v has been initialized and declared and is of type int
// Postconditon: returns the maximum value of the vector

int min(const vector<int> &v);
// Precondition: vector v has been initialized and declared and is of type int
// Postconditon: returns the minimum value of the vector

double avg(const vector<int> &v);
// Precondition: vector v has been initialized and declared and is of type int
// Postconditon: returns the average value of the vector

void get_sentence(string &sentence);
// Precondition: sentence has been initialized and declared and is of type string
// Postcondition: solicits user input for sentence and declares that input for sentence

bool is_palindrome(const string &sentence);
// Precondition: sentence has been initialized and declared and is of type string
// Postcondition: returns true if sentence is a palindrome; false otherwise

string make_lower(const string &sentence);
// Precondition:  sentence has been initialized and declared and is of type string
// Postcondition: returns sentence with all uppercase characters changed to lowercase

string reverse(const string &sentence);
// Precondition:  sentence has been initialized and declared and is of type string
// Postcondition: returns sentence reversed

string remove_punct(const string &sentence);
// Precondition:  sentence and punct has been initialized and declared and is of type string
// Postcondition: returns sentence with occurences of charcters in punct removed

void swap(char& v1, char& v2);
// Interchanges the values of v1 and v2

int main()
{
    cout << "Welcome to Project 08."  << endl;
    cout << "I hope that you have fun." << endl;
    
    vector<int> v;
    char repeat;
    string sentence;

    do
    {
        get_scores(v);

        print_stats(v);

        do
        {
            cout << "Do you want to try another set of scores? (y/n)" << endl;
            cin >> repeat;
        }while(repeat != 'y' && repeat != 'Y' &&  repeat != 'n' && repeat != 'N');

    }while(repeat == 'y' || repeat == 'Y');


    do
    {
        get_sentence(sentence);

        if (is_palindrome(sentence) == 1)
        {
            cout << sentence << " is a palindrome!" << endl;
        }
        else
        {
            cout << sentence << " is not a palindrome!" << endl;
        }

        do
        {
            cout << "Do you want to try another sentence? (y/n)" << endl;
            cin >> repeat;
        }while(repeat != 'y' && repeat != 'Y' &&  repeat != 'n' && repeat != 'N');

    }while(repeat == 'y' || repeat == 'Y');

    cout << "Thanks for stopping by!" << endl;

return 0;

}

void get_scores(vector<int> &v)
{
    cout << "Enter a list of scores (100 or less) separated by a space." << endl;
    cout << "When you are complete, end the list with -1" << endl;

    int next;
    int count(0);

    cin >> next;

    while (cin.fail())
    {
        cout << "Invalid entry found and skipped." << endl;
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), ' ');
        cin >> next;
    }

    while (next > 0 && count <= 100)
    {
        v.push_back(next);
        cin >> next;
        while (cin.fail())
        {
            cout << "Invalid entry found and skipped." << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), ' ');
            cin >> next;
        }
        count++;
    }

    cout << "You entered " << v.size() << " scores." << endl;

    return;
}

void print_stats(const vector<int> &v)
{
    cout.setf(ios::fixed);
    cout.setf(ios::showpoint);
    cout.precision(2);
    cout << "The maximum score is " << max(v) << "." << endl;
    cout << "The minumum score is " << min(v) << "." << endl;
    cout << "The average score is " << avg(v) << "." << endl;

    return;
}

int max(const vector<int> &v)
{
    int max=v[0];

    for (int i = 0; i < v.size(); i++)
    {
        if (max < v[i])
        {
            max = v[i];
        }
    }
    return max;
}


int min(const vector<int> &v)
{
    int min=v[0];

    for (int i = 0; i < v.size(); i++)
    {
        if (min > v[i])
        {
            min = v[i];
        }
    }
    return min;
}

double avg(const vector<int> &v)
{
    double total(0.0);

    for (int i = 0; i < v.size(); i++)
    {
        total += v[i];
    }

    return total/v.size();
}


void get_sentence(string &sentence)
{
    cout << "Enter a sentence:" << endl;

    cin.ignore();  // ignores newline character left in the input stream!
    getline(cin, sentence);

    return;
}

void swap(char& v1, char& v2)
{
    char temp = v1;
    v1 = v2;
    v2 = temp;

    return;
}

string reverse(const string &sentence)
{
    int start = 0;
    int end = sentence.length();

    string temp(sentence);

    while (start < end)
    {
        end--;
        swap(temp[start],temp[end]);
        start++;
    }

    return temp;
}

string make_lower(const string &sentence)
{
    string temp(sentence);

    for (int i = 0; i < sentence.length(); i++)
    {
        temp[i]=tolower(sentence[i]);
    }

    return temp;
}

string remove_punct(const string &sentence)
{
    string no_punct;
    string punct = ",;:.?!'\" ";

    for (int i = 0; i < sentence.length(); i++)
    {
        string a_char = sentence.substr(i,1);
        int location = punct.find(a_char, 0);

        if (location < 0 || location >= punct.length())
            no_punct = no_punct + a_char;
    }

    return  no_punct;
}

bool is_palindrome(const string &sentence)
{
    string str(sentence);
    str = make_lower(str);
    str = remove_punct(str);

    return (str == reverse(str));
}







