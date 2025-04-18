// Add this function to your project, perhaps in PackageNode.h or create a new utility file

#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <string>
#include <sstream>

void sortPackagesByUsername() {
    // Read packages
    std::ifstream inFile("packages.txt");
    if (!inFile) {
        std::cerr << "Error: Cannot open packages.txt" << std::endl;
        return;
    }
    
    // Store package data in vector
    std::vector<std::pair<std::string, std::string>> packages;
    std::string line;
    
    while (std::getline(inFile, line)) {
        std::istringstream iss(line);
        std::string username;
        
        // Extract just the username (first word in each line)
        if (iss >> username) {
            // Store username as key for sorting, and full line as value
            packages.push_back(std::make_pair(username, line));
        }
    }
    
    inFile.close();
    
    // Sort packages by username (alphabetically)
    std::sort(packages.begin(), packages.end());
    
    // Write sorted packages back to the original file
    std::ofstream outFile("packages.txt");
    if (!outFile) {
        std::cerr << "Error: Cannot open packages.txt for writing" << std::endl;
        return;
    }
    
    for (const auto& package : packages) {
        outFile << package.second << std::endl;
    }
    
    outFile.close();
}