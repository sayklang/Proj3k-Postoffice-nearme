#include <iostream>  //C++
#include <string>   
#include <fstream>
#include <regex> 
#include <stdlib.h>
#include <ctime>
#include <limits> // Add this for numeric_limits
#include "User.h"
#include "Menu.h"
#include "Utils.h"  // Include the new header

using namespace std;

int main() {
    srand(time(NULL)); // ตั้งค่า seed ตามเวลากันเลขซ้ำ
    User user;
    int choice = 0; // Initialize the choice variable
    
    while (choice != 3) {
        clearScreen();  // Use the clearScreen() function from Utils.h
        showMenu();
        choice = getChoice();
        
        switch (choice) {
        case 1:
            user.LoginSystem();
            break;
        case 2:
            user.RegisterSystem();
            break;
        case 3:
            cout << "Exiting...\n";
            clearScreen();
            break;
        default:
            cout << "\033[1;31m===================================================\n";
            cout << "Invalid choice. Please try again.\n";
            cout << "===================================================\033[0m" << endl;
            // Add a pause so user can read the message
            cout << "Press Enter to continue...";
            cin.get();
            break;
        }
    }
    
    return 0;
}