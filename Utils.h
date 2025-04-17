#ifndef UTILS_H
#define UTILS_H

#include <iostream>
#include <unistd.h> // สำหรับ usleep()

inline void clearScreen() {
    usleep(500000); // หน่วงเวลา 0.5 วินาทีก่อนล้างหน้าจอ (ลดจาก 1 วินาที)
    std::cout << "\033[2J\033[1;1H"; // ล้างหน้าจอสำหรับ Linux
}

// แสดงข้อความ loading สำหรับเพิ่มความสมจริง
inline void showLoading(const std::string& message) {
    std::cout << "\033[1;33m" << message;
    for (int i = 0; i < 3; i++) {
        std::cout << ".";
        std::cout.flush();
        usleep(300000); // 0.3 วินาที
    }
    std::cout << "\033[0m\n";
}

#endif // UTILS_H