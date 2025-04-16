#ifndef SENDER_H
#define SENDER_H

#include <string>
#include <cstdlib>
#include <set>
#include <fstream> // สำหรับการอ่าน/เขียนไฟล์
#include "Menu.h"
#include "LL.h"
#include "Node.h"
using namespace std;

class Sender : public NODE {
private:
    string name;
    string address;
    string product;
    float weight;
    string username;
    static set<string> generatedTrackingNumbers; // ใช้เพื่อเก็บหมายเลขที่สุ่มแล้ว

public:
    Sender(int, string, string, string, float, string);  // คอนสตรัคเตอร์
    ~Sender();
    static string generateTrackingNumber();  // ฟังก์ชัน static
    void show_node() override;
    void saveToFile(const string& filename);
    static void loadUsedTrackingNumbers(const string& filename); // <<< เพิ่มบรรทัดนี้
};

void sender_menu(string& username);
void showUserPackages(string& username);

#endif
