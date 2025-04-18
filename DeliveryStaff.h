#ifndef DELIVERYSTAFF_H
#define DELIVERYSTAFF_H

#include <string>
#include "Menu.h"
#include "LL.h"
#include "Node.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
using namespace std;

void Deli_menu(string& username);
void readAndShowByTracking(const string& filename, const string& trackingNumber);
void updatePackageStatus(const string& trackingNumber);
bool isValidTrackingNumber(const string& trackingNumber); // New function declaration

#endif