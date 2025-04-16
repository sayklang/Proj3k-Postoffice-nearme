#ifndef USER_H
#define USER_H

#include <iostream>
#include <fstream>
#include <regex>
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
            outFile << username << "," << password << endl;
            outFile.close();
        } else {
            cout << "Failed to open file!" << endl;
        }
    }

    static bool isUsernameTaken(const string& filename, const string& username) {
        ifstream inFile(filename);
        string existingUsername, password;
        if (inFile.is_open()) {
            while (inFile >> existingUsername >> password) {
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
        regex pattern("^[a-zA-Z0-9_-]{8,}$");
        return regex_match(password, pattern);
    }

    void LoginSystem();

    void RegisterSystem();
};

#endif // USER_H
