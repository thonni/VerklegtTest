#include "UI_totalSSN.h"

UI_totalSSN::UI_totalSSN()
{
    //ctor
}

void UI_totalSSN::startUI() {
    string ssn;
    int salary = 0;
    bool found = false;

    cout << "Please enter the SSN that you wish to see the total salary for: ";
    cin >> ssn;
    cout << endl;

    try {
        Service_Salary service;
        int countRecords = service.countRecords();
        Salary *sals = service.readRecords();
        for(int i = 0; i < countRecords; i++) {
            if(sals[i].getSSN() == ssn) {
                salary += sals[i].getSalary();
                found = true;
            }
        }
        if(found) {
            cout << "The total salary for " << ssn << " is: " << salary << endl;
        } else {
            throw 0;
        }
        delete[] sals;
    } catch(int e) {
        if(e == 0) {
            cout << "No records found for the ssn: " << ssn << endl;
        } else {
            cout << "How did you even get here?";
        }
    }
}
