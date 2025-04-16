#ifndef USER_H
#define USER_H

#include <iostream>
#include <fstream>
#include <regex>
#include <termios.h>
#include <unistd.h>  // Make sure we have this for usleep

using namespace std;

class User {
private:
    string username;
    string password;

public:
    User(string uname, string pass) {
        username = uname;
        password = pass;
    }

    User() : username(""), password("") {} //User user
    friend class Sender;

    // Password masking function for Unix/Linux systems
    static string getPasswordMasked() {
        string password;
        struct termios oldt, newt;
        
        // Save current terminal settings
        tcgetattr(STDIN_FILENO, &oldt);
        newt = oldt;
        
        // Disable echo
        newt.c_lflag &= ~ECHO;
        tcsetattr(STDIN_FILENO, TCSANOW, &newt);
        
        // Read password
        char ch;
        while ((ch = getchar()) != '\n') {
            if (ch == 127 || ch == 8) { // Backspace or Delete
                if (!password.empty()) {
                    cout << "\b \b";
                    password.pop_back();
                }
            } else {
                password += ch;
                cout << '*';
            }
        }
        cout << endl;
        
        // Restore terminal settings
        tcsetattr(STDIN_FILENO, TCSANOW, &oldt);
        
        return password;
    }

    bool checkLogin(string inputUser, string inputPass) {
        return (inputUser == username && inputPass == password);
    }

    static bool login(const string& filename, const string& username, const string& password) {
        ifstream inFile(filename);
        string existingUsername, existingPassword;
        if (inFile.is_open()) {
            while (inFile >> existingUsername >> existingPassword) {
                if (existingUsername == username && existingPassword == password) {
                    inFile.close();
                    return true;
                }
            }
            inFile.close();
        }
        return false;
    }

    void saveToFile(const string& filename) {
        ofstream outFile(filename, ios::app);
        if (outFile.is_open()) {
            outFile << username << " " << password << endl;
            outFile.close();
        } else {
            cout << "Failed to open file!" << endl;
        }
    }

    static bool isUsernameTaken(const string& filename, const string& username) {
        ifstream inFile(filename);
        string existingUsername, existingPassword;
        if (inFile.is_open()) {
            while (inFile >> existingUsername >> existingPassword) {
                if (existingUsername == username) {
                    inFile.close();
                    return true;
                }
            }
            inFile.close();
        }
        return false;
    }

    static bool isValidUsername(const string& username) {
        regex pattern("^[a-zA-Z0-9ก-๙_-]+$");
        return regex_match(username, pattern);
    }

    static bool isValidPassword(const string& password) {
        // First check for minimum length
        if (password.length() < 8) {
            return false;
        }
        
        // Then check for valid characters
        regex pattern("^[a-zA-Z0-9_-]+$");
        return regex_match(password, pattern);
    }
    static bool usernameExists(const string& filename, const string& username) {
        ifstream inFile(filename);
        string existingUsername, existingPassword;
        
        if (inFile.is_open()) {
            while (inFile >> existingUsername >> existingPassword) {
                if (existingUsername == username) {
                    inFile.close();
                    return true;
                }
            }
            inFile.close();
        }
        return false;
    }

    void LoginSystem();
    void RegisterSystem();
};

#endif // USER_H