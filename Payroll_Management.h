#ifndef PROJECTS_PAYROLL_MANAGEMENT_H
#define PROJECTS_PAYROLL_MANAGEMENT_H

#include "admin.h"
#include "Finance.h"
#include "Employees.h"

class Payroll_Management {
public:
    admin a;
    Finance f;
    Employees e;
    Payroll_Management();
    static void Welcome();
    bool Login_ForAdmin();
    bool Login_ForEmployee();
    void MenuForAdmin();
    void MenuForEmployee();
};

#endif //PROJECTS_PAYROLL_MANAGEMENT_H
