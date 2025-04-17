#include <iostream>
#include "DeliveryStaff.h"
#include "User.h"  
#include "Menu.h"
#include <sstream>
#include <fstream>

using namespace std;

void Deli_menu(string& username) {
    int choice;
    cout << "\033[1;34mLogged in as: " << username << " (Delivery Staff)\033[0m" << endl;
    do {
        clearScreen();
        choice = Deli_getChoice();
        switch (choice) {
            case 1: {
                string trackingNumber;
                cout << "\033[1;33mEnter TrackingNumber (TNXXXXXX): \033[0m";
                cin >> trackingNumber;
                cout << "\033[1;36mPackage Details:\033[0m" << endl;
                readAndShowByTracking("packages.txt", trackingNumber); 
                cout << "\nPress Enter to continue...";
                cin.ignore();
                cin.get();
                }
                break;
            case 2: {
                string trackingNumber;
                cout << "\033[1;33mEnter TrackingNumber to update status (TNXXXXXX): \033[0m";
                cin >> trackingNumber;
                updatePackageStatus(trackingNumber);
                cout << "\nPress Enter to continue...";
                cin.ignore();
                cin.get();
                }
                break;
            case 3:
                cout << "\033[1;32mReturning to main menu...\033[0m" << endl;
                break;
            default:
                cout << "\033[1;31mInvalid choice. Please try again.\033[0m" << endl;
                break;
        }
    } while (choice != 3);
}

void readAndShowByTracking(const string& filename, const string& trackingNumber) {
    ifstream file(filename);
    if (!file) {
        cerr << "\033[1;31mCannot open file: " << filename << "\033[0m" << endl;
        return;
    }

    string line;
    bool found = false;
    
    while (getline(file, line)) {
        if (line.find(trackingNumber) != string::npos) {
            found = true;
            istringstream iss(line);
            string username, name, address, product, weight, tracking, status;
            
            // Parse the line
            if (iss >> username >> name >> address >> product >> weight >> tracking) {
                // If status exists in the file
                if (iss >> status) {
                    cout << "\033[1;32mUsername: \033[0m" << username << endl;
                    cout << "\033[1;32mRecipient: \033[0m" << name << endl;
                    cout << "\033[1;32mAddress: \033[0m" << address << endl;
                    cout << "\033[1;32mProduct: \033[0m" << product << endl;
                    cout << "\033[1;32mWeight: \033[0m" << weight << " kg" << endl;
                    cout << "\033[1;32mTracking Number: \033[0m" << tracking << endl;
                    cout << "\033[1;32mStatus: \033[0m" << status << endl;
                } else {
                    cout << "\033[1;32mUsername: \033[0m" << username << endl;
                    cout << "\033[1;32mRecipient: \033[0m" << name << endl;
                    cout << "\033[1;32mAddress: \033[0m" << address << endl;
                    cout << "\033[1;32mProduct: \033[0m" << product << endl;
                    cout << "\033[1;32mWeight: \033[0m" << weight << " kg" << endl;
                    cout << "\033[1;32mTracking Number: \033[0m" << tracking << endl;
                    cout << "\033[1;32mStatus: \033[0m" << "Pending" << endl;
                }
            }
        }
    }
    
    if (!found) {
        cout << "\033[1;31mNo package found with tracking number: " << trackingNumber << "\033[0m" << endl;
    }

    file.close();
}

void updatePackageStatus(const string& trackingNumber) {
    // Read all packages
    ifstream inFile("packages.txt");
    if (!inFile) {
        cerr << "\033[1;31mCannot open packages.txt\033[0m" << endl;
        return;
    }
    
    // Store all lines
    vector<string> lines;
    string line;
    bool packageFound = false;
    
    while (getline(inFile, line)) {
        if (line.find(trackingNumber) != string::npos) {
            packageFound = true;
            istringstream iss(line);
            string username, name, address, product, weight, tracking, currentStatus;
            
            // Parse the line
            iss >> username >> name >> address >> product >> weight >> tracking;
            
            // Check if status exists
            if (iss >> currentStatus) {
                cout << "\033[1;36mCurrent status: " << currentStatus << "\033[0m" << endl;
            } else {
                cout << "\033[1;36mCurrent status: Pending\033[0m" << endl;
                currentStatus = "Pending";
            }
            
            // Show status options
            cout << "\033[1;33mUpdate status to:\033[0m" << endl;
            cout << "1. Pending" << endl;
            cout << "2. Processing" << endl;
            cout << "3. In Transit" << endl;
            cout << "4. Delivered" << endl;
            cout << "Enter choice: ";
            
            int statusChoice;
            cin >> statusChoice;
            
            string newStatus;
            switch (statusChoice) {
                case 1: newStatus = "Pending"; break;
                case 2: newStatus = "Processing"; break;
                case 3: newStatus = "InTransit"; break;
                case 4: newStatus = "Delivered"; break;
                default: newStatus = currentStatus; break;
            }
            
            // Create new line with updated status
            string newLine = username + " " + name + " " + address + " " + product + " " + 
                           weight + " " + tracking + " " + newStatus;
            lines.push_back(newLine);
            
            cout << "\033[1;32mStatus updated successfully!\033[0m" << endl;
        } else {
            lines.push_back(line);
        }
    }
    
    inFile.close();
    
    if (!packageFound) {
        cout << "\033[1;31mNo package found with tracking number: " << trackingNumber << "\033[0m" << endl;
        return;
    }
    
    // Write back all lines
    ofstream outFile("packages.txt");
    if (!outFile) {
        cerr << "\033[1;31mCannot open packages.txt for writing\033[0m" << endl;
        return;
    }
    
    for (const auto& l : lines) {
        outFile << l << endl;
    }
    
    outFile.close();
}