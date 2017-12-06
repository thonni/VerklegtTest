#include "UI_Main.h"

UI_AddRecord addRecord;
UI_SSN ssnFind;
UI_totalYear totalYear;
UI_totalSSN totalSSN;
UI_findHighest findHigh;
Service_Salary service;

UI_Main::UI_Main()
{
    //ctor
}

void UI_Main::startUI() {
    char selection = '\0';

    do
    {

        cout << "Please press 1 to add a salary record" << endl;
        cout << "Please press 2 to get all salary records for a given SSN" << endl;
        cout << "Please press 3 to get total salary for a given year" << endl;
        cout << "Please press 4 to get total salary for a given SSN" << endl;
        cout << "Please press 5 to get the name of the employee with the highest total salary for a given year" << endl;
        cout << "Please press q when you wish to quit" << endl;
        cout << ": ";

        //Asks the user who he/she is.
        cin >> selection;

        //Responds to who you are, and shows you the appropriate front page
        if (selection == '1')
        {
            addRecord.startUI();
            cout << endl;
        }
        else if (selection == '2')
        {
            ssnFind.startUI();
            cout << endl;
        }
        else if (selection == '3')
        {
            totalYear.startUI();
            cout << endl;
        }
        else if (selection == '4')
        {
            totalSSN.startUI();
            cout << endl;
        }
        else if (selection == '5')
        {
            findHigh.startUI();
            cout << endl;
        }
        else if (selection == '4')
        {

        }

    //Loops if the selection is not q or Q (Quit).
    } while(toupper(selection) != 'Q');
}
