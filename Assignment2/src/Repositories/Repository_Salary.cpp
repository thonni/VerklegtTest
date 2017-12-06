#include "Repository_Salary.h"

ofstream fout;
ifstream fin;

using namespace std;

Repository_Salary::Repository_Salary()
{
    //ctor
}

void Repository_Salary::writeSalaryRecord(Salary salary) {
    fout.open ("SalaryRecords.txt", ios::app);

    if(fout.is_open()) {
        string name = salary.getName();
        //int nameLength = name.length();
        //fout.write((char*)(&nameLength), sizeof(int));
        //for(int i = 0; i < nameLength; i++) {
        //    fout.write((char*)(&name[i]), sizeof(char));
        //}
        string ssn = salary.getSSN();
        //for(int i = 0; i < 10; i++) {
        //    fout.write((char*)(&ssn[i]), sizeof(char));
        //}
        int month = salary.getMonth();
        //fout.write((char*)(&month), sizeof(int));
        int year = salary.getYear();
        //fout.write((char*)(&year), sizeof(int));
        int money = salary.getSalary();
        //fout.write((char*)(&money), sizeof(double));
        stringstream ss;
        string everything;
        ss << month;
        ss << "▄";
        ss << year;
        ss << "▄";
        ss << money;
        ss << "\n";
        everything = name + "▄" + ssn + "▄" + ss.str();
        int length = everything.length();
        for(int i = 0; i < length; i++) {
            fout.write((char*)(&everything[i]), sizeof(char));
        }
    }

    fout.close();
}

void Repository_Salary::clearSalaryRecord() {
    fout.open ("SalaryRecords.txt");
    fout.close();
}

vector<Salary> Repository_Salary::readSalaryRecords() {

    fin.open("SalaryRecords.txt");
    vector<Salary> salaries;

    if(fin.is_open()) {

        Salary tempSalary;
        string name, ssn, everything;
        int month, year, money;

        do {
            name = everything.substr(0, everything.find("▄"));
            everything.erase(0, everything.find("▄") + 3);
            ssn = everything.substr(0, everything.find("▄"));
            everything.erase(0, everything.find("▄") + 3);
            month = atoi(&everything.substr(0, everything.find("▄"))[0]);
            everything.erase(0, everything.find("▄") + 3);
            year = atoi(&everything.substr(0, everything.find("▄"))[0]);
            everything.erase(0, everything.find("▄") + 3);
            money = atoi(&everything[0]);

            tempSalary.setName(name);
            tempSalary.setSSN(ssn);
            tempSalary.setMonth(month);
            tempSalary.setYear(year);
            tempSalary.setSalary(money);
            salaries.push_back(tempSalary);
        } while(getline(fin, everything));
    }

    fin.close();

    return salaries;
}
