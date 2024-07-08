#include "Finance.h"
#include <iostream>
#include <iomanip>

//[0      1       2     3       4       5      ]
//[id , salary , bon, leaves , tax , net salary]
Finance::Finance() : admin() {}

void Finance::addEmployee(employee & e) {
    list.push_back(e);
    length++;
    Fin.push_back({e.id, e.salary, 0, 0, 0 , e.salary}); // Initialize bonus, leaves, and taxes to 0
}

void Finance :: calc_Bonus (){
    cout<<"Please Enter Your ID.\n";
    int id;
    cin>>id;
    cout<<"Please Enter Your Amount of Bounce.\n";
    int bon;
    cin>>bon;
    for (auto & i : Fin)
        if (i[0] == id) {
            i[2] += bon;
            i[5]+=bon;
            return;
        }

    cout<<"Error : The Employee With id "<<id<<" doesn't exist!!\n";

}
void Finance :: calc_leaves(){
    // let day = 2$
    cout<<"Please Enter Your ID.\n";
    int id;
    cin>>id;
    cout<<"Please Enter Your Number of Days.\n";
    int num_of_days;
    cin>>num_of_days;
    if (length == 0)
        return ;
    for (auto & i : Fin){
        if (i[0] == id){
            i[3]+=num_of_days;
            i[5]=max((i[5]-2*num_of_days) , 0);
            return;
        }
    }
    cout<<"Error : The Employee With id "<<id<<" doesn't exist!!\n";

}
void Finance :: calc_taxes(){
    cout<<"Please Enter Your ID.\n";
    int id;
    cin>>id;
    cout<<"Please Enter Your Amount of Taxes.\n";
    int taxes;
    cin>>taxes;
    if (length == 0)
        return ;
    for (auto & i : Fin){
        if (i[0] == id){
            i[4]+=taxes;
            i[5]=max((i[5] - taxes) , 0);
            return;
        }
    }
    cout<<"Error : The Employee With id "<<id<<" doesn't exist!!\n";

}
void Finance :: Sort_By_id(){
    if (!Fin.empty()){
        sort(Fin.begin(), Fin.end(), [](const vector<int>& a, const vector<int>& b) {
            return a[0] < b[0];
        });
    }
}
void Finance ::display() {
    Sort_By_id();
    std::cout << std::left << std::setw(10) << "ID"
              << std::setw(15) << "Name"
              << std::setw(15) << "Position"
              << std::setw(10) << "Salary"
              << std::setw(10) << "Bonus"
              << std::setw(10) << "Leaves"
              << std::setw(10) << "Taxes"
              << std::setw(15) << "Net Salary"
              << std::endl;

    for (const auto& emp : list) {
        auto it = std::find_if(Fin.begin(), Fin.end(), [&emp](const std::vector<int>& vec) {
            return vec[0] == emp.id;
        });
        if (it != Fin.end()) {
            long long idx = distance(Fin.begin(), it);
            std::cout << std::left << std::setw(10) << emp.id
                      << std::setw(15) << emp.name
                      << std::setw(15) << emp.position
                      << std::setw(10) << emp.salary
                      << std::setw(10) << Fin[idx][2]
                      << std::setw(10) << Fin[idx][3]
                      << std::setw(10) << Fin[idx][4]
                      << std::setw(15) << Fin[idx][5]
                      << std::endl;
        }
    }
    cout<<"          Good Luck \n";
}
