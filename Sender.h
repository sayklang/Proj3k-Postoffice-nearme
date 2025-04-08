//class Sender
#ifndef SENDER_H
#define SENDER_H
#include <string>
using namespace std;

class Sender {
    private:
        string name;
        string address;
        string product;
        float weight;
        string trackingNumber;
    public:
        void inputData();
        void generateTrackingNumber();
        string getTrackingNumber();
        string getReceiverAddress();
        float getWeight();
    };
    #endif