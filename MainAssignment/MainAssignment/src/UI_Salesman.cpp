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

    double totalPrice = 0.0;

    do
    {
        cout << "Choose p to make a pizza" << endl;
        cout << "Choose m to pick a pizza off the menu" << endl;
        cout << "Choose e to add a soda or an extra to the order" << endl;
        cout << "Choose f when the order is finished" << endl;
        cin >> choice;

        if (choice == 'p')
        {
            string name;
            Topping tempTopping;
            vector<Topping> availableToppings;
            vector<Pizza> newPizzas;
            char selection = '\0';
            unsigned int selectionAsInt = 0;
            Pizza newPizza(name, Pizza::Small);
            //Get a vector for all saved toppings using DataManager.
            availableToppings = data.readToppings();
            do
            {
                for(unsigned int i = 0; i < availableToppings.size(); i++)
                {
                    tempTopping = availableToppings[i];
                    cout << "ID: " << i << " - Name: " << tempTopping.getName() << " - Price: " << tempTopping.getPrice() << endl;
                }
                cout << "E - End" << endl << endl;

                //Ask the user to select a topping.
                cout << "Please select the id of the topping to add: ";
                cin >> selection;

                //Change the char selection to int.
                selectionAsInt = (int)(selection - '0');

                //Check if the selection is in the correct range.
                if((selectionAsInt >= 0 && selectionAsInt < availableToppings.size()))
                {
                    //Add the topping to the pizza.
                    newPizza.addTopping(availableToppings[selectionAsInt]);

                    Topping tempTopp;
                    availableToppings[selectionAsInt] = tempTopp;
                    totalPrice += tempTopp.getPrice();
                }
                //If it is not in range, it checks if you entered the letter e or E.
                else if(toupper(selection) != 'E')
                {
                    /// \TODO: Make error message here.
                }

            } while(toupper(selection) != 'E');

            totalPrice += newPizza.generatePrice(0.0);
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


    cout << "The total amount is " << totalPrice << " ISK." << endl;
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


