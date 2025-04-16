#include "Sender.h"
#include <fstream> // สำหรับการอ่าน/เขียนไฟล์

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
    string n, a, p, t;  // ประกาศ t ไว้ก่อนใช้งาน
    int l;
    int choice;

    cout << "Logged in as: " << username << endl;

    do {
        choice = sender_getChoice();
        switch (choice) {
            case 1:
                l = (rand() % 100000);
                cout << "Input ชื่อผู้รับ: ";
                cin >> n;
                cout << "Input ที่อยู่: ";
                cin >> a;
                cout << "Input สินค้า: ";
                cin >> p;
                cout << "Input น้ำหนัก: ";
                cin >> w;
                // สร้าง tracking number ใหม่
                t = Sender::generateTrackingNumber();  // กำหนดค่าให้ t ก่อนจะใช้
                {
                    Sender* z = new Sender(l, n, a, p, w, username);  // ไม่ต้องส่ง t เพราะ tracking number ถูกสร้างโดยอัตโนมัติ
                    A.add_node(z);
                    z->saveToFile("packages.txt");
                }
                break;
            case 2:
                cout << "แสดงข้อมูลของทุกพัสดุ: " << endl;
                // A.show_all(); // ถ้าใช้ linked list ก็ปลดคอมเมนต์อันนี้
                cout << "--------------------------" << endl;
                showUserPackages(username); // ฟังก์ชันแสดงพัสดุของ user นี้
                break;
            case 3:
                cout << "Going back to previous menu..." << endl;
                return; // กลับไปหน้า sender_or_Deli()
            case 4:
                cout << "Exiting program..." << endl;
                exit(0);
            default:
                cout << "Invalid choice. Please try again." << endl;
                break;
        }
    } while (true); // ใช้ while(true) แล้วออกด้วย return/exit
}

void showUserPackages(string& username) {
    ifstream inFile("packages.txt");
    if (!inFile) {
        cout << "Failed to open packages.txt!" << endl;
        return;
    }

    string user, name, address, product, trackingNumber;
    float weight;
    bool found = false;

    while (inFile >> user >> name >> address >> product >> weight >> trackingNumber) {
        if (user == username) {
            found = true;
            cout << "ชื่อผู้รับ: " << name << endl;
            cout << "ที่อยู่: " << address << endl;
            cout << "สินค้า: " << product << endl;
            cout << "น้ำหนัก: " << weight << " kg" << endl;
            cout << "เลขพัสดุ: " << trackingNumber << endl;
            cout << "========================================" << endl;
        }
    }

    if (!found) {
        cout << "No packages found for user " << username << endl;
    }

    inFile.close();
}
