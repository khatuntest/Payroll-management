#include "Payroll_Management.h"
#include <iostream>

Payroll_Management::Payroll_Management() :  f(),a(), e(a, f) {}

void Payroll_Management :: Welcome(){
    cout << "*************************************\n" ;
    cout << "*       Payroll Management System   *\n";
    cout << "*************************************\n";
    cout << "*     Welcome to the Payroll System  *\n";
    cout << "*     Please follow the instructions *\n";
    cout << "*************************************\n\n";
    cout << "This system allows you to manage employee payroll efficiently.\n" ;
    cout << "You can log in, manage employee information, and generate payslips.\n" ;
    cout << "Please log in to continue \n";
}
bool Payroll_Management ::Login_ForAdmin(){
    string user,pass;
    cout<<"Enter Your Username :\n";
    cin>>user;
    cout<<"Enter Your Password  :\n";
    cin>>pass;
    for (auto & i : a.admins){
        if (i.username == user && i.password == pass)
            return true;
    }
    cout<<"Error : The password or Username is Wrong.\n";
    return false;

}
bool Payroll_Management :: Login_ForEmployee(){
    string user,pass;
    cout<<"Enter Your Username :\n";
    cin>>user;
    cout<<"Enter Your Password  :\n";
    cin>>pass;
    for (auto & i : a.list){
        if (i.username == user && i.password == pass)
            return true;
    }
    cout<<"Error : The password or Username is Wrong.\n";
    return false;
}
void Payroll_Management ::  MenuForAdmin( ){
           int choice ;
            cout << "\nAdmin Menu:\n";
            cout << "1. Add Employee\n";
            cout << "2. Search Employee by ID\n";
            cout << "3. Edit Employee\n";
            cout << "4. Delete Employee\n";
            cout << "5. List Employees by ID\n";
            cout << "6. List Employees by Name\n";
            cout << "--- Finance Menu ---\n";
            cout << "7. Calculate Bonuses\n";
            cout << "8. Calculate Leaves\n" ;
            cout << "9. Calculate Taxes\n";
            cout << "10. Display Finance\n";
            cout << "11. Exit\n";
            std::cout << "Enter your choice: ";
           while (cin>>choice) {
               if (choice == 1)
                   a.addEmployees(f);
               if (choice == 2)
                   a.Search_By_ID();
               if (choice == 3)
                   a.Edit(f);
               if (choice == 4)
                   a.Delete();
               if (choice == 5)
                   a.List_By_ID();
               if (choice == 6)
                   a.List_By_Name();
               if (choice == 7)
                   f.calc_Bonus();
               if (choice == 8)
                   f.calc_leaves();
               if (choice == 9)
                   f.calc_taxes();
               if (choice == 10)
                   f.display();
               if (choice == 11) {
                   cout << "          Good Luck \n";
                   return;
               }
               if (choice < 1 || choice > 11)
                   cout << "The choice is not Exist Enter another.\n";

               std::cout << "Enter your choice: ";
           }
}

void Payroll_Management :: MenuForEmployee(){
    std::cout << "\nEmployee Menu:\n";
    std::cout << "1. View Your Information\n";
    std::cout << "2. Change Your Password\n";
    std::cout << "3. View Your Pay Slip\n";
    std::cout << "4. Exit\n";
    int choice ;
    cout << "Enter your choice: ";
    while (cin>>choice){
        if (choice == 1)
            e.View_information();
        if(choice == 2)
            e.Change_Password();
        if (choice == 3){
            e.View_paySlip();}
        if (choice == 4){
            cout << "          Good Luck \n";
            return ;
        }
        if (choice < 1 || choice > 4)
            cout<<"The choice is not Exist Enter another.\n";

        cout << "Enter your choice: ";
    }
}


