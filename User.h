#ifndef USER_H
#define USER_H

#include <iostream>
#include <fstream>
#include <regex>
#include <termios.h>
#include <unistd.h> // สำหรับ Terminal


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

    User() : username(""), password("") {}

    friend class Sender;

    // สำหรับ Terminal: แสดง * ตอนกรอกรหัสผ่าน
    static string getPasswordMasked() {
        string password;
        struct termios oldt, newt;
    
        // ดึงค่าการตั้งค่าปัจจุบันของ terminal
        tcgetattr(STDIN_FILENO, &oldt);
        newt = oldt;
    
        // ปิด ICANON กับ ECHO เพื่อให้รับตัวอักษรทีละตัวและไม่แสดงผล
        newt.c_lflag &= ~(ECHO | ICANON);
        tcsetattr(STDIN_FILENO, TCSANOW, &newt);
    
        char ch;
        while (true) {
            ch = getchar();
            if (ch == '\n') break; // กด Enter เพื่อจบการกรอก
    
            if (ch == 127 || ch == 8) { // backspace
                if (!password.empty()) {
                    password.pop_back();
                    cout << "\b \b";
                }
            } else {
                password += ch;
                cout << '*';
            }
            cout.flush(); // แสดงผลทันที
        }
    
        cout << endl;
        tcsetattr(STDIN_FILENO, TCSANOW, &oldt); // คืนค่าการตั้งค่าเดิม
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

    void saveToFile(const string& filename);

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
        regex pattern("^[a-zA-Zก-๙_\\-][a-zA-Z0-9ก-๙_\\-]*$");
        return regex_match(username, pattern) && username.find(' ') == string::npos;
    }

    static bool isValidPassword(const string& password) {
        if (password.length() < 8) return false;
        regex pattern("^[a-zA-Z0-9_-]+$");
        return regex_match(password, pattern);
    }

    static bool usernameExists(const string& filename, const string& username) {
        ifstream inFile(filename);
        string existingUsername, existingPassword;

        if (inFile.is_open()) {
            while (inFile >> existingUsername >> existingPassword) {
                // Removed debug output here
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