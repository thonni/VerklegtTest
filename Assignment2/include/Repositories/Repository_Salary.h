#ifndef REPOSITORY_SALARY_H
#define REPOSITORY_SALARY_H

#include "Salary.h"
#include <vector>
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <cstdlib>

using namespace std;

class Repository_Salary
{
    public:
        Repository_Salary();
        vector<Salary> readSalaryRecords();
        void writeSalaryRecord(Salary Salary);

    protected:

    private:
};

#endif // REPOSITORY_SALARY_H
