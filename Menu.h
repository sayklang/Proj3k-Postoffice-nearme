#ifndef MENU_H
#define MENU_H

#include <iostream>
using namespace std;

inline void showMenu() {
    cout << "==================================================="<<endl;
    cout << "\033[1;32m1. Login" << endl;
    cout << "2. Register\033[0m" << endl;
    cout << "\033[1;31m3. Exit\033[0m" << endl;
    cout << "==================================================="<<endl;
    cout << "Enter your choice: ";
}

inline int getChoice() {
    int choice;
    cin >> choice;
    return choice;
}

inline int sender_getChoice() {
    int c;
    cout << "\n===== MENU =====" << endl;
    cout << "1. Input pussadu" << endl;
    cout << "2. Get Track" << endl;
    cout << "3. Exit" << endl;
    cout << "Enter your choice: ";
    cin >> c;
    return c;
}

#endif // MENU_H
