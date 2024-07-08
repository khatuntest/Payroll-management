#include "admin.cpp"
#include "Finance.cpp"
#include "Employees.cpp"
#include "Payroll_Management.h"
using namespace std ;

int main() {
    Payroll_Management pm;
    Payroll_Management::Welcome();
    int option;
    cout<<"IF You are Admin Enter 1\n"
          "IF You are Employee Enter 2\n"
          "IF You Want to Exit Enter 3\n";
    cout<<"Enter Your Option.\n";
    while(cin>>option){
        if (option == 1){// this is admin
            if (pm.Login_ForAdmin()) {
                pm.MenuForAdmin();
            }
        }
        if (option == 2){//this is Employee
            if(pm.Login_ForEmployee())
                pm.MenuForEmployee();

        }
        if (option == 3){ // to Exist
            cout << "          Good Luck \n";
            return 0;
        }
        if (option < 1 || option > 3)
            cout<<"This is Option doesn't Exist.\n";

        cout<<"1. IF You are Admin Enter 1\n";
        cout<<"2. IF You are Employee Enter 2\n";
        cout<<"3. IF You Want to Exit Enter 3\n";
        cout<<"Enter Your Option.\n";
    }

    return 0;
}

