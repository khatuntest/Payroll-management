#ifndef PROJECTS_ADMIN_H
#define PROJECTS_ADMIN_H

#include <vector>
#include "employee.h"

class Finance ;

class admin {
public:
    int length;
    std::vector<employee> list,admins;
    explicit admin();
    void addEmployees(Finance& F);
    void Search_By_ID();
    void Edit(Finance& F);
    void Sort_By_ID();
    void Sort_By_Name();
    void Delete();
    void List_By_ID();
    void List_By_Name();
    ~admin();
};

#endif //PROJECTS_ADMIN_H
