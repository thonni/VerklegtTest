#include "UI_Salesman.h"

DataManager data;

UI_Salesman::UI_Salesman()
{
    //ctor
}

UI_Salesman::~UI_Salesman()
{
    //dtor
}

void UI_Salesman::customerOrder ()
{
    cout << "Please enter the customer's order" << endl;
    char choice;
    do
    {
        cout << "Choose p to make a pizza" << endl;
        cout << "Choose m to pick a pizza off the menu" << endl;
        cout << "Choose e to add a soda or an extra to the order" << endl;
        cout << "Choose f when the order is finished" << endl;
        cin >> choice;

        if (choice == 'p')
        {
            data.readToppings();
        }
        if (choice == 'm')
        {
            data.readPizzaMenu();
        }
        if (choice == 'e')
        {
            data.readExtras();
        }

    } while (choice != 'f');
}
