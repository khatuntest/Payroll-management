#include <iostream>
#include <string>
#include <utility>
using namespace std;

#ifndef PROJECTS_EMPLOYEE_H
#define PROJECTS_EMPLOYEE_H

class employee{
public:
    int id , department , salary;
    string name , position , username , password;
    employee(int d, string nm , int depart, string pos ,int sal , string user , string pass ):
    id(d),name(std::move(nm)),department(depart),salary(sal),username(std::move(user))
    ,position (std::move(pos)),password(std::move(pass))
    {}
    bool operator==(const employee& other) const {
        return id == other.id;
    }
};
#endif //PROJECTS_EMPLOYEE_H
