#ifndef MENU_H
#define MENU_H

#include <iostream>
#include <cstdlib>
#include "Utils.h"
#include "InputUtils.h" // Include our new header with validation function
using namespace std;

inline void showMenu() {
    clearScreen();
    const string YELLOW = "\033[1;33m";
    const string RESET = "\033[0m";
    cout << YELLOW;
    cout << "██████╗  ███████╗ ███████╗████████╗ ███╗   ██╗ ███████╗  █████╗  ██╗      ██╗\n";
    cout << "██╔══██╗ ██╔══██║ ██╔════╝╚══██╔══╝ ████╗  ██║ ██╔════╝ ██╔══██╗ ██║      ██║\n";
    cout << "██████╔╝ ██║  ██║ ███████╗   ██║    ██╔██╗ ██║ █████╗   ███████║ ██║      ██║\n";
    cout << "██╔═══╝  ██║  ██║ ╚════██║   ██║    ██║╚██╗██║ ██╔══╝   ██╔══██║ ██║      ██║\n";
    cout << "██║      ███████║ ███████║   ██║    ██║ ╚████║ ███████╗ ██║  ██║ ██║      ██║\n";
    cout << "╚═╝      ╚══════╝ ╚══════╝   ╚═╝    ╚═╝  ╚═══╝ ╚══════╝ ╚═╝  ╚═╝ ╚═╝      ╚═╝\n\n";
    
    cout << "With Loyalty, We Send | ทรงพระเจริญ 💛\n\n";
    cout << RESET;
    
    //cout << "==================================================="<<endl;
    cout << "What would you like to do?" << endl;
    cout << "\033[1;32m[1] Login" << endl;
    cout << "[2] Register\033[0m" << endl;
    cout << "\033[1;31m[3] Exit\033[0m" << endl;
    //cout << "==================================================="<<endl;
    
}

inline int getChoice() {
    return getValidIntInput();
}

inline int sender_getChoice() {
    cout << "\n===== SENDER MENU =====" << endl;
    cout << "1. Input pussadu" << endl;
    cout << "2. Get Track" << endl;
    cout << "3. Back" << endl;
    cout << "4. Exit" << endl;
    cout << "Enter your choice: ";
    int c = getValidIntInput();
    clearScreen();
    
    return c;
}

inline int Deli_getChoice() {
    cout << "\n===== DELIVERYSTAFF MENU =====" << endl;
    cout << "1. Check Track" << endl;
    cout << "2. passsadu" << endl;
    cout << "3. Back" << endl;
    cout << "4. Exit" << endl;
    cout << "Enter your choice: ";
    int c = getValidIntInput();
    clearScreen();
    
    return c;
}

inline int sender_or_Deli() {
    clearScreen();
    cout << "\n===== MENU =====" << endl;
    cout << "1. Sender" << endl;
    cout << "2. Delivery" << endl;
    cout << "3. Exit" << endl;
    cout << "Enter your choice: ";
    int c = getValidIntInput();
    clearScreen();
    return c;
}

inline void E3(){
    cout << "................................................................:::::::......::::::::::::::::::::::::::::::.::......:.......................::::" << endl;
    // ... rest of the artwork ...
    cout << ":::::::::::::::::::::::::::::::::::::::::::=%@%%@@@@@@@@@%%@@@@@@@@@@@@@@%#*+=+*#@@@@@@@@@@@@@@@*:.......................................::::...::" << endl;
}

#endif // MENU_H