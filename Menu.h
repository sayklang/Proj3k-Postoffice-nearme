#ifndef MENU_H
#define MENU_H

using namespace std;

void showMenu() {
    cout << "1. Login" << endl;
    cout << "2. Register" << endl;
    cout << "3. Exis" << endl;
    cout << "Enter your choice: ";
}


int getChoice() {
    int choice;
    cin >> choice;
    return choice;
}

#endif // MENU_H
