#include "MainUI.h"


void MainUI::startUI()
{
    char selection = '\0';

    do
    {

        //Clear the screen.
        cout << string(50, '\n');

        cout << "Welcome to Pizza hut" << endl;
        cout << "Please tell us who you are:" << endl;
        cout << "Choose M for manager" << endl;
        cout << "Choose S for salesman" << endl;
        cout << "Choose B for baker" << endl;
        cout << "Choose D for delivery" << endl;
        cout << "Choose Q to go quit" << endl;
        cout << ": ";

        //Asks the user who he/she is.
        cin >> selection;

        //Responds to who you are, and shows you the appropriate front page
        if (selection == 'm')
        {
            manager.startUI();
            cout << endl;
        }
        else if (selection == 's')
        {
            salesman.startUI();
            //salesman.orderSorting();

            cout << endl;
        }
        else if (selection == 'b')
        {
            baker.startUI();

            cout << endl;
        }
        else if (selection == 'd')
        {

        }

    //Loops if the selection is not q or Q (Quit).
    } while(toupper(selection) != 'Q');
}
