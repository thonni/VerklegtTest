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

void UI_Salesman::customerOrder()
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
        else if (choice == 'm')
        {
            data.readPizzaMenu();
        }
        else if (choice == 'e')
        {
            data.readExtras();
        }
        else if (choice != 'f')
        {
            cout << "Invalid input!" << endl;
        }
    } while (choice != 'f');

    cout << "The total amount is " << "bleeehhhh" << " ISK." << endl;
    cout << endl;
}

void UI_Salesman::orderSorting()
{
    char delivery;
    cout << "How do you want to get your order?" << endl;
    cout << "Choose p for pick up." << endl;
    cout << "Choose d for home delivery." << endl;

    if (delivery == 'p')
    {
        cout << "Choose were you will pick up." << endl;
    }
    else if (delivery == 'd')
    {
        cout << "Where should the pizza be delivered?" << endl;
    }
}


