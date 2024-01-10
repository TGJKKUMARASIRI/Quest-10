#include <iostream>
#include <string>
#include <limits>
#include "BoardClass.h"

using namespace std;

class Player
{
public:
    char command[3];
    Board board;

    //Kumarasiri
    void GettingUserCommand()
    {
        board.rows = 10;
        cout << "Enter your command: ";

        for (int i = 0; i < 3; ++i) 
        {
            cin.get(command[i]);
        }

        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        if (((int(command[0])) < 65 || (int(command[0])) > 64+board.rows) || ((int(command[1])) < 65 || (int(command[1])) > 64+board.rows))
        {
            cout << "Invalid command. Please try again." << endl;
            GettingUserCommand();
        }

        if (command[2] != 'R' && command[2] != 'F')
        {
            cout << "Invalid command. Please try again." << endl;
            GettingUserCommand();
        }
    }

    //Kumarasiri
    void CheckIfItBombed()
    {
        if (board.field[int(command[0])-65][int(command[1])-65][0] == 1)
        {
            cout << "You step on a bomb!" << endl;
        }
    }

    //Kumarasiri
    void FlaggingTheField()
    {
        if (board.flag == 0)
        {
            cout << "You are out of Flags!" << endl;
        }
        else 
        {
            board.field[int(command[0])-65][int(command[1])-65][1] = 2;
            board.flag--;
        }
    }


    void CheckIfWholeTheBombsAreFlagged()
    {

    }

    
    void CheckIfFieldIsCleared()
    {

    }

    void Game()
    {

        Game();
    }

    void WholeGame()
    {
        board.display_menu();
    }
};
