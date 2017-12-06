#ifndef SALARY_H
#define SALARY_H

#include <string>

using namespace std;

class Salary
{
    public:
        Salary();
        Salary(string employee_name, string employee_ssn, int month, int year, int salary);
        string getName();
        string getSSN();
        int getMonth();
        int getYear();
        int getSalary();
        void setName(string Name);
        void setSSN(string SSN);
        void setMonth(int month);
        void setYear(int year);
        void setSalary(int salary);


    protected:

    private:
        string employee_name, employee_ssn;
        int month, year, salary;
};

#endif // SALARY_H
