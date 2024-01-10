
#include <iostream>
using namespace std;

class Board {
public:
    int rows;
    
    // Constructor
    Board() : rows(0){}

    // Function to display menu and set board dimensions
    void display_menu() {
        // Field options
        std::cout << "Field Options \tGrid size \t No of Mines:" << std::endl;
        std::cout << "1. \t\t10-by-10  \t\t12 Mines" << std::endl;
        std::cout << "2. \t\t15-by-15  \t\t18 Mines" << std::endl;
        std::cout << "3. \t\t20-by-20  \t\t24 Mines" << std::endl;

        // Get user input for field selection
        int selectedOption;
        std::cout << "Enter the number of the field option you want to play (1, 2, or 3): ";
        std::cin >> selectedOption;

        // Set the number of rows and columns based on user's selection
        if (selectedOption == 1) {
            rows = 10;
        } else if (selectedOption == 2) {
            rows = 15;
        } else if (selectedOption == 3) {
            rows = 20;
        } else {
            cout<<"Please select the correct field option !!! "<<endl;
            display_menu();
        }
    }
};



