#include "Sender.h"
#include "Utils.h"
#include <fstream> // สำหรับการอ่าน/เขียนไฟล์
#include <sstream> 
#include <iomanip>


set<string> Sender::generatedTrackingNumbers; // การประกาศตัวแปร static

Sender::Sender(int l, string n, string a, string p, float w, string u) : NODE(l) {
    name = n;
    address = a;
    product = p;
    weight = w;
    username=u;
}
Sender::~Sender() {
  
}

void Sender::show_node() {
    cout << "\033[1;36m╔════════════════════════════════════════╗\033[0m" << endl;
    cout << "\033[1;36m║           PACKAGE DETAILS              ║\033[0m" << endl;
    cout << "\033[1;36m╠════════════════════════════════════════╣\033[0m" << endl;
    cout << "\033[1;36m║\033[0m \033[1;32mRecipient:\033[0m " << setw(28) << left << name << "\033[1;36m║\033[0m" << endl;
    cout << "\033[1;36m║\033[0m \033[1;32mAddress:\033[0m " << setw(30) << left << address << "\033[1;36m║\033[0m" << endl;
    cout << "\033[1;36m║\033[0m \033[1;32mProduct:\033[0m " << setw(30) << left << product << "\033[1;36m║\033[0m" << endl;
    cout << "\033[1;36m║\033[0m \033[1;32mWeight:\033[0m " << setw(24) << left << (to_string(weight) + " kg") << "\033[1;36m║\033[0m" << endl;
    cout << "\033[1;36m╚════════════════════════════════════════╝\033[0m" << endl;
}
void Sender::loadUsedTrackingNumbers(const string& filename) {
    ifstream inFile(filename);
    if (!inFile) return;

    string user, name, address, product, trackingNumber;
    float weight;

    while (inFile >> user >> name >> address >> product >> weight >> trackingNumber) {
        generatedTrackingNumbers.insert(trackingNumber);  // ใช้ได้ เพราะอยู่ในคลาส Sender
    }

    inFile.close();
}

string Sender::generateTrackingNumber() {
    string trackingNumber;
    do {
        Sender::loadUsedTrackingNumbers("packages.txt");
        trackingNumber = "TN" + to_string(rand() % 1000000); // สุ่มเลข 6 หลัก
    } while (generatedTrackingNumbers.find(trackingNumber) != generatedTrackingNumbers.end()); // ตรวจสอบเลขซ้ำ
    generatedTrackingNumbers.insert(trackingNumber); // เก็บหมายเลขที่สุ่มแล้ว
    return trackingNumber;
}

void Sender::saveToFile(const string& filename) {
    ofstream outFile(filename, ios::app);
    if (outFile.is_open()) {
        outFile << username << " " << name << " " << address << " " << product << " " << weight << " " << generateTrackingNumber() << endl;
        outFile.close();
    } else {
        cout << "Failed to open file!" << endl;
    }
}

void sender_menu(string& username) {
    LL A;
    float w;
    string n, a, p, t;
    int l;
    int choice;
    bool validWeight;

    cout << "\033[1;34mLogged in as: " << username << " (Sender)\033[0m" << endl;

    do {
        choice = sender_getChoice();
        switch (choice) {
            case 1: {  // Added braces to create a new scope
                l = (rand() % 100000);
                cout << "\033[1;33m╔════════════════════════════════════════╗\033[0m" << endl;
                cout << "\033[1;33m║        NEW PACKAGE INFORMATION         ║\033[0m" << endl;
                cout << "\033[1;33m╚════════════════════════════════════════╝\033[0m" << endl;
                
                // Validate recipient name input
                do {
                    cout << "\033[1;33mInput ชื่อผู้รับ: \033[0m";
                    getline(cin, n);
                    if (n.empty()) {
                        cout << "\033[1;31mRecipient name cannot be empty. Please enter a name.\033[0m" << endl;
                    }
                } while (n.empty());
                
                // Validate address input
                do {
                    cout << "\033[1;33mInput ที่อยู่: \033[0m";
                    getline(cin, a);
                    if (a.empty()) {
                        cout << "\033[1;31mAddress cannot be empty. Please enter an address.\033[0m" << endl;
                    }
                } while (a.empty());
                
                // Validate product input
                do {
                    cout << "\033[1;33mInput สินค้า: \033[0m";
                    getline(cin, p);
                    if (p.empty()) {
                        cout << "\033[1;31mProduct cannot be empty. Please enter a product.\033[0m" << endl;
                    }
                } while (p.empty());
                
                // Validate weight input
                validWeight = false;
                do {
                    cout << "\033[1;33mInput น้ำหนัก: \033[0m";
                    if (cin >> w) {
                        if (w <= 0) {
                            cout << "\033[1;31mWeight must be greater than 0. Please enter a valid weight.\033[0m" << endl;
                        } else {
                            validWeight = true;
                        }
                    } else {
                        cout << "\033[1;31mInvalid input. Please enter a numeric value for weight.\033[0m" << endl;
                        cin.clear(); // Clear error flag
                        cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Discard invalid input
                    }
                } while (!validWeight);
                
                // Clear input buffer after reading numeric input
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                
                // Generate tracking number and create package
                t = Sender::generateTrackingNumber();
                {
                    Sender* z = new Sender(l, n, a, p, w, username);
                    A.add_node(z);
                    z->saveToFile("packages.txt");
                    cout << "\033[1;32mPackage created successfully!\033[0m" << endl;
                    cout << "\033[1;32mTracking Number: " << t << "\033[0m" << endl;
                    cout << "\nPress Enter to continue...";
                    cin.get();
                }
                break;
            }
            case 2: {  // Added braces to create a new scope
                cout << "\033[1;36m╔════════════════════════════════════════╗\033[0m" << endl;
                cout << "\033[1;36m║           YOUR PACKAGES                ║\033[0m" << endl;
                cout << "\033[1;36m╚════════════════════════════════════════╝\033[0m" << endl;
                showUserPackages(username);
                cout << "\nPress Enter to continue...";
                cin.ignore();
                cin.get();
                clearScreen();
                break;
            }
            case 3: {  // Added braces to create a new scope
                cout << "\033[1;32mGoing back to previous menu...\033[0m" << endl;
                return;
            }
            case 4: {  // Added braces to create a new scope
                cout << "\033[1;31mExiting program...\033[0m" << endl;
                exit(0);
            }
            default: {  // Added braces to create a new scope
                cout << "\033[1;31mInvalid choice. Please try again.\033[0m" << endl;
                break;
            }
        }
    } while (true);
}

void showUserPackages(string& username) {
    ifstream inFile("packages.txt");
    if (!inFile) {
        cout << "Failed to open packages.txt!" << endl;
        return;
    }

    string line;
    bool found = false;

    while (getline(inFile, line)) {
        istringstream iss(line);
        string user, name, address, product, trackingNumber, status;
        float weight;
        
        if (iss >> user >> name >> address >> product >> weight >> trackingNumber) {
            // Optional status field
            iss >> status;
            
            if (user == username) {
                found = true;
                cout << "\033[1;32mชื่อผู้รับ: \033[0m" << name << endl;
                cout << "\033[1;32mที่อยู่: \033[0m" << address << endl;
                cout << "\033[1;32mสินค้า: \033[0m" << product << endl;
                cout << "\033[1;32mน้ำหนัก: \033[0m" << weight << " kg" << endl;
                cout << "\033[1;32mเลขพัสดุ: \033[0m" << trackingNumber << endl;
                
                if (!status.empty()) {
                    cout << "\033[1;32mสถานะ: \033[0m" << status << endl;
                } else {
                    cout << "\033[1;32mสถานะ: \033[0m" << "Pending" << endl;
                }
                
                cout << "\033[1;33m========================================\033[0m" << endl;
            }
        }
    }

    if (!found) {
        cout << "\033[1;31mNo packages found for user " << username << "\033[0m" << endl;
    }

    inFile.close();
}
