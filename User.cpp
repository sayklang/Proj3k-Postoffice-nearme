#include "User.h"
#include "Sender.h"
#include "DeliveryStaff.h"
#include "Utils.h"
#include <iostream>
#include <limits>
using namespace std;

void User::LoginSystem() {
    clearScreen();
    cout << "Enter username: ";
    cin >> username;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    if (!User::usernameExists("users.txt", username)) {
        cout << "\033[1;31m===================================================\n";
        cout << "Username does not exist. Please check your username.\n";
        cout << "===================================================\033[0m" << endl;
        cout << "Press Enter to continue...";
        cin.get(); // Wait for enter key
        return;
    }
    
    cout << "Enter password: ";
    password = User::getPasswordMasked();

    if (User::login("users.txt", username, password)) {
        clearScreen();
        cout << "\033[1;32m===================================================\n";
        cout << "Login successful!\n";
        cout << "===================================================\033[0m" << endl;
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
                cout << "Invalid choice. Please try again.\n";
                break;
            }
        }
    } else {
        cout << "\033[1;31m===================================================\n";
        cout << "Invalid password for username: " << username << endl;
        cout << "===================================================\033[0m" << endl;
        cout << "Press Enter to continue...";
        cin.get(); // Wait for enter key
    }
}

void User::RegisterSystem() {
    bool validUsername = false;
    clearScreen();
    while (!validUsername) {
        cout << "Enter username: ";
        cin >> username;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        if (!User::isValidUsername(username)) {
            clearScreen();
            cout << "\033[1;31m===================================================\n";
            cout << "Invalid username format.\n";
            cout << "Only Thai/English letters, numbers, _ and - are allowed.\n";
            cout << "Username must not contain spaces and must not start with a number.\n";
            cout << "===================================================\033[0m" << endl;
        } else if (isdigit(username[0])) {
            clearScreen();
            cout << "\033[1;31m===================================================\n";
            cout << "Username must not start with a number.\n";
            cout << "===================================================\033[0m" << endl;
            clearScreen();
        } else if (User::isUsernameTaken("users.txt", username)) {
            clearScreen();
            cout << "\033[1;31m=========================================================\n";
            cout << "Username is already taken! Please choose a different one.\n";
        } else {
            validUsername = true;
        }
    }

    bool validPassword = false;
    string password;

    while (!validPassword) {
        cout << "Enter password (minimum 8 characters): ";
        password = User::getPasswordMasked();

        if (password.length() < 8) {
            cout << "\033[1;31m===================================================\n";
            cout << "Password must be at least 8 characters long.\n";
            cout << "===================================================\033[0m" << endl;
        } else if (!User::isValidPassword(password)) {
            cout << "\033[1;31m===================================================\n";
            cout << "Password can only contain letters, numbers, underscores, and hyphens.\n";
            cout << "===================================================\033[0m" << endl;
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
        cout << " Failed to open file for writing!" << endl;
    }
}