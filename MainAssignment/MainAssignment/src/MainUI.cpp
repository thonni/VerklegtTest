#include "MainUI.h"

using namespace std;

UI_Manager manager;

MainUI::MainUI()
{
    //ctor
}

MainUI::~MainUI()
{
    //dtor
}

void MainUI::startUI()
{
    char selection = '\0';

    do
    {

        cout << "Welcome to Pizza hut" << endl;
        cout << "Please tell us who you are:" << endl;
        cout << "Choose m for manager" << endl;
        cout << "Choose s for salesman" << endl;
        cout << "Choose b for baker" << endl;
        cout << "Choose d for delivery" << endl;

        //Asks the user who he/she is.
        cin >> selection;

        //Responds to who you are, and shows you the appropriate front page
        if (selection == 'm')
        {
            manager.addToMenu();
        }
        else if (selection == 's')
        {

        }
        else if (selection == 'b')
        {

        }
        else if (selection == 'd')
        {

        }

    //Loops if the selection is not q or Q (Quit).
    } while(toupper(selection) != 'Q');
}
