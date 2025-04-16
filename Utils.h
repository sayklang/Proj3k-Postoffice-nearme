#ifndef UTILS_H
#define UTILS_H

#include <iostream>
#include <unistd.h> // สำหรับ usleep()

inline void clearScreen() {
    usleep(1000000); // หน่วงเวลา 1 วินาทีก่อนล้างหน้าจอ
    std::cout << "\033[2J\033[1;1H"; // ล้างหน้าจอสำหรับ Linux
}

#endif // UTILS_H
