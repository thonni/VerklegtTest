#ifndef SALARY_H
#define SALARY_H

#include <string>

using namespace std;

class Salary
{
    public:
        Salary();
        Salary(string employee_name, string employee_ssn, int month, int year, double salary);
        string getName();
        string getSSN();
        int getMonth();
        int getYear();
        double getSalary();
        void setName(string Name);
        void setSSN(string SSN);
        void setMonth(int month);
        void setYear(int year);
        void setSalary(double salary);


    protected:

    private:
        string employee_name, employee_ssn;
        int month, year;
        double salary;
};

#endif // SALARY_H
