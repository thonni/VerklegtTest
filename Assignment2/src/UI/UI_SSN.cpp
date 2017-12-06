#include "UI_SSN.h"

UI_SSN::UI_SSN()
{
    //ctor
}

void UI_SSN::startUI() {
    string ssn;
    bool found = false;

    cout << "Please enter the employees SSN: ";
    cin >> ssn;
    cout << endl;

    try {
        Service_Salary service;
        int countRecords = service.countRecords();
        Salary *sals = service.readRecords();
        for(int i = 0; i < countRecords; i++) {
            if(sals[i].getSSN() == ssn) {
                cout << "In " << sals[i].getMonth() << "-" << sals[i].getYear() << ", " << sals[i].getName() << " had a salary of: " << sals[i].getSalary() << endl;
                found = true;
            }
        }
        if(!found) {
            cout << "No records found for employee with SSN: " << ssn << endl;
        }
        delete[] sals;
    } catch(int e) {
        if(e == 0) {
            cout << "Not finished.";
        } else {
            cout << "How did you even get here?";
        }
    }
}
