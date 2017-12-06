#include "UI_totalYear.h"

UI_totalYear::UI_totalYear()
{
    //ctor
}

void UI_totalYear::startUI() {
    int year;
    int salary = 0;
    bool found = false;

    cout << "Please enter the year that you wish to see the total salary for: ";
    cin >> year;
    cout << endl;

    try {
        Service_Salary service;
        int countRecords = service.countRecords();
        Salary *sals = service.readRecords();
        for(int i = 0; i < countRecords; i++) {
            if(sals[i].getYear() == year) {
                salary += sals[i].getSalary();
                found = true;
            }
        }
        if(found) {
            cout << "The total salary for " << year << " is: " << salary << endl;
        } else {
            throw 0;
        }
        delete[] sals;
    } catch(int e) {
        if(e == 0) {
            cout << "No records found for the year: " << year << endl;
        } else {
            cout << "How did you even get here?";
        }
    }
}
