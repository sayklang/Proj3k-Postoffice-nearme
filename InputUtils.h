#ifndef INPUT_UTILS_H
#define INPUT_UTILS_H

#include <iostream>
#include <limits>
using namespace std;

// Function to get valid integer input
inline int getValidIntInput() {
    int choice;
    while (!(cin >> choice)) {
        // Clear the error state
        cin.clear();
        // Discard invalid input
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "\033[1;31mInvalid input. Please enter a number.\033[0m" << endl;
    }
    // Clear any remaining characters from the input buffer
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    return choice;
}

#endif // INPUT_UTILS_H