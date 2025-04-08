#ifndef USER_H
#define USER_H

#include <string>
using namespace std;

class User {
private:
    string username;
    string password;

public :
     // Constructor
     User(string uname, string pass) : username(uname), password(pass) {}

     // Getter สำหรับ username และ password
     string getUsername() const {
         return username;
     }
 
     string getPassword() const {
         return password;
     }
 
     // ฟังก์ชันตรวจสอบรหัสผ่าน
     bool checkPassword(const string& pass) const {
         return password == pass;
     }















#endif