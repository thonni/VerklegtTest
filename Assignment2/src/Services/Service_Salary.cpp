#include "Service_Salary.h"

#include <string>

using namespace std;

Repository_Salary repo;

Service_Salary::Service_Salary()
{
    //ctor
}

void Service_Salary::verifyRecord(Salary salary) {
    string name = salary.getName();
    if(name.length() == 0) {
        throw 0;
    }
    for(unsigned int i = 0; i < name.length(); i++) {
        if(!(isalpha(name[i]) || (name[i] == ' '))) {
            throw 1;
        }
    }
    string ssn = salary.getSSN();
    if(ssn.length() == 10) {
        for(int i = 0; i < 10; i++) {
            if(!isdigit(ssn[i])) {
                throw 2;
            }
        }
    } else {
        throw 3;
    }
    int month = salary.getMonth();
    if(month < 1 || month > 12) {
        throw 4;
    }
    int year = salary.getYear();
    if(year != 2017) {
        throw 5;
    }
    int money = salary.getSalary();
    if(money < 0) {
        throw 6;
    }
    vector<Salary> sals = repo.readSalaryRecords();
    repo.clearSalaryRecord();
    for(unsigned int i = 0; i < sals.size(); i++) {
        if(sals.at(i).getMonth() == salary.getMonth() && sals.at(i).getYear() == salary.getYear() && sals.at(i).getSSN() == salary.getSSN()) {
            repo.writeSalaryRecord(salary);
        } else {
            repo.writeSalaryRecord(sals.at(i));
        }
    }


}

Salary* Service_Salary::readRecords() {
    vector<Salary> sals = repo.readSalaryRecords();
    Salary *salaries = new Salary[sals.size()];
    for(unsigned int i = 0; i < sals.size(); i++) {
        salaries[i] = sals.at(i);
    }
    return salaries;
}

int Service_Salary::countRecords() {
    vector<Salary> sals = repo.readSalaryRecords();
    return sals.size();
}







