#include "User.h"
#include "Sender.h" // ต้อง include ที่นี่แทนใน User.h เพื่อไม่ให้วนซ้ำ
#include <iostream>
using namespace std;

void User::LoginSystem() {
    // ล็อกอิน
    cout << "===================================================" << endl;
    cout << "Enter username: ";
    cin >> username;
    cout << "Enter password: ";
    cin >> password;

    // เช็คข้อมูลการล็อกอิน
    if (User::login("users.txt", username, password)) {
        cout << "\033[1;32m===================================================" << endl;
        cout << "Login successful!" << endl;
        cout << "===================================================\033[0m" << endl;
        sender_menu(username);  // เรียกเมนูของผู้ส่งหลังจากล็อกอิน
    } else {
        cout << "\033[1;31m===================================================" << endl;
        cout << "Invalid username or password!" << endl;
        cout << "===================================================\033[0m" << endl;
    }
}

void User::RegisterSystem() {
    cout << "Enter username: ";
    cin >> username;

    if (User::isUsernameTaken("users.txt", username)) {
        cout << "\033[1;31m===================================================" << endl;
        cout << "Username is already taken! Please choose a different one." << endl;
        cout << "===================================================\033[0m" << endl;
    } else if (!User::isValidUsername(username)) {
        cout << "\033[1;31m===================================================" << endl;
        cout << "Only Thai/English letters, numbers, and _ - allowed." << endl;
        cout << "===================================================\033[0m" << endl;
    } else {
        cout << "Enter password: ";
        cin >> password;

        if (User::isValidPassword(password)) {
            User newUser(username, password);
            newUser.saveToFile("users.txt");

            cout << "\033[1;32m===================================================" << endl;
            cout << "User registered successfully!" << endl;
            cout << "===================================================\033[0m" << endl;
        } else {
            cout << "\033[1;31m===================================================" << endl;
            cout << "Password must be at least 8 characters (letters/numbers/_/-)." << endl;
            cout << "===================================================\033[0m" << endl;
        }
    }
}
