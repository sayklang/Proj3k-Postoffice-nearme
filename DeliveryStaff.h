#ifndef DELIVERYSTAFF_H
#define DELIVERYSTAFF_H

#include <string>
#include "Menu.h"
#include "LL.h"
#include "Node.h"
#include <iostream>
#include <fstream>
#include <sstream>
using namespace std;


void Deli_menu(string& username);
void readAndShowByTracking(const string& filename, const string& trackingNumber);
#endif