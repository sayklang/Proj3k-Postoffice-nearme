#include <iostream>  
#include <string>
#include <fstream>
#include <regex> 
#include <stdlib.h>
#include "User.h"
#include "Menu.h"
#include "Utils.h"

using namespace std;

int main() {
    User user;
    int choice = 0;
    
    while (choice != 3) {
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
                cout << "\033[1;31mExiting...\033[0m\n";
                clearScreen();
                break;
            case 101: // Easter egg
                E3();
                cout << "\nPress Enter to continue...";
                cin.ignore();
                cin.get();
                break;
            default:
                cout << "\033[1;31m===================================================\n";
                cout << "Invalid choice. Please try again.\n";
                cout << "===================================================\033[0m" << endl;
                break;
        }
    }
    
    return 0;
}