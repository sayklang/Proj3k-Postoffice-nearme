#include "Sender.h"
#include <fstream> // สำหรับการอ่าน/เขียนไฟล์
#include <sstream> 

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
    cout << "ชื่อผู้รับ: " << name << endl;
    cout << "ที่อยู่: " << address << endl;
    cout << "สินค้า: " << product << endl;
    cout << "น้ำหนัก: " << weight << " kg" << endl;
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

    cout << "\033[1;34mLogged in as: " << username << " (Sender)\033[0m" << endl;

    do {
        choice = sender_getChoice();
        switch (choice) {
            case 1:
                l = (rand() % 100000);
                cin.ignore();  // Clear input buffer
                cout << "\033[1;33mInput ชื่อผู้รับ: \033[0m";
                getline(cin, n);
                cout << "\033[1;33mInput ที่อยู่: \033[0m";
                getline(cin, a);
                cout << "\033[1;33mInput สินค้า: \033[0m";
                getline(cin, p);
                cout << "\033[1;33mInput น้ำหนัก: \033[0m";
                cin >> w;
                // สร้าง tracking number ใหม่
                t = Sender::generateTrackingNumber();
                {
                    Sender* z = new Sender(l, n, a, p, w, username);
                    A.add_node(z);
                    z->saveToFile("packages.txt");
                    cout << "\033[1;32mPackage created successfully!\033[0m" << endl;
                    cout << "\033[1;32mTracking Number: " << t << "\033[0m" << endl;
                    cout << "\nPress Enter to continue...";
                    cin.ignore();
                    cin.get();
                }
                break;
            case 2:
                cout << "\033[1;36mแสดงข้อมูลของทุกพัสดุ: \033[0m" << endl;
                cout << "--------------------------" << endl;
                showUserPackages(username);
                cout << "\nPress Enter to continue...";
                cin.ignore();
                cin.get();
                break;
            case 3:
                cout << "\033[1;32mGoing back to previous menu...\033[0m" << endl;
                return;
            case 4:
                cout << "\033[1;31mExiting program...\033[0m" << endl;
                exit(0);
            default:
                cout << "\033[1;31mInvalid choice. Please try again.\033[0m" << endl;
                break;
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
