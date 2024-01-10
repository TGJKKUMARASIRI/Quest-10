#include <iostream>
using namespace std;
class Board {
public:
    int rows;
    int field [20][20][2] = {{{0}}};
    // Constructor
    Board() : rows(0){}

    // Function to display menu and set board dimensions
    void display_menu() {
        // Field options
        std::cout << "Field Options \tGrid size \t No of Mines" << std::endl;
        std::cout << "\t1. \t10-by-10  \t  12 Mines" << std::endl;
        std::cout << "\t2. \t15-by-15  \t  18 Mines" << std::endl;
        std::cout << "\t3. \t20-by-20  \t  24 Mines" << std::endl;

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



