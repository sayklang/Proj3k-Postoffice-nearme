#include <iostream>  
#include <string>
#include <fstream>
#include <regex> 

#include "User.h"
#include "Menu.h"
#include "Utils.h"  // Include the new header

using namespace std;

int main(){
User user;
int choice;
while (choice!=3)
{
showMenu();
choice=getChoice();
/*if (choice=101)
{
E3();
}
else*/
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
    cout << "\033[1;31m==================================================="<<endl;
    cout << "Invalid choice. Please try again.\n";
    cout<<"===================================================\033[0m"<<endl;
        break;
    }//switch
}//Loop
}//main


