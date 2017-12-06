#include "UI_AddRecord.h"

#include <iostream>
#include <string>

UI_AddRecord::UI_AddRecord()
{
    //ctor
}

void UI_AddRecord::startUI() {
    string name, ssn;
    int month, year;
    double salary;

    cout << "Please enter the employees name: ";
    cin.ignore();
    getline (cin, name);
    cout << "Please enter the employees SSN: ";
    cin >> ssn;
    cout << "Please enter the month for the record: ";
    cin >> month;
    cout << "Please enter the year for the record: ";
    cin >> year;
    cout << "Please enter the salary for the record: ";
    cin >> salary;

    Salary newSalary(name, ssn, month, year, salary);
    try {
        Service_Salary service;
        service.verifyRecord(newSalary);
    } catch(int e) {
        if(e == 0) {
            cout << "Employees name cannot be of length zero";
        } else if(e == 1) {
            cout << "Employees name can only contain standard alphabet letters";
        } else if(e == 2) {
            cout << "Employees SSN can only contain decimal numbers (0, 1, 2, 3, 4, 5, 6, 7, 8, 9)";
        } else if(e == 3) {
            cout << "Employees SSN can only be of length 10";
        } else if(e == 4) {
            cout << "Month can only be a number between 1 and 12, including 1 and 12";
        } else if(e == 5) {
            cout << "Year can only be 2017";
        } else if(e == 6) {
            cout << "Salary can only be a positive real number";
        } else {
            cout << "How did you even get here?";
        }
    }
}











