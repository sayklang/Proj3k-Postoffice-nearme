#include <iostream>
#include <fstream>
#include <string>
#include <vector>

#include"User.h"
using namespace std;

int main() {
    int choice;
    string username, password;

    cout << "1. Register User" << endl;
    cout << "2. Show Registered Users" << endl;
    cout << "Enter your choice: ";
    cin >> choice;

    if (choice == 1) {
        // ล็อกอิน
        cout << "Enter username: ";
        cin >> username;
        cout << "Enter password: ";
        cin >> password;

        // เช็คข้อมูลการล็อกอิน
        if (User::login("users.txt", username, password)) {
            cout << "Login successful!" << endl;
        } else {
            cout << "Invalid username or password!" << endl;
        }

    } else {
        cout << "Invalid choice!" << endl;
    }
} 
