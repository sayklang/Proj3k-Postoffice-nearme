#include "User.h"
#include "Sender.h" 
#include "Utils.h"  // Include Utils.h for clearScreen
#include <iostream>
#include <limits>
using namespace std;

void User::LoginSystem() {
    // ล็อกอิน
    cout << "===================================================" << endl;
    cout << "Enter username: ";
    cin >> username;
    
    // Clear the input buffer
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    
    // Check if username exists before asking for password
    if (!User::usernameExists("users.txt", username)) {
        clearScreen();
        cout << "\033[1;31m===================================================" << endl;
        cout << "Username does not exist. Please check your username." << endl;
        cout << "===================================================\033[0m" << endl;
        return; // Exit the login function
    }
    
    cout << "Enter password: ";
    // Use the password masking function
    password = User::getPasswordMasked();

    // เช็คข้อมูลการล็อกอิน
    if (User::login("users.txt", username, password)) {
        clearScreen();  // Clear screen on success
        cout << "\033[1;32m===================================================" << endl;
        cout << "Login successful!" << endl;
        cout << "===================================================\033[0m" << endl;
        sender_menu(username);  
    } else {
        clearScreen();  // Clear screen on failure
        cout << "\033[1;31m===================================================" << endl;
        cout << "Invalid password for username: " << username << endl;
        cout << "===================================================\033[0m" << endl;
    }
}

void User::RegisterSystem() {
    bool validRegistration = false;
    while (!validRegistration) {  // ลูปจนกว่าจะลงทะเบียนสำเร็จ
        cout << "Enter username: ";
        cin >> username;

        // Clear the input buffer
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        if (User::isUsernameTaken("users.txt", username)) {
            clearScreen();
            cout << "\033[1;31m===================================================" << endl;
            cout << "Username is already taken! Please choose a different one." << endl;
            cout << "===================================================\033[0m" << endl;
        } else if (!User::isValidUsername(username)) {
            clearScreen();
            cout << "\033[1;31m===================================================" << endl;
            cout << "Only Thai/English letters, numbers, and _ - allowed." << endl;
            cout << "===================================================\033[0m" << endl;
        } else {
            bool validPassword = false;
            string password;
            
            while (!validPassword) {
                cout << "Enter password (minimum 8 characters): ";
                password = User::getPasswordMasked();
                
                if (password.length() < 8) {
                    cout << "\033[1;31m===================================================" << endl;
                    cout << "Password must be at least 8 characters long." << endl;
                    cout << "===================================================\033[0m" << endl;
                    cout << "Please try again." << endl;
                } else if (!User::isValidPassword(password)) {
                    cout << "\033[1;31m===================================================" << endl;
                    cout << "Password can only contain letters, numbers, underscores, and hyphens." << endl;
                    cout << "===================================================\033[0m" << endl;
                    cout << "Please try again." << endl;
                } else {
                    validPassword = true;
                }
            }
            
            // At this point, we have a valid password
            this->password = password;
            
            // Create a new user object with the username and password
            User newUser(username, this->password);
            
            // Save to file
            newUser.saveToFile("users.txt");
            
            clearScreen();
            cout << "\033[1;32m===================================================" << endl;
            cout << "User registered successfully!" << endl;
            cout << "Username: " << username << endl;
            cout << "===================================================\033[0m" << endl;
            
            // Add a pause here to see the message
            cout << "Press Enter to continue...";
            cin.get();
            
            validRegistration = true;  // Exit the loop since registration is successful
        }
    }
}


