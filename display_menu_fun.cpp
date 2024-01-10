//#include <iostream>
//using namespace std;
//
//class Board 
//
//void display_menu ()
//{
//	// Field options
//    cout << "Field Options \tGrid size \t No of Mines:" << endl;
//    cout << "1. \t\t10-by-10  \t\t12 Mines" << endl;
//    cout << "2. \t\t15-by-15  \t\t18 Mines" << endl;
//    cout << "3. \t\t20-by-20  \t\t24 Mines" << endl;
//
//    // Get user input for field selection
//    cout << "Enter the number of the field option you want to play (1, 2, or 3): ";
//    int selectedOption;
//    cin >> selectedOption;
//    
//    if (selectedOption == 1)
//        row = 10;
//    else if (selectedOption == 2)
//        row = 15;
//    else
//    	row = 20;
//}
//
//int main()
//{
//	int row = display_menu();
//	display_menu();
//	return 0;
//}


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

int main() {
    Board myBoard;
    
    // Display menu and set board dimensions
    myBoard.display_menu();
    cout<<myBoard.rows;
    

    return 0;
}

