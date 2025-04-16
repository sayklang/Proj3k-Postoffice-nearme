#include <iostream>
#include "DeliveryStaff.h"
#include "User.h"  
#include "Menu.h"

using namespace std;

void Deli_menu(string& username) {
    LL A;
    float w;
    string n, a, p,t;
    int l;
    int choice;
    cout << "Logged in as: " << username << endl;
    do {
        clearScreen();
        choice = Deli_getChoice();
        switch (choice) {
            case 1: {
            string trackingNumber;
            cout << "Enter TrackingNumber (TNXXXXXX): ";
            cin >> trackingNumber;
            cout << "Your Pasadu : " <<endl ;
            readAndShowByTracking("packages.txt", trackingNumber); 
            }
                break;
            case 2:
            
                break;
            case 3:
                cout << "Exiting..." << endl;
                break;
            default:
                cout << "Invalid choice. Please try again." << endl;
                break;
        }
    } while (choice != 3);
}

void readAndShowByTracking(const string& filename, const string& trackingNumber) {
    ifstream file(filename);
    if (!file) {
        cerr << "Cannot open file : " << filename << endl;
        return;
    }

    string line;
    while (getline(file, line)) {
        if (line.find(trackingNumber) != string::npos) {
            istringstream iss(line);
            string word;
            while (iss >> word) {
                // ข้าม TNXXXXXX ที่ตรงกับ tracking number
                if (word == trackingNumber) continue;
                cout << word << " ";
            }
            cout << endl;
        }
    }

    file.close();
}