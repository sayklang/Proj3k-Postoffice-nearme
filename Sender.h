#ifndef SENDER_H
#define SENDER_H

#include <string>
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
    string trackingNumber;
    string username;

public:
    Sender(int, string, string, string, float,string);
    void generateTrackingNumber();
     ~Sender();
    string getTrackingNumber();
    void show_node() override;
    void saveToFile(const string& filename);
    
};
void sender_menu(string& username);
void showUserPackages(string& username);
#endif
