#include "Repository_Salary.h"

ofstream fout;
ifstream fin;

Repository_Salary::Repository_Salary()
{
    //ctor
}

void Repository_Salary::writeSalaryRecord(Salary salary) {
    fout.open ("SalaryRecords.txt", ios::app);

    string name = salary.getName();
    int nameLength = name.length();
    fout.write((char*)(&nameLength), sizeof(int));
    for(int i = 0; i < nameLength; i++) {
        fout.write((char*)(&name[i]), sizeof(char));
    }
    string ssn = salary.getSSN();
    for(int i = 0; i < 10; i++) {
        fout.write((char*)(&ssn[i]), sizeof(char));
    }
    int month = salary.getMonth();
    fout.write((char*)(&month), sizeof(int));
    int year = salary.getYear();
    fout.write((char*)(&year), sizeof(int));
    double money = salary.getSalary();
    fout.write((char*)(&money), sizeof(double));

    fout.close();
}

vector<Salary> Repository_Salary::readSalaryRecords() {

    fin.open("SalaryRecords.txt");

    vector<Salary> salaries;

    Salary tempSalary;
    int nameLength;
    string name, ssn;
    int month, year;
    double money;

    while(!fin.eof()) {
        fin.read((char*)(&nameLength), sizeof(int));
        for(int i = 0; i < nameLength; i++) {
            fin.read((char*)(&name[i]), sizeof(char));
        }
        for(int i = 0; i < 10; i++) {
            fin.read((char*)(&ssn[i]), sizeof(char));
        }
        fin.read((char*)(&month), sizeof(int));
        fin.read((char*)(&year), sizeof(int));
        fin.read((char*)(&money), sizeof(double));
        tempSalary.setName(name);
        tempSalary.setSSN(ssn);
        tempSalary.setMonth(month);
        tempSalary.setYear(year);
        tempSalary.setSalary(money);
        salaries.push_back(tempSalary);
    }

    fin.close();

    return salaries;
}
