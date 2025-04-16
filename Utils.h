#ifndef UTILS_H
#define UTILS_H

#include  <iostream>

// Function to clear the screen - marked as inline to avoid multiple definition errors
inline void clearScreen() {
    // ANSI escape codes to clear screen and move cursor to top-left
    std::cout << "\033[2J\033[1;1H";
    
    // Alternative methods:
    // system("clear");  // For Unix/Linux
    // system("cls");    // For Windows
}

#endif // UTILS_H