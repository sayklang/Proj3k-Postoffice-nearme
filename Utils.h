#ifndef UTILS_H
#define UTILS_H

#include <iostream>
#include <unistd.h> // สำหรับ usleep()


// Cross-platform clear screen function
inline void clearScreen() {
    #ifdef _WIN32
        system("cls");
    #else
        system("clear");  // For Linux/Unix
    #endif
}

#endif // UTILS_H