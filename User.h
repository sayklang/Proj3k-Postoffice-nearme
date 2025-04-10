#ifndef USER_H
#define USER_H

using namespace std;

// สร้างคลาส User สำหรับเก็บข้อมูลผู้ใช้
class User {
private:
    string username;
    string password;
public :
     // Constructor
     User(string uname, string pass) {
        username=uname;
        password=pass;
     }
     // default constructor
    User() : username(""), password("") {}

    //bool เก็บค่าTrue/False
    //สำหรับLoginSystem
     bool checkLogin(string inputUser, string inputPass) {
        return (inputUser == username && inputPass == password);
    }
    
    // ฟังก์ชัน static สำหรับตรวจสอบข้อมูลการล็อกอิน
    static bool login(const string& filename, const string& username, const string& password) {
        ifstream inFile(filename);
        if (inFile.is_open()) {
        string existingUsername, existingPassword;
        while (inFile >> existingUsername >> existingPassword) {
            if (existingUsername == username && existingPassword == password) {
                inFile.close();
                return true; // หากข้อมูลตรงกัน
            }
        }
        inFile.close();
    }
    return false; // ถ้าข้อมูลไม่ตรงกัน
}




    //สำหรับRegister
     // ฟังก์ชันสำหรับบันทึกข้อมูลผู้ใช้ลงในไฟล์
     void saveToFile(const string& filename) {
        ofstream outFile(filename, ios::app);  // เปิดไฟล์ในโหมด append
        if (outFile.is_open()) {
            outFile << username << " " << password << endl;
            outFile.close();
        } else {
            cout << "Failed to open file!" << endl;
        }
    }
    static bool isUsernameTaken(const string& filename, const string& username) {
        ifstream inFile(filename);
        if (inFile.is_open()) {
            string existingUsername, password;
            while (inFile >> existingUsername >> password) {
                if (existingUsername == username) {
                    inFile.close();
                    return true; // ถ้ามีชื่อผู้ใช้ซ้ำ
                }
            }
            inFile.close();
        }
        return false; // ถ้าไม่พบชื่อผู้ใช้ในไฟล์
    }


    static bool isValidUsername(const string& username) {
        // ใช้ regex ตรวจสอบว่า Password ประกอบด้วยตัวอักษรภาษาอังกฤษ, ตัวเลข และอักขระพิเศษที่อนุญาต (_ - .)
        regex pattern("^[a-zA-Z0-9ก-๙_-]+$");  // ต้องมีตัวอักษรและตัวเลขอย่างน้อย 8 ตัว
        return regex_match(username, pattern);  // ตรวจสอบว่า username ตรงกับ pattern นี้หรือไม่
    }


    static bool isValidPassword(const string& password) {
        // ใช้ regex ตรวจสอบว่า Password ประกอบด้วยตัวอักษรภาษาอังกฤษ, ตัวเลข และอักขระพิเศษที่อนุญาต (_ - .)
        regex pattern("^[a-zA-Z0-9_-]{8,}$");  // ต้องมีตัวอักษรหรือตัวเลขอย่างน้อย 8 ตัว
        return regex_match(password, pattern);  // ตรวจสอบว่า username ตรงกับ pattern นี้หรือไม่
    }





    void LoginSystem(){
        // ล็อกอิน
        cout << "Enter username: ";
        cin >> username;
        cout << "Enter password: ";
        cin >> password;
   
        // เช็คข้อมูลการล็อกอิน
        if (User::login("users.txt", username, password)) 
        {
            cout << "Login successful!" << endl;
        } 
        else {
            cout << "Invalid username or password!" << endl;
        }
   
    } 

   
   
   void RegisterSystem(){
       cout << "Enter username: ";
       cin >> username;
   
       // เช็คว่ามีชื่อผู้ใช้นี้ในไฟล์หรือไม่
       if (User::isUsernameTaken("users.txt", username))
        {
           cout << "Username is already taken! Please choose a different one." << endl;
       } 
       if(User::isValidUsername(username)==false)
       {
        cout << "Only thai eng number and _ - " << endl;
       }

       else {
           cout << "Enter password: ";
           cin >> password;
        if(User::isValidPassword(password)==true){
        // สร้าง object ของ User และบันทึกข้อมูลลงในไฟล์
        User newUser(username, password);
        newUser.saveToFile("users.txt");
        cout << "User registered successfully!" << endl;
       }
       else  cout << "Only eng number _ -  and 8 ตัว!" << endl;
    }
   }

};


#endif