#include "admin.h"
#include <iostream>
#include <algorithm>
#include <limits>
#include <iomanip>
#include "Finance.h"

admin::admin() {
    length = 0;
    admins.emplace_back(1, "menna", 5, "manager", 3500, "manon", "m234");
    admins.emplace_back(3, "mohammed", 6, "manger", 7000, "hamad", "m235");
    admins.emplace_back(2, "nada", 7, "manger", 3400, "nona", "n345");
}

admin::~admin() {
    list.clear();
}

void admin::addEmployees(Finance& F) {
    int id, department, salary;
    string name, position, username, password;

    cout << "Enter The Data.\n";
    cout << "Enter ID :\n";
    while (!(cin >> id)) {
        cout << "Invalid input. Please enter a numeric ID:\n";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    cout << "Enter Name :\n";
    cin >> name;

    cout << "Enter Department :\n";
    while (!(cin >> department)) {
        cout << "Invalid input. Please enter a numeric Department number:\n";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    cout << "Enter Position :\n";
    cin >> position;

    cout << "Enter Salary :\n";
    while (!(cin >> salary)) {
        cout << "Invalid input. Please enter a numeric Salary:\n";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    cout << "Enter Username :\n";
    cin >> username;

    cout << "Enter Password :\n";
    cin >> password;

    employee item(id, name, department, position, salary, username, password);

    auto it = find_if(list.begin(), list.end(),
                      [item](const employee& emp) { return emp.id == item.id; });
    if (it == list.end()) {
        list.push_back(item);
        length++;
        F.addEmployee(item);
        cout << "Employee added successfully.\n";
    } else {
        cout << "Error: Employee with ID " << item.id << " already exists.\n";
    }
}

void admin :: Search_By_ID(){
    cout<<"Please Enter The ID.\n";
    int id;
    cin>>id;
    if (length == 0)
        return void(cout<<"The List is Empty.\n");
    auto itm= find_if(list.begin() , list.end(),
                      [id](const employee& e){return e.id == id;});
    if (itm == list.end())
        return void (cout<<"The Employee doesn't exist . \n");
    cout << std::left
              << std::setw(10) << "ID"
              << std::setw(15) << "Name"
              << std::setw(15) << "Position"
              << std::setw(10) << "Department"
              << std::setw(10) << "Salary"
              << std::endl;
    cout << left << std::setw(10) << itm->id
              << setw(15) << itm->name
              << setw(15) << itm->position
              << setw(10) << itm->department
              << setw(10) << itm->salary
              << "\n";
}
void admin :: Edit(Finance& f){
    Delete();
    addEmployees(f);
    Sort_By_ID();
}
void admin::Sort_By_ID() {
    if (length ==  0)
        return void (cout<<"The List is Empty !!!\n");
    sort(list.begin()  , list.end() ,[](const employee& a , const employee& b){
        return a.id  < b.id;
    } );
}
void admin ::  Sort_By_Name(){
    if (length ==  0)
        return void (cout<<"The List is Empty !!!\n");
    sort(list.begin()  , list.end() ,[](const employee& a , const employee& b){
        return a.name  < b.name;
    } );

}
void admin ::Delete() {
    cout<<"Enter The old id.\n";
    int id ;
    cin>>id;
    if (length == 0)
        return void(cout<<"The List is Empty.\n");
    auto itm= find_if(list.begin() , list.end(),
                      [id]( const employee& e){return e.id == id;});
   if (itm == list.end())
       return void (cout<<"The Employee doesn't exist . \n");
   list.erase(itm);
   --length;
}
void admin ::List_By_ID () {
    if (list.empty()) {
        return void(cout << "The List is Empty !!!\n");
    }
    Sort_By_ID() ;
    std::cout << std::left
              << std::setw(10) << "ID"
              << std::setw(15) << "Name"
              << std::setw(15) << "Position"
              << std::setw(10) << "Department"
              << std::setw(10) << "Salary"
              << std::endl;

    for (const auto& emp : list) {
        auto it = std::find_if(list.begin(), list.end(),
                               [&emp](const employee &e) {return e.id == emp.id;});
        if (it != list.end()) {
            std::cout << left << std::setw(10) << emp.id
                      << setw(15) << emp.name
                      << setw(15) << emp.position
                      << setw(10) << emp.department
                      << setw(10) << emp.salary
                      << "\n";
        }
    }
    cout<<"          Good Luck \n";
}
void admin ::List_By_Name() {
        if (list.empty()) {
            return void(cout << "The List is Empty !!!\n");
        }
        Sort_By_Name();
        std::cout << std::left
                  << std::setw(10) << "ID"
                  << std::setw(15) << "Name"
                  << std::setw(15) << "Position"
                  << std::setw(10) << "Department"
                  << std::setw(10) << "Salary"
                  << std::endl;

        for (const auto &emp: list) {
            auto it = std::find_if(list.begin(), list.end(),
                                   [&emp](const employee &e) { return e.id == emp.id; });
            if (it != list.end()) {
                std::cout << left << std::setw(10) << emp.id
                          << setw(15) << emp.name
                          << setw(15) << emp.position
                          << setw(10) << emp.department
                          << setw(10) << emp.salary
                          << "\n";
            }
        }
        cout << "          Good Luck \n";
}
