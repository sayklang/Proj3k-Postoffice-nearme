#ifndef PACKAGENODE_H
#define PACKAGENODE_H

#include <iostream>
#include <fstream>
#include <string>
#include <sstream>

struct PackageNode {
    std::string username;
    std::string lineData;
    PackageNode* next;

    PackageNode(const std::string& user, const std::string& line)
        : username(user), lineData(line), next(nullptr) {}
};

class PackageList {
private:
    PackageNode* head;

    // ตัวช่วยแทรกเรียงตามตัวอักษร
    void insertSorted(PackageNode* newNode) {
        if (!head || newNode->username < head->username) {
            newNode->next = head;
            head = newNode;
            return;
        }

        PackageNode* current = head;
        while (current->next && current->next->username < newNode->username) {
            current = current->next;
        }

        newNode->next = current->next;
        current->next = newNode;
    }

public:
    PackageList() : head(nullptr) {}

    ~PackageList() {
        while (head) {
            PackageNode* temp = head;
            head = head->next;
            delete temp;
        }
    }

    void loadFromFile(const std::string& filename) {
        std::ifstream inFile(filename);
        if (!inFile) {
            std::cerr << "Error: Cannot open " << filename << std::endl;
            return;
        }

        std::string line;
        while (std::getline(inFile, line)) {
            std::istringstream iss(line);
            std::string username;
            if (iss >> username) {
                PackageNode* newNode = new PackageNode(username, line);
                insertSorted(newNode);
            }
        }

        inFile.close();
    }

    void writeToFile(const std::string& filename) {
        std::ofstream outFile(filename);
        if (!outFile) {
            std::cerr << "Error: Cannot open " << filename << " for writing" << std::endl;
            return;
        }

        PackageNode* current = head;
        while (current) {
            outFile << current->lineData << std::endl;
            current = current->next;
        }

        outFile.close();
    }
};

// ฟังก์ชันสำหรับใช้เรียกใน main ได้เลย
void sortPackagesByUsername_LL() {
    PackageList list;
    list.loadFromFile("packages.txt");
    list.writeToFile("packages.txt");
}

#endif // PACKAGENODE_H
