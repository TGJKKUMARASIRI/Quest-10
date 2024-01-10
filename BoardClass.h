#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

 /*
 P.SIVABALASRI - 21_ENG_097
 
 */

class Board {
public:
    int rows;
    int flags;
    int field[20][20][2] = {{{0}}};

    // Constructor
    Board() : rows(0),flags(0) {}

    // Function to display menu and set board dimensions
    // P.SIVABALASRI
    void display_menu() {
        // Field options
        std::cout << "Field Options \tGrid size \t No of Mines" << std::endl;
        std::cout << "	1. \t10-by-10  \t  12 Mines" << std::endl;
        std::cout << "	2. \t15-by-15  \t  18 Mines" << std::endl;
        std::cout << "	3. \t20-by-20  \t  24 Mines" << std::endl;
        cout<<endl<<endl;

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

    // Function to initialize bomb placement
    // P.SIVABLASRI
    void initialize_bombs() {
        srand(static_cast<unsigned>(time(nullptr)));

        // Place 16 bombs randomly
        int bombsToPlace = 10;
        while (bombsToPlace > 0) {
            int randomRow = rand() % rows;
            int randomCol = rand() % rows;
            // Check if there is no bomb already at the selected location
            if (field[randomRow][randomCol][0] != 1) {
                field[randomRow][randomCol][0] = 1;  // Place bomb in the front layer
                //field[randomRow][randomCol][1] = bombsToPlace;  // Store the bomb count in the back layer
                bombsToPlace--;
            }
        }
    }

    // Function to display the 3D field
    /*
	void display_field() {
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < rows; ++j) {
                // Display the front layer (whether there is a bomb or not)
                cout << (field[i][j][0] == 1 ? "B" : "-") << " ";
            }
            cout << endl;
        }

        cout << endl;
        
		
		 // displaying the background stroed data
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < rows; ++j) {
                // Display the back layer (1 if there is a bomb, 0 otherwise)
                cout << (field[i][j][0] == 1 ? 1 : 0) << " ";
            }
            cout << endl;
        }
        */
        
        //P.SIVABALASRI
        void display_field() {
        	
        	field[2][3][1] = 1;
        	field[2][8][1] = 2;
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < rows; ++j) {
                // Display the front layer (whether there is a bomb or not)
                if (field[i][j][1] == 0)
                {
                	cout << "C ";
				}
				else if (field[i][j][1] == 1)
				{
					cout<<"1 ";
				}
				else
				{
					cout << "F ";
				}
            }
            cout << endl;
        }

        cout << endl;
    }
   
   int CheckingTheNeibours()
   {
   	
   }
};



