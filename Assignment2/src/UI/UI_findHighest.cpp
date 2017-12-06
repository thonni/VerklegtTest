#include "UI_findHighest.h"

using namespace std;

UI_findHighest::UI_findHighest()
{
    //ctor
}

void UI_findHighest::startUI() {
    int year;
    int highest = 0;
    string highestEmp;
    bool found = false;

    cout << "Please enter the year that you wish to see the total salary for: ";
    cin >> year;
    cout << endl;

    try {
        Service_Salary service;
        int countRecords = service.countRecords();
        Salary *sals = service.readRecords();
        vector<string> SSNs;
        vector<string> names;
        vector<int> salaries;
        cout << "ONE" << endl;
        cout << countRecords << endl;
        for(int i = 0; i < countRecords; i++) {
            cout << "i " << i << endl;
            cout << "year " << sals[i].getYear() << endl;
            if(sals[i].getYear() == year) {
                for(unsigned int j = 0; j < SSNs.size(); j++) {
                    cout << "j " << j << endl;
                    if(SSNs.at(j) == sals->getSSN()) {
                        salaries.at(i) += sals->getSalary();
                        names.at(i) = sals->getName();
                        found = true;
                    }
                }
                if(!found) {
                    SSNs.push_back(sals->getSSN());
                    salaries.push_back(sals->getSalary());
                    names.push_back(sals->getName());
                }
                found = false;
            }
        }
        cout << "TWO" << endl;
        for(unsigned int i = 0; i < salaries.size(); i++) {
            if(salaries[i] > highest) {
                highestEmp = names[i];
            }
        }
        cout << "The name of the employee with the highest total salary in " << year << " is: " << highestEmp << endl;
        delete[] sals;
    } catch(int e) {
        if(e == 0) {
            cout << "No records found for the year: " << year << endl;
        } else {
            cout << "How did you even get here?";
        }
    }
}
