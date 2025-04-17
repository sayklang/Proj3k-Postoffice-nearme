#ifndef MENU_H
#define MENU_H

#include <iostream>
#include <cstdlib>
#include "Utils.h"
#include "InputUtils.h"
using namespace std;

inline void showMenu() {
    clearScreen();
    const string YELLOW = "\033[1;33m";
    const string CYAN = "\033[1;36m";
    const string GREEN = "\033[1;32m";
    const string RED = "\033[1;31m";
    const string RESET = "\033[0m";
    
    cout << CYAN;
    cout << "╔═══════════════════════════════════════════════════════════════════════╗\n";
    cout << "║                                                                       ║\n";
    cout << YELLOW;
    cout << "║  ██████╗  ██████╗ ███████╗████████╗███╗   ██╗███████╗ █████╗ ██╗      ║\n";
    cout << "║  ██╔══██╗██╔═══██╗██╔════╝╚══██╔══╝████╗  ██║██╔════╝██╔══██╗██║      ║\n";
    cout << "║  ██████╔╝██║   ██║███████╗   ██║   ██╔██╗ ██║█████╗  ███████║██║      ║\n";
    cout << "║  ██╔═══╝ ██║   ██║╚════██║   ██║   ██║╚██╗██║██╔══╝  ██╔══██║██║      ║\n";
    cout << "║  ██║     ╚██████╔╝███████║   ██║   ██║ ╚████║███████╗██║  ██║███████╗ ║\n";
    cout << "║  ╚═╝      ╚═════╝ ╚══════╝   ╚═╝   ╚═╝  ╚═══╝╚══════╝╚═╝  ╚═╝╚══════╝ ║\n";
    cout << CYAN;
    cout << "║                                                                       ║\n";
    cout << "║  " << YELLOW << "With Loyalty, We Deliver | ทรงพระเจริญ 💛" << CYAN << "                             ║\n";
    cout << "║                                                                       ║\n";
    cout << "╚═══════════════════════════════════════════════════════════════════════╝\n";
    cout << RESET;
    
    cout << "\n";
    cout << CYAN << "╔════════════════════════════════════════╗\n";
    cout << "║         SELECT AN OPTION:              ║\n";
    cout << "╠════════════════════════════════════════╣\n";
    cout << "║  " << GREEN << "[1] Login to your account             " << CYAN << "║\n";
    cout << "║  " << GREEN << "[2] Register a new account            " << CYAN << "║\n";
    cout << "║  " << RED << "[3] Exit application                  " << CYAN << "║\n";
    cout << "╚════════════════════════════════════════╝" << RESET << "\n";
    cout << "\nEnter your choice: ";
}

inline int getChoice() {
    return getValidIntInput();
}

inline int sender_getChoice() {
    const string CYAN = "\033[1;36m";
    const string GREEN = "\033[1;32m";
    const string RED = "\033[1;31m";
    const string RESET = "\033[0m";
    
    cout << CYAN << "\n╔════════════════════════════════════════╗\n";
    cout << "║            SENDER MENU                 ║\n";
    cout << "╠════════════════════════════════════════╣\n";
    cout << "║  " << GREEN << "[1] Send a new package                " << CYAN << "║\n";
    cout << "║  " << GREEN << "[2] Track my packages                 " << CYAN << "║\n";
    cout << "║  " << GREEN << "[3] Return to main menu               " << CYAN << "║\n";
    cout << "║  " << RED << "[4] Exit application                  " << CYAN << "║\n";
    cout << "╚════════════════════════════════════════╝" << RESET << "\n";
    cout << "Enter your choice: ";
    
    int c = getValidIntInput();
    clearScreen();
    
    return c;
}

inline int Deli_getChoice() {
    const string CYAN = "\033[1;36m";
    const string GREEN = "\033[1;32m";
    const string RED = "\033[1;31m";
    const string RESET = "\033[0m";
    
    cout << CYAN << "\n╔════════════════════════════════════════╗\n";
    cout << "║          DELIVERY STAFF MENU           ║\n";
    cout << "╠════════════════════════════════════════╣\n";
    cout << "║  " << GREEN << "[1] Check package details             " << CYAN << "║\n";
    cout << "║  " << GREEN << "[2] Update package status             " << CYAN << "║\n";
    cout << "║  " << GREEN << "[3] Return to main menu               " << CYAN << "║\n";
    cout << "║  " << RED << "[4] Exit application                  " << CYAN << "║\n";
    cout << "╚════════════════════════════════════════╝" << RESET << "\n";
    cout << "Enter your choice: ";
    
    int c = getValidIntInput();
    clearScreen();
    
    return c;
}

inline int sender_or_Deli() {
    clearScreen();
    const string CYAN = "\033[1;36m";
    const string GREEN = "\033[1;32m";
    const string RED = "\033[1;31m";
    const string RESET = "\033[0m";
    
    cout << CYAN << "\n╔════════════════════════════════════════╗\n";
    cout << "║        SELECT SERVICE TYPE:            ║\n";
    cout << "╠════════════════════════════════════════╣\n";
    cout << "║  " << GREEN << "[1] Sender services                   " << CYAN << "║\n";
    cout << "║  " << GREEN << "[2] Delivery staff services           " << CYAN << "║\n";
    cout << "║  " << RED << "[3] Return to login screen            " << CYAN << "║\n";
    cout << "╚════════════════════════════════════════╝" << RESET << "\n";
    cout << "Enter your choice: ";
    
    int c = getValidIntInput();
    clearScreen();
    return c;
}

#endif // MENU_H