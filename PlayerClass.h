#include <iostream>
#include <string>
#include "BoardClass.h"

using namespace std;

class PlayerClass
{
public:
    char command[3];

    //Kumarasiri
    void GettingUserCommand()
    {

        cout << "Enter your command: ";

        for (int i = 0; i < 3; ++i) 
        {
            cin.get(command[i]);
        }

        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        if (command[2] != 'R' || command[2] != 'F')
        {
            cout << "Invalid command. Please try again." << endl;
            GettingUserCommand();
        }
    }

    void CheckIfItBombed()
    {

    }

    void FlaggingTheField()
    {

    }

    void CheckIfWholeTheBombsAreFlagged()
    {

    }

    void CheckIfFieldIsCleared()
    {

    }

    void Game()
    {

    }

    void WholeGame()
    {

    }
};
