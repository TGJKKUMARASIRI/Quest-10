//P.SIVABALASRI - 21/ENG/097
//KAWTHUKA - 21/ENG/008
#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

#define MAXSIDE 25

class Board {
public:
    int rows;
    int flags;
    int field[20][20][2] = {{{0}}};

    // Constructor
    Board() : rows(0), flags(0) {}

    //P.SIVABALASRI
    // Function to display menu and set board dimensions
    void display_menu() {
        // Field options
        std::cout << "Field Options \tGrid size \t No of Mines" << std::endl;
        std::cout << "	1. \t10-by-10  \t  12 Mines" << std::endl;
        std::cout << "	2. \t15-by-15  \t  18 Mines" << std::endl;
        std::cout << "	3. \t20-by-20  \t  24 Mines" << std::endl;
        cout << endl
             << endl;

        // Get user input for field selection
        int selectedOption;
        std::cout << "Enter the number of the field option you want to play (1, 2, or 3): ";
        std::cin >> selectedOption;

        // Set the number of rows and columns based on the user's selection
        if (selectedOption == 1) {
            rows = 10;
            flags = 12;
        } else if (selectedOption == 2) {
            rows = 15;
            flags = 18;
        } else if (selectedOption == 3) {
            rows = 20;
            flags = 24;
        } else {
            cout << "Please select the correct field option !!! " << endl;
            display_menu();
        }

        // Initialize bomb placement
        initialize_bombs();
    }

    //P.SIVABALASRI
    // Function to initialize bomb placement
    void initialize_bombs() {
        srand(static_cast<unsigned>(time(nullptr)));

        // Place bombs randomly
        int bombsToPlace = flags;
        while (bombsToPlace > 0) {
            int randomRow = rand() % rows;
            int randomCol = rand() % rows;
            // Check if there is no bomb already at the selected location
            if (field[randomRow][randomCol][0] != 1) {
                field[randomRow][randomCol][0] = 1; // Place bomb in the front layer
                bombsToPlace--;
            }
        }
    }

    //Kawthuka
    // Function to count adjacent mines for a cell
    int countAdjacentMines(int row, int col, int mines[][2], char realBoard[][MAXSIDE]) {
        int count = 0;

        // Neighbour coordinates offsets
        int neighbourOffsets[][2] = {
            {-1, 0},  // North
            {1, 0},   // South
            {0, 1},   // East
            {0, -1},  // West
            {-1, 1},  // North-East
            {-1, -1}, // North-West
            {1, 1},   // South-East
            {1, -1}   // South-West
        };

        // Check each neighbour cell
        for (int i = 0; i < 8; ++i) {
            int newRow = row + neighbourOffsets[i][0];
            int newCol = col + neighbourOffsets[i][1];

            // Check if the new cell is valid
            if (isValid(newRow, newCol) && isMine(newRow, newCol, realBoard)) {
                count++;
            }
        }

        return count;
    }
    //Kawthuka
    // Function to check if a cell is valid
    bool isValid(int row, int col) {
        return (row >= 0) && (row < rows) &&
               (col >= 0) && (col < rows);
    }

    //Kawthuka
    // Function to check if a cell has a mine
    bool isMine(int row, int col, char board[][MAXSIDE]) {
        return (board[row][col] == '*');
    }

    //P.SIVABALASRI
    // Function to display the content of each cell
    void display_field() {
//    	field[2][3][1] = 1;
//        field[2][8][1] = 2;
    
    for (int i = 0; i < rows; ++i) {
            cout << "  ";
            for (int j = 0; j < rows; ++j) {
                cout << char(j + 65) << " ";
            }
            cout << endl;
            break;
        }

        for (int i = 0; i < rows; ++i) {
            cout << char(i + 65) << " ";
            for (int j = 0; j < rows; ++j) {
                // Display the front layer (whether there is a bomb or not)
                if (field[i][j][1] == 0) {
                    cout << "C ";
                } else if (field[i][j][1] == 2) {
                    // If there is a bomb, display "F"
                    cout << "F ";
                } else {
                    // If it's not a bomb, use countAdjacentMines to get the number of adjacent bombs
                    int adjacentMines = countAdjacentMines(i, j, nullptr, getRealBoard());
                    if (adjacentMines == 0)
                    {
                        cout << ". ";
                    }
                    else
                    {
                        cout << adjacentMines << " ";
                    }
                }
            }
            cout << endl;
        }

        cout << endl;
    }

    //Kawthuka
    // Function to get the real board (mine locations)
    char (*getRealBoard())[MAXSIDE] {
        static char realBoard[MAXSIDE][MAXSIDE];
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < rows; ++j) {
                realBoard[i][j] = (field[i][j][0] == 1) ? '*' : '-';
            }
        }
        return realBoard;
    }
};


