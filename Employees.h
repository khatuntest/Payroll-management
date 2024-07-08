#ifndef PROJECTS_EMPLOYEES_H
#define PROJECTS_EMPLOYEES_H

#include "admin.h"
#include "Finance.h"

class Employees {
private:
    admin& d;
    Finance& f;

public:
    Employees(admin& m, Finance& F);
    void View_information();
    void Change_Password();
    void View_paySlip();
};

#endif //PROJECTS_EMPLOYEES_H
