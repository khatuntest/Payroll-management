#ifndef PROJECTS_FINANCE_H
#define PROJECTS_FINANCE_H

#include <vector>
#include <utility>
#include "admin.h"

class Finance : public admin {
public:
    //[id , salary , bon, leaves , tax , net salary]
    std::vector<std::vector<int>> Fin;
    Finance();
    void addEmployee(employee& e);
    void calc_Bonus();
    void calc_leaves();
    void calc_taxes();
    void Sort_By_id();
    void display();
};

#endif //PROJECTS_FINANCE_H
