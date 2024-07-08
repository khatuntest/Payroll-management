#include <iostream>
#include <string>
#include "Employees.h"

Employees::Employees(admin& m, Finance& F) : d(m), f(F) {}

void Employees ::  View_information(){
    cout<<"Please Enter Your ID.\n";
    int id ;
    cin>>id;
    for (auto & i : d.list){
        if (i.id == id ){
            std::cout << std::left
                      << std::setw(5) << "ID"
                      << std::setw(20) << "Name"
                      << std::setw(20) << "Position"
                      << std::setw(15) << "Department"
                      << std::setw(10) << "Salary"
                      << std::setw(20) << "Username"
                      << std::setw(20) << "Password"
                      << std::endl;

            std::cout << std::left
                      << std::setw(5) << i.id
                      << std::setw(20) << i.name
                      << std::setw(20) << i.position
                      << std::setw(15) << i.department
                      << std::setw(10) << i.salary
                      << std::setw(20) << i.username
                      << std::setw(20) << i.password
                      << std::endl;

            std::cout << "          Good Luck \n";
            return;
        }
    }
    cout<<"The Employee doesn't Exist.\n";

}

void Employees :: Change_Password(){
    cout<<"Please Enter Your ID.\n";
    int id ;
    cin>>id;
    cout<<"Please Enter The New Password.\n";
    string pass;
    cin>>pass;
    for (auto & i : d.list){
        if (i.id  == id ){
            i.password = pass;
            return void (cout << "Password for employee with ID " << id <<
            " has been successfully updated." << endl);
        }
    }
    cout<<"This ID doesn't Exist.\n";

}
void Employees :: View_paySlip(){
    cout<<"Please Enter Your ID.\n";
    int id ;
    cin>>id;
    f.Sort_By_id();
    if (f.Fin.empty())
        return void (cout<<"Don't Have Employees.\n");

    for (auto & i : f.Fin){
        if (i[0] == id){
            cout << left << setw(10) << "ID"
                 << setw(10) << "Salary"
                 << setw(10) << "Bonus"
                 << setw(10) << "Leaves"
                 << setw(10) << "Taxes"
                 << setw(15) << "Net Salary"
                 << endl;
            cout << left << std::setw(10) << i[0]
                      << std::setw(10) << i[1]
                      << std::setw(10) << i[2]
                      << std::setw(10) << i[3]
                      << std::setw(10) << i[4]
                      << std::setw(15) << i[5]
                      << std::endl;
            cout<<"          Good Luck \n";
            return ;
        }
    }
    cout<<"The ID is not Exist.\n";

}