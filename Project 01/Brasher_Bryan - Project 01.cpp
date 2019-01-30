// Brasher, Bryan
// 2019-JAN-29
/* This is my first C++ program
 * and I am using multiline comments
 * CSCI 121 Computer Science 1 */

#include <iostream>
using namespace std;

int main()
{
    cout << "Hello, World!" << endl;
    //Capitalizing C in cout gives: error: ‘Cout’ was not declared in this scope
    cout << "This is my first C++ program." << endl;
    /*system() takes a command as a string and passes it to the OS's
    default shell.  Here I replaced "pause" with Linux read command
    that has the same effect desired by the system(pause) requirement.*/
    system("read -rsp $'Press enter to continue...\n'");
}