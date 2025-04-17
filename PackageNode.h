#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <string>
#include <sstream>

void sortPackagesByWeight() {
    // Read packages
    std::ifstream inFile("packages.txt");
    if (!inFile) {
        std::cerr << "Error: Cannot open packages.txt" << std::endl;
        return;
    }
    
    // Store package data in vector
    std::vector<std::pair<float, std::string>> packages;
    std::string line;
    
    while (std::getline(inFile, line)) {
        std::istringstream iss(line);
        std::string username, name, address, product, trackingNumber, status;
        float weight;
        
        if (iss >> username >> name >> address >> product >> weight >> trackingNumber) {
            // Optionally read status if present
            iss >> status;
            // Store weight as key for sorting, and full line as value
            packages.push_back(std::make_pair(weight, line));
        }
    }
    
    inFile.close();
    
    // Sort packages by weight (ascending)
    std::sort(packages.begin(), packages.end());
    
    // Write sorted packages to new file
    std::ofstream outFile("sortpackage.txt");
    if (!outFile) {
        std::cerr << "Error: Cannot create sortpackage.txt" << std::endl;
        return;
    }
    
    for (const auto& package : packages) {
        outFile << package.second << std::endl;
    }
    
    outFile.close();
    
    std::cout << "Packages sorted by weight and saved to sortpackage.txt" << std::endl;
}