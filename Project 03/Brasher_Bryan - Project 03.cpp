// Brasher, Bryan
// 2019-FEB-24
/* This is a game of 23 between a human player who provides input and a simulated player
 * whose actions are based on a set of rules.  Player who chooses the last stick loses. */

#include <iostream>
#include <limits>
using namespace std;

int main() 
{
  cout << "Shall we play a game?" << endl;
  cout << "How about a nice game of 23?\n\n"  << endl;
  cout << "There are 23 sticks.  You go first.\n" << endl;

  // variables for sticks remaining, and how many human and computer are going to draw
  int t(23), human_choice, comp_choice;
  // variable for repeat response
  char response;

  while (t > 0)
  {
      cout << "Enter the number of sticks that you wish to pick." << endl;
      cin >> human_choice;

      // input validation to ensure that only integers are entered by the player and that
      // player does not validate rules of the game i.e. pick too many sticks
      while (cin.fail() || human_choice > t || human_choice > 3 || human_choice == 0)
      {
          cout << "That is an invalid entry." << endl;
          cout << "Your input must  be the WHOLE NUMBER of sticks that you want to pick." << endl;
          cout << "You can not pick more than 3 sticks or more than the number that remain."  << endl;
          cout << "You are not allowed to skip your turn i.e. pick zero sticks." << endl;
          cout << "Enter the number of sticks that you wish to pick." << endl;
          cin.clear();
          cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
          cin >> human_choice;
      }

      //update sticks remaining
      t -= human_choice;

      //update player on game status
      cout << "You drew " << human_choice << ". " << endl;

      // apply computer rules
      if (t == 0) //computer wins
      {
          cout << "You picked the last stick!" << endl;
          cout << "Sorry, the computer beat you!" << endl;
      }
      else if (t == 1) //human wins
      {
          cout << "The computer has picked the last stick!" << endl;
          cout << "Congratulations, you have beat the computer!" << endl;
          break; //breaks while loop and ends that game
      }
      else if (t == 2) // computer makes last turn i.e. can win and will
      {
          comp_choice = 1;
          t -= comp_choice;
          cout << "Computer picked " << comp_choice << ". " << t << " remain." << endl;
      }
      else if (t == 3) // computer makes last turn i.e. can win and will
      {
          comp_choice = 2;
          t -= comp_choice;
          cout << "Computer picked " << comp_choice << ". " << t << " remain." << endl;
      }
      else if (t == 4) // computer makes last turn i.e. can win and will
      {
          comp_choice = 3;
          t -= comp_choice;
          cout << "Computer picked " << comp_choice << ". " << t << " remain." << endl;
      }
      else  // computer always chooses 4 minus what the human chose
      {
          comp_choice = 4 - human_choice;
          t -= comp_choice;
          cout << "Computer picked " << comp_choice << ". " << t << " remain." << endl;
      }
  }

    // ask player to play again
    cout << "Would you like to play again? (y/n)";
    cin >> response;

    while (response != 'y' && response != 'Y' && response != 'n' && response != 'N')
    {
        cout << "Invalid response." << endl;
        cout << "Would you like to play again? (y/n)?" << endl;
        cin >> response;
    }

    if (response == 'y' || response == 'Y')
    {
        main(); //restarts program
    }
    else
    {
        cout << "Thank you for playing!" << endl;
        return 0; //exits
    }


}

