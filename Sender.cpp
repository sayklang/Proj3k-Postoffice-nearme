#include <iostream>
#include "Sender.h"
#include "User.h"  

using namespace std;

Sender::Sender(int l, string n, string a, string p, float w,string u) : NODE(l) {
    name = n;
    address = a;
    product = p;
    weight = w;
    username=u;
}
Sender::~Sender() {
    // Destructor code
}

void Sender::show_node() {
    cout << "ชื่อผู้รับ: " << name << endl;
    cout << "ที่อยู่: " << address << endl;
    cout << "สินค้า: " << product << endl;
    cout << "น้ำหนัก: " << weight << " kg" << endl;
    if (!trackingNumber.empty()) {
        cout << "Tracking No: " << trackingNumber << endl;
    }
}

void Sender::generateTrackingNumber() {
    trackingNumber = "TN" + to_string(rand() % 1000);
}

string Sender::getTrackingNumber() {
    return trackingNumber;
}

void sender_menu(string& username) {
    LL A;
    float w;
    string n, a, p;
    int l;
    int choice;
    cout << "Logged in as: " << username << endl;
    do {
        choice = sender_getChoice();
        switch (choice) {
            case 1:
                cout << "Node (ID): ";
                cin >> l;
                cout << "Input ชื่อผู้รับ: ";
                cin >> n;
                cout << "Input ที่อยู่: ";
                cin >> a;
                cout << "Input สินค้า: ";
                cin >> p;
                cout << "Input น้ำไม่เบา: ";
                cin >> w;

                {
                    Sender* z = new Sender(l, n, a, p, w,username);
                    A.add_node(z);
                    z->saveToFile("packages.txt");
                }
                break;
            case 2:
            cout << "แสดงข้อมูลของทุกพัสดุ: " << endl;
            //A.show_all();
            cout << "--------------------------" << endl;
            showUserPackages(username);
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


void Sender::saveToFile(const string& filename) {
    ofstream outFile(filename, ios::app);
    if (outFile.is_open()) {
        outFile << username << "," << name << "," << address << "," << product << "," << weight << endl;
        outFile.close();
    } else {
        cout << "Failed to open file!" << endl;
    }
}

void showUserPackages(string& username) {
    ifstream inFile("packages.txt");
    if (!inFile) {
        cout << "Failed to open packages.txt!" << endl;
        return;
    }

    string user, name, address, product;
    float weight;
    bool found = false;

    while (inFile >> user >> name >> address >> product >> weight) {
        if (user == username) {
            found = true;
            cout << "ชื่อผู้รับ: " << name << endl;
            cout << "ที่อยู่: " << address << endl;
            cout << "สินค้า: " << product << endl;
            cout << "น้ำหนัก: " << weight << " kg" << endl;
            cout<<"========================================"<<endl;
        }
    }

    if (!found) {
        cout << "No packages found for user " << username << endl;
    }

    inFile.close();
}



