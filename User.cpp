#include "User.h"
#include "Sender.h"
#include "DeliveryStaff.h"
#include "Utils.h"
#include <iostream>
#include <limits>
using namespace std;

void User::LoginSystem() {
    clearScreen();
    cout << "\033[1;36m╔════════════════════════════════════════╗\033[0m" << endl;
    cout << "\033[1;36m║            USER LOGIN SYSTEM           ║\033[0m" << endl;
    cout << "\033[1;36m╚════════════════════════════════════════╝\033[0m" << endl;
    
    cout << "\033[1;33mUsername: \033[0m";
    cin >> username;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    if (!User::usernameExists("users.txt", username)) {
        cout << "\033[1;31m╔════════════════════════════════════════╗\n";
        cout << "║         USERNAME DOES NOT EXIST        ║\n";
        cout << "║    Please check your username again    ║\n";
        cout << "╚════════════════════════════════════════╝\033[0m" << endl;
        cout << "Press Enter to continue...";
        cin.get(); // Wait for enter key
        return;
    }
    
    cout << "\033[1;33mPassword: \033[0m";
    password = User::getPasswordMasked();

    if (User::login("users.txt", username, password)) {
        clearScreen();
        cout << "\033[1;32m╔════════════════════════════════════════╗\n";
        cout << "║          LOGIN SUCCESSFUL!             ║\n";
        cout << "╚════════════════════════════════════════╝\033[0m" << endl;
        int c = 0;
        while (true) {
            c = sender_or_Deli();
            clearScreen();
            if (c == 1) {
                sender_menu(username);
            } else if (c == 2) {
                Deli_menu(username);
            } else if (c == 3) {
               break;
            } 
            else {
                cout << "\033[1;31mInvalid choice. Please try again.\033[0m\n";
                sleep(1);
                break;
            }
        }
    } else {
        cout << "\033[1;31m╔════════════════════════════════════════╗\n";
        cout << "║           INVALID PASSWORD             ║\n";
        cout << "║  Please check your password and retry  ║\n";
        cout << "╚════════════════════════════════════════╝\033[0m" << endl;
        cout << "Press Enter to continue...";
        cin.get(); // Wait for enter key
    }
}

void User::RegisterSystem() {
    bool validUsername = false;
    clearScreen();
    cout << "\033[1;36m╔════════════════════════════════════════╗\033[0m" << endl;
    cout << "\033[1;36m║        NEW USER REGISTRATION           ║\033[0m" << endl;
    cout << "\033[1;36m╚════════════════════════════════════════╝\033[0m" << endl;
    while (!validUsername) {
        cout << "Enter username: ";
        cin >> username;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        if (username.empty()) {
            clearScreen();
            cout << "\033[1;31m╔════════════════════════════════════════╗\n";
            cout << "║           USERNAME IS EMPTY             ║\n";
            cout << "║      Please enter a valid username      ║\n";
            cout << "╚════════════════════════════════════════╝\033[0m" << endl;
            continue;
        }

        if (!User::isValidUsername(username)) {
            clearScreen();
            cout << "\033[1;31m╔════════════════════════════════════════╗\n";
            cout << "║        INVALID USERNAME FORMAT          ║\n";
            cout << "║ Use only letters, numbers, _ and -      ║\n";
            cout << "║ Username must not start with a number   ║\n";
            cout << "╚════════════════════════════════════════╝\033[0m" << endl;
        } else if (isdigit(username[0])) {
            clearScreen();
            cout << "\033[1;31m╔════════════════════════════════════════╗\n";
            cout << "║  USERNAME MUST NOT START WITH A NUMBER  ║\n";
            cout << "╚════════════════════════════════════════╝\033[0m" << endl;
            clearScreen();
        } else if (User::isUsernameTaken("users.txt", username)) {
            clearScreen();
            cout << "\033[1;31m╔════════════════════════════════════════╗\n";
            cout << "║       USERNAME ALREADY EXISTS           ║\n";
            cout << "║      Please choose another username     ║\n";
            cout << "╚════════════════════════════════════════╝\033[0m" << endl;
        } else {
            validUsername = true;
        }
    }

    bool validPassword = false;
    string password;

    while (!validPassword) {
        cout << "\033[1;33mCreate a password (minimum 8 characters): \033[0m";
        password = User::getPasswordMasked();

        if (password.length() < 8) {
            cout << "\033[1;31m╔════════════════════════════════════════╗\n";
            cout << "║   PASSWORD MUST BE AT LEAST 8 CHARS     ║\n";
            cout << "╚════════════════════════════════════════╝\033[0m" << endl;
        } else if (!User::isValidPassword(password)) {
            cout << "\033[1;31m╔════════════════════════════════════════╗\n";
            cout << "║         INVALID PASSWORD FORMAT         ║\n";
            cout << "║ Use only letters, numbers, _ and -      ║\n";
            cout << "╚════════════════════════════════════════╝\033[0m" << endl;
        } else {
            validPassword = true;
        }
    }

    this->password = password;
    User newUser(username, this->password);
    newUser.saveToFile("users.txt");

    clearScreen();
    cout << "\033[1;32m===================================================\n";
    cout << "User registered successfully!\n";
    cout << "Username: " << username << endl;
    cout << "===================================================\033[0m" << endl;

    cout << "Press Enter to continue...";
    cin.get();
}

void User::saveToFile(const string& filename) {
    ofstream outFile(filename, ios::app);
    if (outFile.is_open()) {
        outFile << username << " " << password << endl;
        outFile.close();
        cout << "User information saved successfully." << endl;
    } else {
        cout << "\033[1;31mFailed to open file for writing!\033[0m" << endl;
    }
}