//class Sender
#ifndef DELIVERYSTAFF_H
#define DELIVERYSTAFF_H
#include <string>
using namespace std;
class DeliveryStaff {
    public:
        void getReceiverAddress(string trackingNumber);
        void displayDeliveryInfo(string trackingNumber);
    };
    #endif