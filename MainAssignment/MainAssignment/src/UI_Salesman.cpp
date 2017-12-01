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

void UI_Salesman::startUI()
{
    char choice;

    do
    {
        //Clear the screen.
        cout << string(50, '\n');
        cout << "Welcome salesperson" << endl << endl;

        cout << "Choose O to take order" << endl;
        cout << "Choose V to view orders" << endl;
        cout << "Choose B to go back" << endl;
        cin >> choice;

        if (toupper(choice) == 'O')
        {
            this->takeOrder();
        }
        else if (toupper(choice) == 'V')
        {

        }
        else if (toupper(choice) != 'F')
        {
            cout << "Invalid input!" << endl;
        }
    } while (toupper(choice) != 'B');
}



void UI_Salesman::takeOrder()
{
    char choice;

    do
    {

        //Clear the screen.
        cout << string(50, '\n');

        cout << "Order creation" << endl << endl;

        cout << "Choose S to Select a pizza from the menu" << endl;
        cout << "Choose M to Make a Pizza from scratch" << endl;
        cout << "Choose E to add Extras" << endl;
        cout << "Choose F to Finish up the order" << endl;
        cout << "Choose C to Cancel order" << endl;
        cout << ": ";
        cin >> choice;

        if(toupper(choice) == 'S')
        {
            this->choosePizzaFromMenu();
        }
        else if(toupper(choice) == 'M')
        {
            this->makePizza();
        }
        else if(toupper(choice) == 'E')
        {

        }
        else if(toupper(choice) == 'F')
        {

        }

    } while(toupper(choice) != 'C');
}


Pizza UI_Salesman::choosePizzaFromMenu()
{
    /// \TODO: Print out all pizzas and make the user select from them.
}


Pizza UI_Salesman::makePizza()
{
    Topping tempTopping;
    vector<Topping> availableToppings;
    char selection = '0';
    unsigned int selectionAsInt = 0;

    //Clear the screen.
    cout << string(50, '\n');

    //Get a vector for all saved toppings using DataManager.
    availableToppings = data.readToppings();

    //Create an instance of pizza using the name
    Pizza newPizza("noName", Pizza::Small);

    do
    {
        //Clear the screen.
        cout << string(50, '\n');

        //Loop trough all menu toppings and print them on screen.
        for(unsigned int i = 0; i < availableToppings.size(); i++)
        {
            tempTopping = availableToppings[i];
            cout << i << " - Name: " << tempTopping.getName() << " - Price: " << tempTopping.getPrice() << endl;
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
        }
        //If it is not in range, it checks if you entered the letter e or E.
        else if(toupper(selection) != 'E')
        {
            /// \TODO: Make error message here.
        }

    } while(toupper(selection) != 'E');

    do
    {
        //Clear the screen.
        cout << string(50, '\n');

        cout << "Please select the size of the pizza" << endl;
        cout << "Choose S for Small" << endl;
        cout << "Choose M for Medium" << endl;
        cout << "Choose L for Large" << endl;
        cout << ": ";
        cin >> selection;

        if(toupper(selection) == 'S')
        {
            newPizza.setSize(Pizza::Small);
        }
        else if(toupper(selection) == 'M')
        {
            newPizza.setSize(Pizza::Medium);
        }
        else if(toupper(selection) == 'L')
        {
            newPizza.setSize(Pizza::Large);
        }
        else
        {
            selection = '0';
        }

    } while(selection == '0');

    //Make the pizza calculate the price of it self.
    newPizza.generatePrice();

    //Clear the screen.
    cout << string(50, '\n');

    //Tell the user all the information about the pizza he/she created
    cout << "Toppings:" << endl;
    for(unsigned int i = 0; i < newPizza.getToppings().size(); i++)
    {
        cout << " *" << newPizza.getToppings().at(i).getName() << endl;
    }
    cout << endl << "Pizza price: " << newPizza.getPrice() << " ISK" << endl << endl;

    //Ask the user if everything is OK.
    cout << "Is this OK? (Y/N): ";
    cin >> selection;


    return newPizza;
}

/*void UI_Salesman::orderSorting()
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

*/
