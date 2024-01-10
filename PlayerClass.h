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
    bool CheckIfItBombed()
    {
        if (board.field[int(command[0])-65][int(command[1])-65][0] == 1)
        {
            cout << "You step on a bomb!" << endl;
            return true;
        }
        return false;
    }

    //Kumarasiri
    void FlaggingTheField()
    {
        if (board.flags == 0)
        {
            cout << "You are out of Flags!" << endl;
        }
        else 
        {
            board.field[int(command[0])-65][int(command[1])-65][1] = 2;
            board.flags--;
        }
    }

    //Kawthuka
    bool areAllMinesFlagged() {
    for (int i = 0; i < board.rows; ++i) {
        for (int j = 0; j < board.rows; ++j) {
            // Check if this cell contains a mine and it's not flagged
            if (board.field[i][j][0] == 1 && board.field[i][j][1] != 2) {
                return false; // Mine is present but not flagged
            }
        }
    }
    return true; // All mines are flagged
    }

    
   //Kawthuka
    bool areAllTilesRevealed() 
    {
        for (int i = 0; i < board.rows; ++i) 
        {
            for (int j = 0; j < board.rows; ++j)
            {
                // Check if this cell doesn't contain a bomb and it's not revealed
                if (board.field[i][j][0] != 1 && board.field[i][j][1] != 1) 
                {
                    return false; // Not all tiles are revealed except for bombs
                }
            }
            return true;
        }
    }

    //Kumarasiri
    void Game()
    {
        GettingUserCommand();
        
        if (command[2] == 'R')
        {
            if (CheckIfItBombed())
            {
                board.display_field();
                cout << "Game Over!" << endl;
                return;
            }
            else
            {
                board.field[int(command[0])-65][int(command[1])-65][1] = 1;
                board.display_field();
            }
        }
        else if (command[2] == 'F')
        {
            FlaggingTheField();
            board.display_field();
        }

        if (areAllMinesFlagged() || areAllTilesRevealed()) 
        {
            cout << "You won!" << endl;
            return;
        }

        Game();
    }

    //Kumarasiri
    void WholeGame()
    {
        board.display_menu();
        Game();
    }
};
