# Proj3k-Postoffice-nearme

Proj3k-Postoffice-nearme/
│
├── include/                # ไฟล์ header (.h)
│   ├── Sender.h            # class ผู้ส่ง
│   ├── DeliveryStaff.h     # class พนักงานส่งของ
│   └── PackageNode.h       # โหนดของ binary tree
│   └── User.h              # class user กับ Loginsystem
│   
│
├── .cpp/                    # ไฟล์ source (.cpp)
│   ├── main.cpp            # จุดเริ่มโปรแกรม
|   ├── test.cpp            # เทส
│   ├── Sender.cpp          #ฟังชั่น Sender.cpp
│   ├── DeliveryStaff.cpp   #ฟังชั่น DeliveryStaff.cpp
│   └── BinaryTree.cpp      # โครงสร้างต้นไม้ไบนารีเรียงตามน้ำหนัก
│
├── data/                   # ข้อมูลจำลองหรือเก็บไฟล์บันทึก
│   └── dummy_data.txt      #dummy_data.txt = ไฟล์ที่ใส่ข้อมูลจำลองไว้ใช้สำหรับ ทดสอบโปรแกรม 
│
│
├── README.md               # อธิบายโปรเจกต์
├── Makefile                # หรือ CMakeLists.txt ถ้าใช้ CMake