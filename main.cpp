#include <iostream>  
#include <string>
#include <fstream>
#include <regex> 

#include "User.h"
#include "Menu.h"

using namespace std;


int main(){
User user;
int choice;


showMenu();
choice=getChoice();

    switch (choice)
    {
    case 1:
    user.LoginSystem();
        break;
    case 2:
    user.RegisterSystem();
        break;
    case 3:
    cout << "Exiting...\n";
        break;
    
    default:
    cout << "Invalid choice. Please try again.\n";
        break;
    }

}


