#include "Salary.h"

Salary::Salary()
{
    //ctor
}

Salary::Salary(string employee_name, string employee_ssn, int month, int year, double salary) {
    this->employee_name = employee_name;
    this->employee_ssn = employee_ssn;
    this->month = month;
    this->year = year;
    this->salary = salary;
}

string Salary::getName() {
    return this->employee_name;
}

string Salary::getSSN() {
    return this->employee_ssn;
}

int Salary::getMonth() {
    return this->month;
}

int Salary::getYear() {
    return this->year;
}

double Salary::getSalary() {
    return this->salary;
}

void Salary::setName(string Name) {
    this->employee_name = Name;
}

void Salary::setSSN(string SSN) {
    this->employee_ssn = SSN;
}

void Salary::setMonth(int month) {
    this->month = month;
}

void Salary::setYear(int year) {
    this->year = year;
}

void Salary::setSalary(double salary) {
    this->salary = salary;
}

