#include "MainUI.h"


void MainUI::startUI()
{
    char selection = '\0';

    do
    {

        //Clear the screen.
        cout << string(50, '\n');

        cout << "Welcome to Prime Pizzeria" << endl;
        cout << "Please tell us who you are:" << endl;
        cout << "Choose M for Manager" << endl;
        cout << "Choose S for Salesman" << endl;
        cout << "Choose B for Baker" << endl;
        cout << "Choose D for Delivery" << endl;
        cout << "Choose Q to Quit" << endl;
        cout << ": ";

        //Asks the user who he/she is.
        cin >> selection;

        //Responds to who you are, and shows you the appropriate front page
        if (toupper(selection) == 'M')
        {
            manager.startUI();
            cout << endl;
        }
        else if (toupper(selection) == 'S')
        {
            salesman.startUI();

            cout << endl;
        }
        else if (toupper(selection) == 'B')
        {
            baker.startUI();

            cout << endl;
        }
        else if (toupper(selection) == 'D')
        {
            delivery.deliveryMenu();
            cout << endl;
        }

    //Loops if the selection is not q or Q (Quit).
    } while(toupper(selection) != 'Q');
}
