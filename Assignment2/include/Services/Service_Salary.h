#ifndef SERVICE_SALARY_H
#define SERVICE_SALARY_H

#include "Salary.h"
#include "Repository_Salary.h"

class Service_Salary
{
    public:
        Service_Salary();

        void verifyRecord(Salary Salary);

        Salary* readRecords();

    protected:

    private:
};

#endif // SERVICE_SALARY_H
